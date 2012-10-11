use Test::Most;

BEGIN { use_ok 'Document::ToText' }

can_ok __PACKAGE__, 'txt';

my $hacker_ethic = do { local $/; <DATA> };

$0 =~ /(.*)\//;

lives_ok { is txt( $_ ), $hacker_ethic } $_ for ( <$1/files/*> );

done_testing;

__DATA__
Access to computers—and anything which might teach you something about the way the world works—should be unlimited and total. Always yield to the Hands-on Imperative!
All information should be free.
Mistrust authority—promote decentralization.
Hackers should be judged by their hacking, not bogus criteria such as degrees, age, race or position.
You can create art and beauty on a computer.
Computers can change your life for the better.