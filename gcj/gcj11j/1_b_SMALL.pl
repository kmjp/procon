#!/usr/bin/perl

# small‚Ì‚Ý•”•ª“_

use Data::Dumper;
use Math::BigInt;

sub gv  { my $t=<>; chomp $t; return $t}
sub gls { my $t=<>; chomp $t; return split(/ +/,$t);}
sub gl  { my $t=<>; chomp $t; return split(//,$t);}
sub printa  { print join("",@_) . "\n" ; print STDERR join("",@_) . "\n" ; }

$set = gv();

for $cset(1..$set){
	@row=gls();
	
	$a = Math::BigInt->new($row[0]);
	if($row[2]==1) {
		$a = 0;
	}
	else {
		if($row[1]==1) {
			$a = $a->bmodpow($a, $row[2]);v
		}
		else {
			$a = ($a**$a);
			$a = $a->bmodpow($a, $row[2]);v
			
		}
	}
	
	printf STDERR "Case #%d: %s\n",$cset,$a;
	printf "Case #%d: %s\n",$cset,$a;
}



