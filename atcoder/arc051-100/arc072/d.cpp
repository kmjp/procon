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

ll X,Y;
string A="Alice";
string B="Brown";

ll memo[100][100];

int win(int x,int y) {
	if(x<=1 && y<=1) return 0;
	if(memo[x][y]==-1) {
		memo[x][y]=0;
		int i;
		for(i=2;i<=x;i+=2) if(win(x-i,y+i/2)==0) memo[x][y]=1;
		for(i=2;i<=y;i+=2) if(win(y-i,x+i/2)==0) memo[x][y]=1;
	}
	return memo[x][y];
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(memo);
	
	for(i=1;i<=10;i++) {
		for(j=1;j<=10;j++) {
			//_P("%d %d %d\n",i,j,win(i,j));
		}
	}
	
	cin>>X>>Y;
	if(abs(X-Y)<=1) cout<<B<<endl;
	else cout<<A<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
