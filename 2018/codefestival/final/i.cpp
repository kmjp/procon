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
ll K;
vector<ll> V[51];

ll ok(ll v) {
	vector<ll> C;
	
	int i;
	ll tot=0;
	FOR(i,50) {
		FORR(v,V[i]) C.push_back(v);
		sort(ALL(C));
		if((v&(1LL<<i)) && C.size()) {
			tot+=C.back();
			C.pop_back();
		}
		vector<ll> C2;
		while(C.size()>=2) {
			C2.push_back(C[C.size()-1]+C[C.size()-2]);
			C.pop_back();
			C.pop_back();
		}
		if(C.size()) C2.push_back(C[0]);
		swap(C,C2);
	}
	return tot;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>x>>y;
		V[x].push_back(y);
	}
	
	ll mi=1LL<<50;
	for(i=49;i>=0;i--) if(ok(mi-(1LL<<i))>=K) mi-=1LL<<i;
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
