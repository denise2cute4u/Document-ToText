package Text::Convert;

use strict;
use warnings;

use Exporter;
use Text::Convert::Plugin::WPS;

our @EXPORT  = 'txt';
our @ISA     = 'Exporter';
our $VERSION = .1;

sub txt
{
	Text::Convert::Plugin::WPS::parse;
}

1;

__END__

=head1 NAME

Text::Convert - Convert documents into plain text