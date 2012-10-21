package Document::ToText::application_vnd_oasis_opendocument_text;

use OpenOffice::OODoc;

sub parse
{
	my $doc = odfText( file => $_[0] );
    my $xml;

	open my $out, '>', \$xml;

	$doc->getBody->print( $out );

	close( $out );
    
	# Strip formatting newlines in the XML
	$xml =~ s/\n//g;
	# Strip first text:p
	$xml =~ s/<text:p[^>]*>//;
	# Convert XML newlines to real ones
	$xml =~ s/<text:p[^>]*>/\n/g;
	# Remove tags
	$xml =~ s/<[^>]*>//g;
	return $xml;
}

1;

__END__

=head1 NAME

Document::ToText::application_vnd_oasis_opendocument_text - A plugin for L<Document::ToText> to handle ODT files