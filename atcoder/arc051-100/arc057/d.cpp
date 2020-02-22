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
int A[31];
ll mo=1000000007;
int yes[900];

map<vector<int>, ll> memo[900][900];

ll dfs(vector<int> V,int id,int left) {
	
	if(id>N*(N-1)/2) return 1;
	
	if(memo[id][left].count(V)) return memo[id][left][V];
	ll ret=0;
	
	if(yes[id]) {
		if(V.size()>1) {
			int x,y,z;
			FOR(y,V.size()) FOR(x,y) {
				vector<int> V2;
				FOR(z,V.size()) if(z!=x && z!=y) V2.push_back(V[z]);
				V2.push_back(V[x]+V[y]);
				sort(ALL(V2));
				ret += V[x]*V[y]*dfs(V2,id+1,left+V[x]*V[y]-1);
			}
		}
	}
	else {
		if(left) ret = left * dfs(V,id+1,left-1) % mo;
	}
	
	return memo[id][left][V]=ret%mo;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	if(N==1) return _P("1\n");
	
	FOR(i,N-1) cin>>x, yes[x]=1;
	cout<<dfs(vector<int>(N,1),1,0)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
