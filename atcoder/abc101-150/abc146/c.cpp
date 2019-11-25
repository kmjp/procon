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

ll A,B,X;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>X;
	
	ll ma=0;
	int d=1;
	ll L=1,R=9;
	for(d=1;d<=10;d++) {
		
		ll needL=L*A+B*d;
		if(needL<=X) {
			ll add=min(R-L,(X-needL)/A);
			ma=max(ma,L+add);
		}
		
		L=L*10;
		R=L*10-1;
		if(R>1000000000) R=1000000000;
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
