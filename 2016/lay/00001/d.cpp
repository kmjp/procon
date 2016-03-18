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

int T;
ll X,N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>X>>N;
		
		vector<ll> V;
		for(ll i=2;i*i<=X;i++) if(X%i==0) {
			V.push_back(i);
			while(X%i==0) X/=i;
		}
		if(X>1) V.push_back(X);
		
		ll num=0;
		for(int mask=0;mask<(1<<V.size());mask++) {
			int sgn=1;
			ll x=1;
			FOR(i,V.size()) if(mask & (1<<i)) x *= V[i], sgn=-sgn;
			num += sgn*(N/x);
		}
		cout<<num<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
