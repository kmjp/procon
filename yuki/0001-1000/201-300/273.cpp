#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int L;
string S;
int par[51][51];
int dp[51];

int palin(string SS) {
	int i;
	FOR(i,SS.size()) if(SS[i]!=SS[SS.size()-1-i]) return 0;
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>S;
	L=S.size();
	
	FOR(x,L) for(y=1;x+y<=L;y++) if(x!=0 || x+y!=L) par[x][x+y]=palin(S.substr(x,y))*y;
	FOR(x,L) for(y=x+1;y<=L;y++) for(z=x+1;z<y;z++) par[x][y]=max(par[x][y],max(par[x][z],par[z][y]));
	cout<<par[0][L]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
