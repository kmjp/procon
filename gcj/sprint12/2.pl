#!/usr/bin/perl

use Data::Dumper;

sub gv  { my $t=<>; $t=~s/[\r\n]//g; return $t}
sub gls { my $t=<>; $t=~s/[\r\n]//g; return split(/ +/,$t);}
sub gl  { my $t=<>; $t=~s/[\r\n]//g; return split(//,$t);}
sub printa  { print join("",@_) . "\n" ; print STDERR join("",@_) . "\n" ; }


$set = gv();

for $cset(1..$set){
	($k,$s) = gls();
	
	$sl=length($s);
	
	%map=();
	for $i (0..($sl-$k)) {
		$st = substr($s,$i,$k);
		$map{$st}++;
	}
	#print Dumper(%map);
	@list = sort grep {$map{$_}>1} keys %map;
	if($#list==-1) {
		printf STDERR "Case #%d: NONE\n",$cset;
		printf "Case #%d: NONE\n",$cset;
	}
	else {
		printf STDERR "Case #%d: @list\n",$cset;
		printf "Case #%d: @list\n",$cset;
	}
		
}
