package Document::ToText;

use strict;
use warnings;

our $VERSION = .1;

require XSLoader;

XSLoader::load( 'Document::ToText' );

sub import
{
	no strict 'refs';

	*{ caller . '::txt' } = \*{ "$_[0]::txt" };
}

sub txt
{
	my $filename = $_[0];

	my $mime = mime( $filename );

	require "Document/ToText/$mime.pm";

	my $text = &{ \&{ "Document::ToText::${mime}::parse" } }( $filename );
	   $text =~ s/^\s+//;
	   $text =~ s/\s+$//;
	   $text;
}

1;

__END__

=head1 NAME

Document::ToText - Convert documents into plain text