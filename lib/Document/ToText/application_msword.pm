package Document::ToText::application_msword;

use Text::Extract::Word;

sub parse
{
	Text::Extract::Word->new( $_[0] )->get_body;
}

1;

__END__

=head1 NAME

Document::ToText::application_msword - A plugin for L<Document::ToText> to handle DOC files