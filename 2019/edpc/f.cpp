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


string S,T;
int A,B;
int memo[3030][3030];

int dfs(int x,int y) {
	if(memo[x][y]>=0) return memo[x][y];
	if(x==A||y==B) return memo[x][y]=0;
	
	if(S[x]==T[y]) return memo[x][y]=dfs(x+1,y+1)+1;
	
	return memo[x][y]=max(dfs(x+1,y),dfs(x,y+1));
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(memo);
	cin>>S>>T;
	A=S.size();
	B=T.size();
	
	dfs(0,0);
	
	x=y=0;
	while(x<A && y<B) {
		if(memo[x][y]==0) break;
		if(S[x]==T[y]) {
			cout<<S[x];
			x++;
			y++;
		}
		else if(memo[x+1][y]>memo[x][y+1]) {
			x++;
		}
		else {
			y++;
		}
	}
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
