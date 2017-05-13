#!/usr/bin/perl

use Data::Dumper;

$set = <>;
chomp $set;



for($i=1;$i<=$set;$i++){
	$pat = <>;
	chomp $pat;
	my @num = split(//,$pat);
	
	#Œ…‚ª‘‚¦‚È‚¢
	my %nl=(),%rnl=();
	for(@num){ $nl{"$_"}++;}
	my @tmp = sort keys %nl;
	for (0..$#tmp){ $rnl{$tmp[$_]}=$_; }
	
	$err=0;
	
	$q=-1;
	for($j=$#num;$j>0;$j--){
		for($k=$j;$k>=0;$k--){
			if($num[$k]<$num[$j]){
				if($q < $k){
					$q = $k;
					$t = $j;
				}
				last;
			}
		}
	}
	if($q!=-1){
		@num=(@num[0..($q-1)],$num[$t],(sort @num[($q..$t-1),($t+1..$#num)]));
		$ans = join("",@num);
	}
	else {
		@num3 = sort @num;
		for($j=0;$j<=$#num3;$j++){
			if($num3[$j] ne '0'){last;}
		}
		
		$ans=$num3[$j] . "0" . join("",(@num3[0 .. $j-1],@num3[$j+1 .. $#num]));
	}
		
	
	printf STDERR "Case #%d: %s\n",$i,$ans;
	printf "Case #%d: %s\n",$i,$ans;
}



