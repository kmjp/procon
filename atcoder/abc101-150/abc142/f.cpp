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

int N,M;
vector<int> E[1010];
int vis[1010];
vector<int> V,C;
int id[1010];

void dfs(int cur) {
	if(vis[cur]==2) {
		if(C.empty()) {
			int i,j;
			FOR(i,V.size()) if(V[i]==cur) {
				for(j=i;j<V.size();j++) {
					C.push_back(V[j]);
					id[V[j]]=j-i;
				}
				break;
			}
		}
		return;
	}
	if(vis[cur]==1) return;
	vis[cur]=2;
	V.push_back(cur);
	FORR(e,E[cur]) dfs(e);
	V.pop_back();
	vis[cur]=1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x].push_back(y);
	}
	
	MINUS(id);
	FOR(i,N) {
		ZERO(vis);
		V.clear();
		dfs(i+1);
	}
	
	if(C.empty()) return _P("-1\n");
	retry:
	FOR(i,C.size()) {
		FORR(e,E[C[i]]) if(id[e]!=-1 && id[e]!=(id[C[i]]+1)%C.size()) {
			vector<int> C2;
			y=id[e];
			MINUS(id);
			FOR(j,C.size()) {
				C2.push_back(C[(y+j)%C.size()]);
				id[C[(y+j)%C.size()]]=j;
				if((y+j)%C.size()==i) break;
			}
			swap(C,C2);
			goto retry;
		}
	}
	
	cout<<C.size()<<endl;
	FORR(c,C) cout<<c<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
