#!/usr/bin/perl

use Data::Dumper;

sub gv  { my $t=<>; chomp $t; return $t}
sub gls { my $t=<>; chomp $t; return split(/ +/,$t);}
sub gl  { my $t=<>; chomp $t; return split(//,$t);}
sub printa  { print join("",@_) . "\n" ; print STDERR join("",@_) . "\n" ; }

$set = gv();

for $cset(1..$set){
	$t = gv();
	
	@row=();
	for(0..($t-1)){
		my $v=0;
		my @a=gl();
		for $b(0..$#a){
			if($a[$b]=='1'){ $v=$b+1;}
		}
		$row[$_]=$v;
	}
	
	$ans=0;
	for $i(0..($t-1)){
		#print "/$i @row\n";
		for $s(($i) .. ($t-1)){
			#print "$i $s @row\n";
			if($row[$s]<=$i+1){
				if($s==$i){last;}
				$ans+=$s-$i;
				#print "-- $s $i * @row\n";
				my $u=$row[$s];
				@row[($i+1)..$s]=@row[$i..($s-1)];
				$row[$i]=$u;
				#print "-- @row\n";
				last;
			}
		}
		
	}
	
	
	
	
	printf STDERR "Case #%d: %s\n",$cset,$ans;
	printf "Case #%d: %s\n",$cset,$ans;
}
