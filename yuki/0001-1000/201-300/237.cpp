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

ll A;
ll F[5]={3,5,17,257,65537};
set<ll> S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A;
	FOR(i,32) {
		ll r=1;
		FOR(j,5) if(i&(1<<j)) r*=F[j];
		S.insert(r);
	}
	
	ll ret=0;
	while(1) {
		ll a=*S.begin();
		S.erase(a);
		if(a>A) break;
		if(a>=3) ret++;
		S.insert(2*a);
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
