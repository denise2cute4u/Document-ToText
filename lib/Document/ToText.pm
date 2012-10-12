package Document::ToText;

use strict;
use warnings;

use File::LibMagic;

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
	
	my $mime = File::LibMagic->new->checktype_filename( $filename );
	   $mime =~ s/;.*//;
	   $mime = 'application/msworks' if $mime eq 'Composite Document File V2 Document, No summary info';

	my $class = $mime;
	   $class =~ s/\//_/g;

	require "Document/ToText/$class.pm";

	my $text = &{ \&{ "Document::ToText::${class}::parse" } }( $filename );
	   $text =~ s/^\s+//;
	   $text =~ s/\s+$//;
	   $text;
}

1;

__END__

=head1 NAME

Document::ToText - Convert documents into plain text