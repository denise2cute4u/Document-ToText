use Test::Most;

BEGIN { use_ok 'Document::ToText' }

can_ok __PACKAGE__, 'txt';

open my $txt, '<', 't/files/hacker_ethic.txt';
$txt = do { local $/; <$txt> };

lives_ok { is txt( $_ ), $txt } $_ for ( <t/files/*> );

done_testing;