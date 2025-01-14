package vmsish;

=head1 NAME

vmsish - Perl pragma to control VMS-specific language features

=head1 SYNOPSIS

    use vmsish;

    use vmsish 'status';	# or '$?'
    use vmsish 'exit';
    use vmsish 'time';

    use vmsish;
    no vmsish 'time';

=head1 DESCRIPTION

If no import list is supplied, all possible VMS-specific features are
assumed.  Currently, there are three VMS-specific features available:
'status' (a.k.a '$?'), 'exit', and 'time'.

=over 6

=item C<vmsish status>

This makes C<$?> and C<system> return the native VMS exit status
instead of emulating the POSIX exit status.

=item C<vmsish exit>

This makes C<exit 1> produce a successful exit (with status SS$_NORMAL),
instead of emulating UNIX exit(), which considers C<exit 1> to indicate
an error.  As with the CRTL's exit() function, C<exit 0> is also mapped
to an exit status of SS$_NORMAL, and any other argument to exit() is
used directly as Perl's exit status.

=item C<vmsish time>

This makes all times relative to the local time zone, instead of the
default of Universal Time (a.k.a Greenwich Mean Time, or GMT).

=back

See L<perlmod/Pragmatic Modules>.

=cut

if ($^O ne 'VMS') {
    require Carp;
    Carp::croak("This isn't VMS");
}

sub bits {
    my $bits = 0;
    my $sememe;
    foreach $sememe (@_) {
	$bits |= 0x01000000, next if $sememe eq 'status' || $sememe eq '$?';
	$bits |= 0x02000000, next if $sememe eq 'exit';
	$bits |= 0x04000000, next if $sememe eq 'time';
    }
    $bits;
}

sub import {
    shift;
    $^H |= bits(@_ ? @_ : qw(status exit time));
}

sub unimport {
    shift;
    $^H &= ~ bits(@_ ? @_ : qw(status exit time));
}

1;
