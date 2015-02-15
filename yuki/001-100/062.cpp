#include <bits/stdc++.h>
using namespace std;
//typedef __int128_t ll;
typedef signed long long ll;
typedef signed long long ll2;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll2 W,H,D,MX,MY,HX,HY,VX,VY;

ll ext_gcd(ll p,ll q,ll& x, ll& y) { // get px+qy=gcd(p,q)
	if(q==0) return x=1,y=0,p;
	ll g=ext_gcd(q,p%q,y,x);
	y-=p/q*x;
	return g;
}

bool calc(ll tx,ll ty) {
	ll A=2*W*VY;
	ll B=-2*H*VX;
	ll C=ty*VX-tx*VY+HX*VY-HY*VX;
	ll2 g=__gcd(abs((ll2)A),abs((ll2)B));
	if(C%g) return false;
	C/=g; A/=g; B/=g;
	
	ll x,y;
	ext_gcd(A,B,x,y);
	ll m=C*y%A;
	ll tv=(ty+2*H*m-HY)/(ll)VY;
	
	tv %=2*H*A/VY;
	if(tv<0) tv +=2*H*A/(ll)VY;
	return tv<=D;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int Q;
	cin>>Q;
	while(Q--) {
		cin>>W>>H>>D>>MX>>MY>>HX>>HY>>VX>>VY;
		
		if(VX<0) MX=W-MX, HX=W-HX, VX=-VX;
		if(VY<0) MY=H-MY, HY=H-HY, VY=-VY;
		
		if(VX==0) {
			if(MX==HX && ((MY>HY&&(MY-HY)<=D*VY) || (MY<HY&&(2*H-MY-HY)<=D*VY))) _P("Hit\n");
			else _P("Miss\n");
			continue;
		}
		if(VY==0) {
			if(MY==HY && ((MX>HX&&(MX-HX)<=D*VX) || (MX<HX&&(2*W-MX-HX)<=D*VX))) _P("Hit\n");
			else _P("Miss\n");
			continue;
		}
		
		ll2 g=__gcd(VY,VX);
		D*=g;
		VY/=g;
		VX/=g;
		
		bool ok= calc(MX,MY) || calc(2*W-MX,MY) || calc(MX,2*H-MY) || calc(2*W-MX,2*H-MY);
		if(ok) _P("Hit\n");
		else _P("Miss\n");
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
