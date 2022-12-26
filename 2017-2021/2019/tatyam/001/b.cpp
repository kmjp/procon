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

int N;
ll A;
ll F[1010];
string S[1010];

bool isprime(ll v) {
	for(ll i=2;i*i<=v;i++) if(v%i==0) return false;
	return (v!=1);
}


ll hoge(vector<ll> V) {
	int i;
	for(i=1;i<V.size();i++) if(V[i]==1) return 1LL<<60;
	if(!isprime(V[0])) return 1LL<<60;
	
	while(V.size()>1) {
		ll q=V.back();
		V.pop_back();
		ll p=V.back();
		V.pop_back();
		ll r=1;
		while(q--) {
			r*=p;
			if(r>1LL<<30) return r;
		}
		V.push_back(r);
	}
	return V.back();
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A;
	FOR(i,N) cin>>S[i]>>F[i];
	vector<vector<ll>> V;
	V.push_back(vector<ll>());
	FOR(i,N) {
		if(i && S[i]=="*") {
			V.push_back(vector<ll>());
		}
		V.back().push_back(F[i]);
	}
	FORR(v,V) {
		ll ret=hoge(v);
		if(A%ret) return _P("No\n");
		A/=ret;
	}
	if(A!=1) return _P("No\n");
	cout<<"Yes"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
