#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll H,W;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	ll mi=1LL<<60;
	
	x = H/3;
	y = (H+2)/3;
	mi = min(mi,(y-x)*W);
	x = W/3;
	y = (W+2)/3;
	mi = min(mi,(y-x)*H);
	
	for(x=1;x<W;x++) {
		ll a=x*H;
		ll b=(H/2)*(W-x);
		ll c=((H+1)/2)*(W-x);
		mi = min(mi, max({a,b,c})-min({a,b,c}));
	}
	for(y=1;y<H;y++) {
		ll a=y*W;
		ll b=(W/2)*(H-y);
		ll c=((W+1)/2)*(H-y);
		mi = min(mi, max({a,b,c})-min({a,b,c}));
	}
	
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
