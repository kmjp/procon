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


int N,M;
multiset<int> E[101010];
vector<pair<int,int>> V;

int dfs(int cur,int pre) {
	int lef=-1;
	while(E[cur].size()) {
		int x=*E[cur].begin();
		E[cur].erase(x);
		E[x].erase(cur);
		int y=dfs(x,cur);
		
		if(y!=-1) {
			if(lef==-1) lef=y;
			else {
				V.push_back({cur,lef});
				V.push_back({cur,y});
				lef=-1;
			}
		}
	}
	
	if(lef!=-1) {
		if(pre!=-1) {
			V.push_back({cur,pre});
			V.push_back({cur,lef});
			return -1;
		}
	}
	return cur;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x].insert(y);
		E[y].insert(x);
	}
	if(M%2) return _P("-1\n");
	
	dfs(1,-1);
	FORR(v,V) cout<<v.first<<" "<<v.second<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
