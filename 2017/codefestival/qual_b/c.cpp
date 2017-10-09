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
vector<int> E[101010];
int C[101010];
int num[101010];

void dfs(int cur,int col) {
	if(C[cur]!=-1) {
		if(C[cur]!=col) {
			cout<<1LL*N*(N-1)/2-M<<endl;
			exit(0);
		}
	}
	else if(C[cur]==-1) {
		C[cur]=col;
		num[col]++;
		FORR(e,E[cur]) dfs(e,col^1);
		
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(C);
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	dfs(0,0);
	
	cout<<1LL*num[0]*num[1]-M<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
