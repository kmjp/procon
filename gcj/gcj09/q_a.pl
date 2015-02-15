#!/usr/bin/perl

use Data::Dumper;

$a = <>;
chomp $a;
($l,$d,$set) = split(/ +/,$a);
for($i=1;$i<=$d;$i++){
	$a = <>;
	push(@word,$a);
};
chomp @word;

for($i=1;$i<=$set;$i++){
	$pat = <>;
	chomp $pat;
	$pat =~ s/\(/[/g;
	$pat =~ s/\)/]/g;
	
	$ans=0;
	for(@word){
		if(/$pat/){ $ans++};
	}
	printf "Case #%d: %d\n",$i,$ans;
}



