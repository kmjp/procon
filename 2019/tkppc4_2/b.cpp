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
vector<int> E[200005];
int C[202020];

int dfs(int cur,int pre) {
	int num=C[cur];
	int v=0;
	FORR(e,E[cur]) if(e!=pre) {
		int ret=dfs(e,cur);
		if(ret>0) {
			C[cur]+=ret;
			v++;
		}
	}
	if(C[cur]<M) v++;
	if(v>2) {
		cout<<"trumpet"<<endl;
		exit(0);
	}
	
	return C[cur];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}

	FOR(i,M) {
		cin>>x;
		C[x-1]++;
	}
	
	dfs(0,-1);
	cout<<"Yes"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
