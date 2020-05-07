#!/usr/bin/perl -w
# This file was preprocessed, do not edit!


package Debconf::Element::Dialog::Multiselect;
use strict;
use base qw(Debconf::Element::Multiselect);
use Debconf::Encoding qw(width);


sub show {
	my $this=shift;
	
	my ($text, $lines, $columns)=
		$this->frontend->makeprompt($this->question, -2);

	my $screen_lines=$this->frontend->screenheight - $this->frontend->spacer;
	my @params=();
	my @choices=$this->question->choices_split;
	my %value = map { $_ => 1 } $this->translate_default;

	my $menu_height=$#choices + 1;
	if ($lines + $#choices + 2 >= $screen_lines) {
		$menu_height = $screen_lines - $lines - 4;
		if ($menu_height < 3 && $#choices + 1 > 2) {
			$this->frontend->showtext($this->question, $this->question->extended_description);
			($text, $lines, $columns)=$this->frontend->sizetext($this->question->description);
			$menu_height=$#choices + 1;
			if ($lines + $#choices + 2 >= $screen_lines) {
				$menu_height = $screen_lines - $lines - 4;
			}
		}
	}
	
	$lines=$lines + $menu_height + $this->frontend->spacer;
	my $selectspacer = $this->frontend->selectspacer;
	my $c=1;
	foreach (@choices) {
		push @params, ($_, "");
		push @params, ($value{$_} ? 'on' : 'off');

		if ($columns < width($_) + $selectspacer) {
			$columns = width($_) + $selectspacer;
		}
	}
	
	if ($this->frontend->dashsep) {
		unshift @params, $this->frontend->dashsep;
	}
	
	@params=('--separate-output', '--checklist', 
	         $text, $lines, $columns, $menu_height, @params);

	my $value=$this->frontend->showdialog($this->question, @params);

	if (defined $value) {
		$this->value(join(", ", $this->order_values(
					map { $this->translate_to_C($_) }
					split(/\n/, $value))));
	}
	else {
		my $default='';
		$default=$this->question->value
			if defined $this->question->value;
		$this->value($default);
	}
}

1
