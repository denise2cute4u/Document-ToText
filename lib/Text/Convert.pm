package Text::Convert;

use strict;
use warnings;

use Text::Convert::Plugin::WPS;

our $VERSION = .1;

sub import
{
	no strict 'refs';

	*{ caller . '::txt' } = \*{ "$_[0]::txt" };
}

sub txt
{
	Text::Convert::Plugin::WPS::parse( $_[0] );
}

1;

__END__

=head1 NAME

Text::Convert - Convert documents into plain text