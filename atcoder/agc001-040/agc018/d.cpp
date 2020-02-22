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
vector<pair<int,int>> E[101010];
int num[101010];
ll ret;
int C[101010];

pair<int,int> dfs_center(int cur,int pre) {
	pair<int,int> res=make_pair(1<<30,-1);
	int ma=0;
	num[cur]=1;
	
	FORR(r,E[cur]) if(r.first!=pre) {
		res=min(res,dfs_center(r.first,cur));
		ma=max(ma,num[r.first]);
		num[cur]+=num[r.first];
	}
	return min(res,make_pair(max(ma,N-num[cur]),cur));
}

int dfs(int cur,int pre,ll dep) {
	ret+=dep*2;
	C[cur]=1;
	FORR(e,E[cur]) if(e.first!=pre) C[cur]+=dfs(e.first,cur,dep+e.second);
	return C[cur];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	
	int center=dfs_center(0,-1).second;
	dfs(center,center,0);
	int mi=1LL<<30;
	FORR(e,E[center]) {
		if(C[e.first]*2==N) {
			cout<<ret-e.second<<endl;
			return;
		}
		mi=min(mi,e.second);
	}
	cout<<ret-mi<<endl;
	
	

}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
