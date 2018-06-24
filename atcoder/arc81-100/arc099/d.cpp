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

int K;

int F(ll v) {
	int ret=0;
	while(v) {
		ret+=v%10;
		v/=10;
	}
	return ret;
}

ll nex(ll v) {
	vector<pair<ll,ll>> V;
	ll p=1;
	while(p<=v) {
		ll n=p*(v/p+1)-1;
		V.push_back({n,F(n)});
		p*=10;
	}
	sort(ALL(V));
	int x,y;
	FOR(x,V.size()) {
		
		for(y=x+1;y<V.size();y++) {
			if(V[x].first*V[y].second>V[y].first*V[x].second) break;
		}
		if(y==V.size()) return V[x].first;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K;
	vector<ll> V;
	V.push_back(1);
	while(V.size()<K) V.push_back(nex(V.back()+1));
	
	FORR(c,V) cout<<c<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
