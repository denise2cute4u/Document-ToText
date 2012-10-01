package Text::Convert;

use strict;
use warnings;

use File::LibMagic;

our $VERSION = .1;

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

	require "Text/Convert/Plugin/$class.pm";
	
	#&{ "Text::Convert::Plugin::$class::parse" }( $filename );
	Text::Convert::Plugin::application_msworks::parse( $filename );
}

1;

__END__

=head1 NAME

Text::Convert - Convert documents into plain text