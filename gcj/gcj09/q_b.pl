#!/usr/bin/perl

use Data::Dumper;

$set = <>;
chomp $set;

sub color {
	my ($x,$y,$v)=@_;
	
	if($map[$y]->[$x] ne ''){ return; }
	$map[$y]->[$x] = $v;
	if($flow[$y]->[$x] eq "u"){ color($x,$y-1,$v); }
	if($flow[$y]->[$x] eq "d"){ color($x,$y+1,$v); }
	if($flow[$y]->[$x] eq "l"){ color($x-1,$y,$v); }
	if($flow[$y]->[$x] eq "r"){ color($x+1,$y,$v); }
	
	if($y<$h-1 && $flow[$y+1]->[$x] eq "u") { color($x,$y+1,$v) }
	if($y>0    && $flow[$y-1]->[$x] eq "d") { color($x,$y-1,$v) }
	if($x<$w-1 && $flow[$y]->[$x+1] eq "l") { color($x+1,$y,$v) }
	if($x>0    && $flow[$y]->[$x-1] eq "r") { color($x-1,$y,$v) }
	
}

for($i=1;$i<=$set;$i++){
	$in = <>;
	($h,$w) = split(/ +/,$in);
	@area = ();
	for($j=0;$j<$h;$j++){
		my $l = <>;
		chomp $l;
		@a = split(/ +/,$l);
		$area[$j] = [ @a ];
	}
	@flow=();
	for($y=0;$y<$h;$y++){
		for($x=0;$x<$w;$x++){
			$dir="none";
			$hei=$area[$y]->[$x];
			
			if($y>0 && $area[$y-1]->[$x] < $hei){ $dir="u"; $hei=$area[$y-1]->[$x];}
			if($x>0 && $area[$y]->[$x-1] < $hei){ $dir="l"; $hei=$area[$y]->[$x-1];}
			if($x<$w-1 && $area[$y]->[$x+1] < $hei){ $dir="r"; $hei=$area[$y]->[$x+1];}
			if($y<$h-1 && $area[$y+1]->[$x] < $hei){ $dir="d"; $hei=$area[$y+1]->[$x];}
			$flow[$y]->[$x] = $dir;
		}
	}
	@map=();
	@val=split(//,"abcdefghijklmnopqrstuvwxyz");
	for($y=0;$y<$h;$y++){
		for($x=0;$x<$w;$x++){
			$map[$y]->[$x]='';
		}
	}
	for($y=0;$y<$h;$y++){
		for($x=0;$x<$w;$x++){
			if($map[$y]->[$x] eq ''){
				color($x,$y,shift(@val));
			}
		}
	}
	
	printf "Case #%d:\n",$i;
	for($y=0;$y<$h;$y++){
		for($x=0;$x<$w;$x++){
			if($x!=0) {print " ";}
			print $map[$y]->[$x];
		}
		print "\n";
	}
}



