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

ll N,K;
ll mo=1000000007;

vector<pair<ll,ll>> V;
int tar[150505];

ll from[101010];
ll S[101010];
ll to[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	for(i=1;;i++) {
		V.push_back({i,i});
		if(i*i>N) break;
	}
	i++;
	V.push_back({i,i});
	while(i>=1) {
		ll L=N/(i+1)+1;
		ll R=N/i;
		//cout<<L<<" "<<R<<endl;
		L=max(L,V.back().second+1);
		if(L<=R) V.push_back({L,R});
		i--;
	}
	
	while(V.back().first>N) V.pop_back();
	V.back().second=min(V.back().second,N);
	
	FOR(i,V.size()) {
		x=0;
		for(j=20;j>=0;j--) if(x+(1<<j)<V.size() && 1LL*V[i].second*V[x+(1<<j)].second<=N) x+=1<<j;
		tar[i]=x;
		from[i]=V[i].second-V[i].first+1;
		//cout<<i<<" "<<V[i].first<<" "<<V[i].second<<" "<<tar[i]<<endl;
	}
	
	
	K--;
	while(K--) {
		FOR(i,V.size()) S[i+1]=(S[i]+from[i])%mo;
		FOR(i,V.size()) to[i]=S[tar[i]+1]*(V[i].second-V[i].first+1)%mo;
		swap(from,to);
	}
	
	ll ret=0;
	FOR(i,V.size()) ret+=from[i];
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
