package Document::ToText::text_plain;

sub parse
{
	open my $fh, '<', $_[0];

	do { local $/; <$fh> };
}

1;

__END__

=head1 NAME

Document::ToText::text_plain - A plugin for L<Document::ToText> to handle TXT files