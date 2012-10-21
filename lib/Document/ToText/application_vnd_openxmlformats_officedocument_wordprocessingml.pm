package Document::ToText::application_vnd_openxmlformats_officedocument_wordprocessingml;

use Archive::Zip;

sub parse
{
	my $zip = Archive::Zip->new;

	$zip->read( $_[0] );

	$xml = $zip->contents( 'word/document.xml' );
}

1;

__END__

=head1 NAME

Document::ToText::application_vnd_openxmlformats_officedocument_wordprocessingml - A plugin for L<Document::ToText> to handle DOCX files