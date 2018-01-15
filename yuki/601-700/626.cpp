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
ll W;
pair<ll,ll> P[5050];
ll ma=0;

bool cmp(pair<ll,ll> L,pair<ll,ll> R) {
	return L.first*1.0/L.second>R.first*1.0/R.second;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>W;
	FOR(i,N) {
		cin>>P[i].first>>P[i].second;
	}
	sort(P,P+N,cmp);
	
	vector<pair<ll,ll>> V;
	V.push_back({0,0});
	FOR(i,N) {
		ll v=P[i].first,w=P[i].second;
		vector<pair<ll,ll>> V2=V;
		FORR(vv,V) if(vv.second+w<=W) V2.push_back({vv.first+v,vv.second+w});
		V.clear();
		sort(ALL(V2));
		reverse(ALL(V2));
		ll pre=W+1;
		FORR(vv,V2) if(vv.second<pre) V.push_back(vv), pre=vv.second;
	}
	
	ll ma=0;
	FORR(v,V) ma=max(ma,v.first);
	
	
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
