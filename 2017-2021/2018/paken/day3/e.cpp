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


int Q;
ll A,B,X;
ll C[110],S[110];
ll ret=0;

void dfs(int cur,ll X) {
	if(X==0) {
		ret++;
		return;
	}
	if(cur<0) return;
	if(X>S[cur]) return;
	
	if(C[cur]<=X) dfs(cur-2,X-C[cur]);
	dfs(cur-1,X);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>C[0]>>C[1]>>X;
		S[0]=C[0];
		S[1]=C[0]+C[1];
		for(i=2;i<=100;i++) {
			C[i]=min(C[i-1]+C[i-2],1LL<<60);
			S[i]=min(S[i-1]+C[i],1LL<<60);
		}
		ret=0;
		dfs(90,X);
		
		
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
