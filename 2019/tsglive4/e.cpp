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

int L[3];
string S[3];
int memo[101][101][101];

int dfs(int a,int b,int c) {
	if(a>L[0]||b>L[1]||c>L[2]) return 101010;

	if(a==L[0]&&b==L[1]&&c==L[2]) return 0;
	if(memo[a][b][c]>=0) return memo[a][b][c];
	int ret=101010;

	if(a<L[0]) ret=min(ret,dfs(a+1,b,c)+1);
	if(b<L[1]) ret=min(ret,dfs(a,b+1,c)+1);
	if(c<L[2]) ret=min(ret,dfs(a,b,c+1)+1);

	if(a<L[0]) {
		int cb=0,cc=0;
		if(b<L[1]&&S[1][b]!=S[0][a]) cb++;
		if(c<L[2]&&S[2][c]!=S[0][a]) cc++;
		ret=min(ret,dfs(a+1,b+1,c+1)+cb+cc);
		ret=min(ret,dfs(a+1,b+1,c)+cb+1);
		ret=min(ret,dfs(a+1,b,c+1)+1+cc);
		ret=min(ret,dfs(a+1,b,c)+2);
	}
	if(b<L[1]) {
		int ca=0,cc=0;
		if(a<L[0]&&S[0][a]!=S[1][b]) ca++;
		if(c<L[2]&&S[2][c]!=S[1][b]) cc++;
		ret=min(ret,dfs(a+1,b+1,c+1)+ca+cc);
		ret=min(ret,dfs(a+1,b+1,c)+ca+1);
		ret=min(ret,dfs(a,b+1,c+1)+1+cc);
		ret=min(ret,dfs(a,b+1,c)+2);
	}
	if(c<L[2]) {
		int ca=0,cb=0;
		if(a<L[0]&&S[0][a]!=S[2][c]) ca++;
		if(b<L[1]&&S[1][b]!=S[2][c]) cb++;
		ret=min(ret,dfs(a+1,b+1,c+1)+ca+cb);
		ret=min(ret,dfs(a+1,b,c+1)+ca+1);
		ret=min(ret,dfs(a,b+1,c+1)+1+cb);
		ret=min(ret,dfs(a,b,c+1)+2);
	}
	return memo[a][b][c]=ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,3) {
		cin>>L[i]>>S[i];
	}
	MINUS(memo);
	cout<<dfs(0,0,0)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
