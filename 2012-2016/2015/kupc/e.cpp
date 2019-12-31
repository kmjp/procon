#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T;
int H,W;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		if(W<H) swap(H,W);
		double ma=min(W*1.0,sqrt(H*H+W*0.5*W*0.5));
		
		double rate=sqrt(H*H+W*W)/W;
		double aa=sqrt(H*H+W*W)/2*rate;
		ma=max(ma,aa);
		
		double t=2*W-sqrt(3)*H;
		if(t>=0 && t<=W) {
			double X=H*0.5+sqrt(3)*t/2;
			if(X>=0 && X<=H) ma=max(ma,sqrt(H*H+t*t));
		}
		
		_P("%.12lf\n",ma);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
