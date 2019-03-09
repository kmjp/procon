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

int N,A,B,C;
int L[10];

int mi=1<<30;

void dfs(int cur,int a,int b,int c,int co) {
	if(cur==N) {
		if(a==0 || b==0 || c==0) return;
		
		mi=min(mi,co+abs(A-a)+abs(B-b)+abs(C-c));
		
		return;
	}
	
	dfs(cur+1,a+L[cur],b,c,co+10);
	dfs(cur+1,a,b+L[cur],c,co+10);
	dfs(cur+1,a,b,c+L[cur],co+10);
	dfs(cur+1,a,b,c,co);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B>>C;
	FOR(i,N) cin>>L[i];
	
	dfs(0,0,0,0,-30);
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
