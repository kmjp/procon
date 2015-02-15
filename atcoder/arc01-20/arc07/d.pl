#!/usr/bin/perl

use Data::Dumper;
use bigint;

while(<>) {
	chomp;
	solve($_);
}

sub solve {
	my $vl = $_[0];
	$fl=1;
	if(substr($vl,0,1)=='0'){
		$f=1;
	}
	else {
		$f = substr($vl,0,1);
		$vl = substr($vl,1);
	}

	while(length($vl)>0 && substr($vl,0,1)=='0') {
		$f*=10;
		$fl++;
		$vl = substr($vl,1);
	}

	$sl=length($vl);
	if($sl==0) {
		out($f,1);
	}
	elsif($sl<$fl) {
		$up=1;
		while(1) {
			$min=$vl*(10**$up);
			$max=($vl+1)*(10**$up)-1;
			if($min>=$f+1) {out($f,$min-$f); last;}
			if($max>=$f+1) {out($f,1); last;}
			$up++;
		}
	}
	elsif($sl==$fl) {
		if($vl<$f+1){ $vl*=10;};
		out($f,$vl-$f);
	}
	else {
		#’T‚·
		
		for $len(1..(length($vl))) {
			$nv = substr($vl,0,$len);
			$dif = 0+$nv-$f;
			if($dif<1){ next;}
			
			$ok=1;
			$left = substr($vl,$len);
			while(length($left)>0) {
				$nv+=$dif;
				if(length($nv)<=length($left)) {
					$t = 0+substr($left,0,length($nv));
					if($t != $nv){ $ok=0; last;}
					$left=substr($left,length($nv));
				}
				else {
					$nvl = 0+substr($nv,0,length($left));
					if($nvl!=$left){ $ok=0;}
					last;
				}
			}
			if($ok==1) {
				out($f,$dif);
				last;
			}
		}
	}
}



sub out {
	printf "%s %s\n",$_[0],$_[1];
}

