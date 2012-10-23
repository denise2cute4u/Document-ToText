use Test::Most;

BEGIN { use_ok 'Document::ToText' }

can_ok __PACKAGE__, 'txt';

open my $txt, '<', 't/files/hacker_ethic.txt';
$txt = do { local $/; <$txt> };

my %specialCase;

# ODT parsing can't handle ordered lists
$specialCase{ odt } = $txt;
$specialCase{ odt } =~ s/\d\. //g;

# Text::Extract::Word also can't handle ordered lists, and converts endashes to hyphens
$specialCase{ doc } = $specialCase{ odt };
$specialCase{ doc } =~ s/—/-/g;

lives_ok { is txt( $_ ), $specialCase{ ( split /\./, $_ )[1] } || $txt, $_ } $_ for ( <t/files/*> );

done_testing;