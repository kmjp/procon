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

ll S;

void hoge(int x1,int y1,int x2,int y2,int x3,int y3) {
	_P("%d %d %d %d %d %d\n",x1,y1,x2,y2,x3,y3);
	
	x2-=x1;
	x3-=x1;
	y2-=y1;
	y3-=y1;
	
	ll a=1LL*x2*y3-1LL*y2*x3;
	assert(S==abs(a));
	exit(0);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	if(S<=1000000000LL) hoge(0,0,S,0,0,1);
	if(S%1000000000LL==0) hoge(0,0,1000000000,0,0,S/1000000000);
	ll Y=S/1000000000;
	ll X=S%1000000000;
	hoge(X,0,0,Y,1000000000,Y+1);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
