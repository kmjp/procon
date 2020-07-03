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

int N,M,K,S,T;
vector<pair<int,int>> V[202020];
ll from[202020];
ll to[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K>>S>>T;
	FOR(i,M) {
		cin>>x>>y>>j;
		V[x-1].push_back({y,j});
	}
	
	map<ll,ll> cur;
	cur[S]=0;
	
	FOR(i,N-1) {
		map<ll,ll> nex;
		vector<pair<ll,ll>> T;
		FORR(c,cur) T.push_back(c);
		if(T.empty()) break;
		FOR(j,T.size()-1) {
			T[j+1].second=min(T[j+1].second,T[j].second+T[j+1].first-T[j].first);
		}
		for(j=(int)T.size()-2;j>=0;j--) {
			T[j].second=min(T[j].second,T[j+1].second+T[j+1].first-T[j].first);
		}
		FORR(e,V[i]) {
			if(nex.count(e.second)==0) nex[e.second]=1LL<<50;
			x = lower_bound(ALL(T),make_pair((ll)e.first,0LL))-T.begin();
			if(x>=0 && x<T.size()) nex[e.second]=min(nex[e.second],T[x].second+abs(e.first-T[x].first));
			x++;
			if(x>=0 && x<T.size()) nex[e.second]=min(nex[e.second],T[x].second+abs(e.first-T[x].first));
			x--,x--;
			if(x>=0 && x<T.size()) nex[e.second]=min(nex[e.second],T[x].second+abs(e.first-T[x].first));
		}
		swap(cur,nex);
	}
	if(cur.empty()) {
		cout<<-1<<endl;
	}
	else {
		ll ret=1LL<<60;
		FORR(c,cur) ret=min(ret,c.second+abs(T-c.first));
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
