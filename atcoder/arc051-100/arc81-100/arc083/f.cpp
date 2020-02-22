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
vector<int> E[202020];
int vis[202020];
ll ret=1;
ll mo=1000000007;
ll rev[202020];

vector<int> P,LP;
set<int> Vs,IL;
set<pair<int,int>> Es;
map<pair<int,int>,int> O;

void dfs(int cur) {
	int i;
	if(Vs.count(cur)) {
		if(LP.size()) return;
		int add=0;
		FOR(i,P.size()) {
			if(P[i]==cur) add=1;
			if(add) {
				LP.push_back(P[i]);
				IL.insert(P[i]);
			}
		}
		return;
	}
	vis[cur]=1;
	Vs.insert(cur);
	P.push_back(cur);
	FORR(e,E[cur]) if(Es.count({min(e,cur),max(e,cur)})==0) {
		Es.insert({min(e,cur),max(e,cur)});
		dfs(e);
	}
	P.pop_back();
	
}

void dfs2(int cur,int pre) {
	O[{min(cur,pre),max(cur,pre)}]=cur;
	FORR(e,E[cur]) if(e!=pre) dfs2(e,cur);
}

ll hoge(int cur) {
	LP.clear();
	IL.clear();
	P.clear();
	Vs.clear();
	Es.clear();
	
	dfs(cur);
	if(Vs.size()!=Es.size()) return 0;
	LP.push_back(LP[0]);
	
	ll r[2]={1,1};
	int i,x;
	FOR(i,2) {
		O.clear();
		
		FORR(v,LP) FORR(e,E[v]) if(IL.count(e)==0) dfs2(e,v);
		FOR(x,LP.size()-1) O[{min(LP[x],LP[x+1]),max(LP[x],LP[x+1])}]=LP[x+i];
		map<pair<int,int>,int> cost;
		FORR(p,Es) {
			cost[p]++;
			int take=O[p];
			int oth=p.first+p.second-take;
			FORR(v,E[take]) {
				if(v<oth) cost[p]+=cost[{min(v,take),max(v,take)}];
				if(v>=oth) break;
			}
			(r[i]*=rev[cost[p]])%=mo;
		}
		
	}
	return (r[0]+r[1])%mo;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	rev[1]=1;
	for(i=2;i<=201000;i++) rev[i] = rev[mo%i]*(mo-mo/i)%mo;
	
	cin>>N;
	FOR(i,2*N) {
		cin>>x>>y;
		E[x-1].push_back(y-1+N);
		E[y-1+N].push_back(x-1);
	}
	FOR(i,2*N) sort(ALL(E[i]));
	
	FOR(i,2*N) {
		if(E[i].size() && vis[i]==0) (ret*=hoge(i))%=mo;
		ret=ret*(1+i)%mo;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
