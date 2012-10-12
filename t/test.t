use Test::Most;

BEGIN { use_ok 'Document::ToText' }

can_ok __PACKAGE__, 'txt';

my $hacker_ethic = do { local $/; <DATA> };

lives_ok { is txt( $_ ), $hacker_ethic } $_ for ( <t/files/*> );

done_testing;

__DATA__
1. Access to computers—and anything which might teach you something about the way the world works—should be unlimited and total. Always yield to the Hands-on Imperative!
2. All information should be free.
3. Mistrust authority—promote decentralization.
4. Hackers should be judged by their hacking, not bogus criteria such as degrees, age, race or position.
5. You can create art and beauty on a computer.
6. Computers can change your life for the better.