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
vector<pair<int,int>> E[101010];
ll D[101010];
int L[101010],R[101010];
int id;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bta,btb;

void dfs(int cur,int pre,int d) {
	D[cur]=d;
	
	L[cur]=id++;
	FORR(e,E[cur]) if(e.first!=pre) {
		int pa=id;
		dfs(e.first,cur,d+1);
		bta.add(pa,e.second);
		bta.add(id,-e.second);
	}
	R[cur]=id;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y>>r;
		E[x].push_back({y,r});
		E[y].push_back({x,r});
	}
	dfs(0,0,0);
	
	cin>>Q;
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x>>y;
			btb.add(L[x],y);
			btb.add(R[x],-y);
			bta.add(L[x],-D[x]*y);
			bta.add(R[x],D[x]*y);
			
		}
		else {
			cin>>x;
			cout<<bta(L[x])+D[x]*btb(L[x])<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
