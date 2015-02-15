#!/usr/bin/perl

use Data::Dumper;
use Math::BigInt;

sub gv  { my $t=<>; chomp $t; return $t}
sub gls { my $t=<>; chomp $t; return split(/ +/,$t);}
sub gl  { my $t=<>; chomp $t; return split(//,$t);}
sub printa  { print join("",@_) . "\n" ; print STDERR join("",@_) . "\n" ; }

my $t=<>;
chomp $t;
my($x,$y)=split(/\//,$t);
$X=Math::BigInt->new($x);
$Y=Math::BigInt->new($y);
#$N=2*$X/$Y-2;
$N=2*$X;
$N = $N->bdiv($Y) - 2;

$loop=0;
$a=0;
while(1){
	if($loop>5){
		if($a==0) {
			print "Impossible\n";
		}
		exit;
	}
	if($N>=1) {
		$M=($N+1)*$N/2;
		$T=$N*$X;
		if($T % $Y==0) {
			$M=$M-$T/$Y;
			if($M>=1 && $M<=$N) {
				printf "%s %s\n",$N,$M;
				$a=1;
			}
			
		}
	}
	$loop++;
	$N++;
}

