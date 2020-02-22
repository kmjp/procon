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

int N,K;
int A[101010];
int D[101010];
vector<int> E[101010];
int ret;

int dfs(int cur) {
	if(cur==0) return 0;
	if(D[cur]>=0) return D[cur];
	return D[cur]=dfs(A[cur])+1;
}

int dfs2(int cur) {
	int ma=0;
	FORR(r,E[cur]) ma=max(ma,dfs2(r)+1);
	if(cur==0) return 0;
	
	if(ma==K-1 && A[cur]!=0) ret++, ma=-1;
	return ma;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>A[i];
		A[i]--;
		if(i) E[A[i]].push_back(i);
	}
	
	if(A[0]!=0) ret++;
	dfs2(0);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
