	,"DEBPKG:debian/cpan_definstalldirs - Provide a sensible INSTALLDIRS default for modules installed from CPAN."
	,"DEBPKG:debian/db_file_ver - http://bugs.debian.org/340047 Remove overly restrictive DB_File version check."
	,"DEBPKG:debian/doc_info - Replace generic man(1) instructions with Debian-specific information."
	,"DEBPKG:debian/enc2xs_inc - http://bugs.debian.org/290336 Tweak enc2xs to follow symlinks and ignore missing @INC directories."
	,"DEBPKG:debian/errno_ver - http://bugs.debian.org/343351 Remove Errno version check due to upgrade problems with long-running processes."
	,"DEBPKG:debian/libperl_embed_doc - http://bugs.debian.org/186778 Note that libperl-dev package is required for embedded linking"
	,"DEBPKG:fixes/respect_umask - Respect umask during installation"
	,"DEBPKG:debian/writable_site_dirs - Set umask approproately for site install directories"
	,"DEBPKG:debian/extutils_set_libperl_path - EU:MM: set location of libperl.a under /usr/lib"
	,"DEBPKG:debian/no_packlist_perllocal - Don't install .packlist or perllocal.pod for perl or vendor"
	,"DEBPKG:debian/fakeroot - Postpone LD_LIBRARY_PATH evaluation to the binary targets."
	,"DEBPKG:debian/instmodsh_doc - Debian policy doesn't install .packlist files for core or vendor."
	,"DEBPKG:debian/ld_run_path - Remove standard libs from LD_RUN_PATH as per Debian policy."
	,"DEBPKG:debian/libnet_config_path - Set location of libnet.cfg to /etc/perl/Net as /usr may not be writable."
	,"DEBPKG:debian/mod_paths - Tweak @INC ordering for Debian"
	,"DEBPKG:debian/prune_libs - http://bugs.debian.org/128355 Prune the list of libraries wanted to what we actually need."
	,"DEBPKG:fixes/net_smtp_docs - [rt.cpan.org #36038] http://bugs.debian.org/100195 Document the Net::SMTP 'Port' option"
	,"DEBPKG:debian/perlivp - http://bugs.debian.org/510895 Make perlivp skip include directories in /usr/local"
	,"DEBPKG:debian/deprecate-with-apt - http://bugs.debian.org/747628 Point users to Debian packages of deprecated core modules"
	,"DEBPKG:debian/squelch-locale-warnings - http://bugs.debian.org/508764 Squelch locale warnings in Debian package maintainer scripts"
	,"DEBPKG:debian/skip-upstream-git-tests - Skip tests specific to the upstream Git repository"
	,"DEBPKG:debian/patchlevel - http://bugs.debian.org/567489 List packaged patches for 5.22.1-9 in patchlevel.h"
	,"DEBPKG:debian/skip-kfreebsd-crash - http://bugs.debian.org/628493 [perl #96272] Skip a crashing test case in t/op/threads.t on GNU/kFreeBSD"
	,"DEBPKG:fixes/document_makemaker_ccflags - http://bugs.debian.org/628522 [rt.cpan.org #68613] Document that CCFLAGS should include $Config{ccflags}"
	,"DEBPKG:debian/find_html2text - http://bugs.debian.org/640479 Configure CPAN::Distribution with correct name of html2text"
	,"DEBPKG:debian/perl5db-x-terminal-emulator.patch - http://bugs.debian.org/668490 Invoke x-terminal-emulator rather than xterm in perl5db.pl"
	,"DEBPKG:debian/cpan-missing-site-dirs - http://bugs.debian.org/688842 Fix CPAN::FirstTime defaults with nonexisting site dirs if a parent is writable"
	,"DEBPKG:fixes/memoize_storable_nstore - [rt.cpan.org #77790] http://bugs.debian.org/587650 Memoize::Storable: respect 'nstore' option not respected"
	,"DEBPKG:debian/regen-skip - Skip a regeneration check in unrelated git repositories"
	,"DEBPKG:debian/makemaker-pasthru - http://bugs.debian.org/758471 Pass LD settings through to subdirectories"
	,"DEBPKG:fixes/pod_man_reproducible_date - http://bugs.debian.org/759405 Support POD_MAN_DATE in Pod::Man for the left-hand footer"
	,"DEBPKG:debian/locale-robustness - http://bugs.debian.org/782068 [perl #124310] Make t/run/locale.t survive missing locales masked by LC_ALL"
	,"DEBPKG:fixes/podman-utc - http://bugs.debian.org/780259 Make the embedded date from Pod::Man reproducible"
	,"DEBPKG:fixes/podman-utc-docs - http://bugs.debian.org/780259 Documentation and test suite updates for UTC fix"
	,"DEBPKG:fixes/podman-empty-date - http://bugs.debian.org/780259 Support an empty POD_MAN_DATE environment variable"
	,"DEBPKG:fixes/podman-pipe - http://bugs.debian.org/777405 Better errors for man pages from standard input"
	,"DEBPKG:debian/pod2man-customized - Update porting/customized.dat for pod2man modifications"
	,"DEBPKG:debian/makemaker-manext - http://bugs.debian.org/247370 Make EU::MakeMaker honour MANnEXT settings in generated manpage headers"
	,"DEBPKG:debian/makemaker_customized - Update t/porting/customized.dat for files patched in Debian"
	,"DEBPKG:debian/do-not-record-build-date - [6baa8db] http://bugs.debian.org/774422 [perl #125830] Allow overriding the compile time in \"perl -V\" output"
	,"DEBPKG:fixes/podman-source-date-epoch - http://bugs.debian.org/801621 Make Pod::Man honor the SOURCE_DATE_EPOCH environment variable"
	,"DEBPKG:fixes/podman-source-date-epoch-cleanups - http://bugs.debian.org/801621 Coding style and documentation for SOURCE_EPOCH_DATE"
	,"DEBPKG:fixes/podman-source-date-epoch-testfix - http://bugs.debian.org/807086 Guard for building with SOURCE_DATE_EPOCH or POD_MAN_DATE set"
	,"DEBPKG:debian/devel-ppport-reproducibility - http://bugs.debian.org/801523 Sort the list of XS code files when generating RealPPPort.xs"
	,"DEBPKG:fixes/encode-unicode-bom - http://bugs.debian.org/798727 [rt.cpan.org #107043] Address https://rt.cpan.org/Public/Bug/Display.html?id=107043"
	,"DEBPKG:debian/encode-unicode-bom-doc - http://bugs.debian.org/798727 Document Debian backport of Encode::Unicode fix"
	,"DEBPKG:debian/kfreebsd-softupdates - http://bugs.debian.org/796798 Work around Debian Bug#796798"
	,"DEBPKG:fixes/autodie-scope - http://bugs.debian.org/798096 Fix a scoping issue with \"no autodie\" and the \"system\" sub"
	,"DEBPKG:debian/debugperl-compat-fix - [perl #127212] http://bugs.debian.org/810326 Disable PERL_TRACK_MEMPOOL for debugging builds"
	,"DEBPKG:fixes/CVE-2015-8607_file_spec_taint_fix - http://bugs.debian.org/810719 [perl #126862] ensure File::Spec::canonpath() preserves taint"
	,"DEBPKG:fixes/mkstemp-umask - http://bugs.debian.org/810924 [perl #127322] [e57270b] Fix umask for mkstemp(3) calls"
	,"DEBPKG:fixes/crosscompile-no-targethost - [perl #127234] Fix the Configure escape with usecrosscompile but no targethost"
	,"DEBPKG:fixes/podlators-no-encode - [rt.cpan.org #111156] Degrade gracefully if utf8 is requested but Encode is not available"
	,"DEBPKG:debian/cross-time-hires - [rt.cpan.org #111391] Add an environment variable to skip running configuration probes"
	,"DEBPKG:fixes/encode-unicode-pod - Unicode.pm: Fix POD error"
	,"DEBPKG:fixes/memoize-pod - [rt.cpan.org #89441] Fix POD errors in Memoize"
	,"DEBPKG:fixes/ok-pod - Added encoding for pod."
	,"DEBPKG:fixes/CVE-2016-2381_duplicate_env - remove duplicate environment variables from environ"
