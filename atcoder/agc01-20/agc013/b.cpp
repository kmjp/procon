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
int A[101010],B[101010];
vector<int> E[101010];
int did[101010];
vector<int> V[2];

int dfs(int cur,int id) {
	V[id].push_back(cur+1);
	did[cur]=1;
	
	FORR(r,E[cur]) if(did[r]==0) {
		dfs(r,id);
		break;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>A[i]>>B[i];
		A[i]--,B[i]--;
		E[A[i]].push_back(B[i]);
		E[B[i]].push_back(A[i]);
	}
	
	dfs(0,0);
	dfs(0,1);
	vector<int> R;
	while(V[0].size()>1) R.push_back(V[0].back()),V[0].pop_back();
	FOR(i,V[1].size()) R.push_back(V[1][i]);
	
	
	_P("%d\n",R.size());
	FOR(i,R.size()) _P("%d%c",R[i],(i==R.size()-1)?'\n':' ');
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
