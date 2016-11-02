use strict;
use warnings;
use Net::Twitter;
use Encode;
use utf8;

my $nt = Net::Twitter->new( traits => [qw/API::Search API::REST/] );
my $r = $nt->search('test');
for my $status ( @{ $r->{results} } ) {
   print encode_utf8("$status->{text}\n");
}