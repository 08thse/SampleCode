use LWP::UserAgent;
my $url = "http://www.google.com/";
my $ua = LWP::UserAgent->new();
my $req = HTTP::Request->new("GET", $url);
my $res = $ua->request($req);

print $res->code, "\n";
print $res->content, "\n";