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
ll N;

vector<pair<ll,ll>> cand[33];
map<int,int> V;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=2;i<=32;i++) {
		for(ll x=2;;x++) {
			ll v=1;
			FOR(j,i) v*=x;
			if(v>1000000000) break;
			V[v]=i;
		}
	}
	
	cin>>T;
	while(T--) {
		cin>>N;
		ll ret=0;
		// same
		ret=(N-1)*N;
		// a=c=1
		ret+=N*N;
		// b=1 or d=1;
		FORR(v,V) if(v.first<=N) {
			for(x=1;x<v.second;x++) {
				y=v.second*x/__gcd(x,v.second);
				ret+=2*(N/(y/x));
			}
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
