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

int M,N;
int A[101010];
vector<vector<int>> V;
vector<vector<ll>> S;
int id[101010],id2[101010];
int vis[101010];

void dfs(int cur) {
	vis[cur]=1;
	id[cur]=V.size()-1;
	id2[cur]=V.back().size();
	V.back().push_back(A[cur]);
	if(vis[A[cur]-1]==0) dfs(A[cur]-1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M>>N;
	FOR(i,M) cin>>A[i];
	FOR(i,M) if(vis[i]==0) {
		V.push_back(vector<int>());
		dfs(i);
		S.push_back(vector<ll>());
		S.back().push_back(0);
		FORR(r,V.back()) S.back().push_back(S.back().back()+r);
		FORR(r,V.back()) S.back().push_back(S.back().back()+r);
	}
	
	FOR(i,M) {
		x = id[i];
		y = id2[i];
		ll a=N/V[x].size()*S[x][V[x].size()];
		ll b=S[x][y+N%V[x].size()]-S[x][y];
		
		cout<<a+b<<" ";
	}
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
