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

int N,Q;
vector<int> E[101010];
int D[101010],P[101010];
int CL[101010],CR[101010],GL[101010],GR[101010];
int DN[101010],id[101010];
set<pair<int,ll>> S[101010];

void dfs(int cur,int pre,int d) {
	D[cur]=d;
	P[cur]=pre;
	id[cur]=++DN[D[cur]];
	CL[cur]=GL[cur]=1<<20;
	CR[cur]=GR[cur]=-1;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur,d+1);
		CL[cur]=min(CL[cur],id[e]);
		CR[cur]=max(CR[cur],id[e]);
		GL[cur]=min(GL[cur],CL[e]);
		GR[cur]=max(GR[cur],CR[e]);
	}
	
}

ll poke(int e) {
	ll tot=0;
	auto it=S[D[e]].lower_bound(make_pair(id[e],0));
	if(it!=S[D[e]].end() && it->first==id[e]) {
		tot=it->second;
		S[D[e]].erase(it);
	}
	return tot;
}

ll poke_range(int d,int L,int R) {
	ll tot=0;
	while(1) {
		auto it=S[d].lower_bound({L,0});
		if(it==S[d].end() || it->first>R) break;
		tot+=it->second;
		S[d].erase(it);
	}
	return tot;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	dfs(0,0,0);
	FOR(i,N) {
		cin>>x;
		S[D[i]].insert({id[i],x});
	}
	cin>>Q;
	while(Q--) {
		cin>>x;
		ll tot=poke(x);
		
		if(D[x]>=2) {
			tot+=poke(P[P[x]]);
		}
		if(D[x]>=1) {
			tot+=poke(P[x]);
			tot+=poke_range(D[x],CL[P[x]],CR[P[x]]);
		}
		tot+=poke_range(D[x]+1,CL[x],CR[x]);
		tot+=poke_range(D[x]+2,GL[x],GR[x]);
		S[D[x]].insert({id[x],tot});
		cout<<tot<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
