# Copyright © 2014-2015 Guillem Jover <guillem@debian.org>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

package Dpkg::Dist::Files;

use strict;
use warnings;

our $VERSION = '0.01';

use Dpkg::Gettext;
use Dpkg::ErrorHandling;

use parent qw(Dpkg::Interface::Storable);

sub new {
    my ($this, %opts) = @_;
    my $class = ref($this) || $this;

    my $self = {
        options => [],
        files => {},
    };
    foreach my $opt (keys %opts) {
        $self->{$opt} = $opts{$opt};
    }
    bless $self, $class;

    return $self;
}

sub reset {
    my $self = shift;

    $self->{files} = {};
}

sub parse_filename {
    my ($self, $fn) = @_;

    my $file;

    if ($fn =~ m/^(([-+:.0-9a-z]+)_([^_]+)_([-\w]+)\.([a-z0-9.]+))$/) {
        $file->{filename} = $1;
        $file->{package} = $2;
        $file->{version} = $3;
        $file->{arch} = $4;
        $file->{package_type} = $5;
    } elsif ($fn =~ m/^([-+:.,_0-9a-zA-Z~]+)$/) {
        $file->{filename} = $1;
    } else {
        $file = undef;
    }

    return $file;
}

sub parse {
    my ($self, $fh, $desc) = @_;
    my $count = 0;

    local $_;
    binmode $fh;

    while (<$fh>) {
        chomp;

        my $file;

        if (m/^(\S+) (\S+) (\S+)$/) {
            $file = $self->parse_filename($1);
            error(g_('badly formed package name in files list file, line %d'), $.)
                unless defined $file;
            $file->{section} = $2;
            $file->{priority} = $3;
        } else {
            error(g_('badly formed line in files list file, line %d'), $.);
        }

        if (defined $self->{files}->{$file->{filename}}) {
            warning(g_('duplicate files list entry for file %s (line %d)'),
                    $file->{filename}, $.);
        } else {
            $count++;
            $self->{files}->{$file->{filename}} = $file;
        }
    }

    return $count;
}

sub get_files {
    my $self = shift;

    return map { $self->{files}->{$_} } sort keys %{$self->{files}};
}

sub get_file {
    my ($self, $filename) = @_;

    return $self->{files}->{$filename};
}

sub add_file {
    my ($self, $filename, $section, $priority) = @_;

    my $file = $self->parse_filename($filename);
    error(g_('invalid filename %s'), $filename) unless defined $file;
    $file->{section} = $section;
    $file->{priority} = $priority;

    $self->{files}->{$filename} = $file;
}

sub del_file {
    my ($self, $filename) = @_;

    delete $self->{files}->{$filename};
}

sub filter {
    my ($self, %opts) = @_;
    my $remove = $opts{remove} // sub { 0 };
    my $keep = $opts{keep} // sub { 1 };

    foreach my $filename (keys %{$self->{files}}) {
        my $file = $self->{files}->{$filename};

        if (not &$keep($file) or &$remove($file)) {
            delete $self->{files}->{$filename};
        }
    }
}

sub output {
    my ($self, $fh) = @_;
    my $str = '';

    binmode $fh if defined $fh;

    foreach my $filename (sort keys %{$self->{files}}) {
        my $file = $self->{files}->{$filename};
        my $entry = "$filename $file->{section} $file->{priority}\n";

        print { $fh } $entry if defined $fh;
        $str .= $entry;
    }

    return $str;
}

1;
