#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int W,H,D,MX,MY,HX,HY,VX,VY;
int hit[20][20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int Q;
	cin>>Q;
	while(Q--) {
		cin>>W>>H>>D>>MX>>MY>>HX>>HY>>VX>>VY;
		ZERO(hit);
		
		int g;
		if(VX==0) g=abs(VY);
		else if(VY==0) g=abs(VX);
		else g=__gcd(abs(VY),abs(VX));
		D*=g;
		VY/=g;
		VX/=g;
		
		FOR(i,min(D+1,257*4)) {
			int dx=abs(HX+i*VX),dy=abs(HY+i*VY);
			dx%=2*W;
			if(dx>W) dx=2*W-dx;
			dy%=2*H;
			if(dy>H) dy=2*H-dy;
			hit[dy][dx]=1;
		}
		if(hit[MY][MX]) _P("Hit\n");
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
