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

int L;
string S;
int par[5010][5010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	L=S.size();
	
	FOR(i,L) par[i][i+1]=1;
	FOR(i,L-1) if(S[i]==S[i+1]) par[i][i+2]=1;
	for(i=3;i<=L;i++) {
		for(x=0;x+i<=L;x++) if(par[x+1][x+i-1] && S[x]==S[x+i-1]) par[x][x+i]=1;
	}
	ll ret=0;
	for(i=2;i<=L;i++) {
		y=0;
		for(x=1;x<i;x++) if(par[0][x] && par[x][i]) y++;
		for(x=1;i+x<L;x++) if(par[L-x][L]) ret+=y;
	}
	cout<<ret<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
