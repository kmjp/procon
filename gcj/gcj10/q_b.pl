#!/usr/bin/perl

use Data::Dumper;
use Math::BigInt;

sub gv  { my $t=<>; chomp $t; return $t}
sub gls { my $t=<>; chomp $t; return split(/ +/,$t);}
sub gl  { my $t=<>; chomp $t; return split(//,$t);}
sub printa  { print join("",@_) . "\n" ; print STDERR join("",@_) . "\n" ; }

$set = gv();

for $cset(1..$set){
	@row=gls();
	$n = shift @row;
	@row = sort { $a <=> $b } map { Math::BigInt->new($_) }@row;
	@brow = map {$_ - $row[0]} @row;
	shift @brow;
	while($#brow>0) {
		my $a = shift @brow;
		my $b = shift @brow;
		my $c = gcd($a,$b);
		#print "$a $b -> $c\n";
		unshift(@brow,$c);
	}
	
	$res = $brow[0] - ($row[0]->bmod($brow[0]));
	if($res == $brow[0]) { $res=0;}
	#print $brow[0] . " : ";
	for my $aa(@row) {
		#print (($aa+$res) % $brow[0]) . " ";
		
	}
	
	
	printf STDERR "Case #%d: %s\n",$cset,$res;
	printf "Case #%d: %s\n",$cset,$res;
}



sub gcd{
	my ($a,$b)=@_;
	my $c;
	
	if($a->bcmp($b)>0){
		$c=$b;
		$b=$a;
		$a=$c;
	}
	while(1) {
		#print "$a $b - \n";
		if($a->is_zero()){ return $b; }
		my $c = $a;
		$a = $b->bmod($a);
		$b = $c;
	}
}

