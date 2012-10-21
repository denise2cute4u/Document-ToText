use Test::Most;

BEGIN { use_ok 'Document::ToText' }

can_ok __PACKAGE__, 'txt';

open my $txt, '<', 't/files/hacker_ethic.txt';
$txt = do { local $/; <$txt> };

my $txtLoose = $txt;
   $txtLoose =~ s/\d\. //g;

lives_ok { is txt( $_ ), $_ =~ /\.(?:doc|odt)$/ ? $txtLoose : $txt, $_ } $_ for ( <t/files/*> );

done_testing;