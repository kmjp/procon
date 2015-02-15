#!/usr/bin/perl

use Data::Dumper;

$set = <>;
chomp $set;

sub func {
	my($id,$td)=@_;
	my $ta=0;
	
	#print "$id,$td $in[$id] $text[$td]";
	if($td > $#text){ return 1;}
	if($id > $#in){ return 0;}
	if(exists $cache{"$id,$td"}){ return $cache{"$id,$td"};}
	
	if($in[$id] eq $text[$td]){
		#print "[".$in[$id]."]";
		$ta = func($id+1,$td) + func($id+1,$td+1);
	}
	else {
		$ta = func($id+1,$td);
	}
	$cache{"$id,$td"} = $ta % 10000;
	return $ta % 10000;
}



for($i=1;$i<=$set;$i++){
	my $in = <>;
	chomp $in;
	$ans=0;
	$in =~ s/[^welcome to code jam]//g;
	$in =~ s/^[^w]+//;
	$in =~ s/[^m]+$//;
	@in=split(//,$in);
	@text=split(//,"welcome to code jam");
	
	%cache=();
	$ans = func(0,0) % 10000;
	
	printf "Case #%d: %04d\n",$i,$ans;
}



