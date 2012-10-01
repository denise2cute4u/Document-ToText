use strict;
use warnings;

use Test::Most;
use Text::Convert;

for my $doc ( grep { /\./ } split /\n/, `find \$PWD/t/files` )
{
	lives_ok { txt $doc } $doc;
}

done_testing;