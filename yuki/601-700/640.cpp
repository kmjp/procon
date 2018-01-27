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

int N;
string S[75];
int LR[76][76];
int UD[76][76];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) {
		cin>>S[y];
		FOR(x,N) {
			LR[y+1][x+1]=LR[y+1][x]+(S[y][x]=='#');
			UD[y+1][x+1]=UD[y][x+1]+(S[y][x]=='#');
		}
	}
	
	
	int ma=0;
	// all yoko
	int ret=0;
	FOR(y,N) if(LR[y+1][N-1]-LR[y+1][1]==0 && (S[y][0]=='.'||S[y][N-1]=='.')) ret++;
	ma=max(ma,ret);
	ret=0;
	FOR(x,N) if(UD[N-1][x+1]-UD[1][x+1]==0 && (S[0][x]=='.'||S[N-1][x]=='.')) ret++;
	ma=max(ma,ret);
	
	int L=0,R=0,U=0,D=0;
	if(UD[N-1][1]-UD[1][1]==0 && (S[0][0]=='.'||S[N-1][0]=='.')) L=1;
	if(UD[N-1][N]-UD[1][N]==0 && (S[0][N-1]=='.'||S[N-1][N-1]=='.')) R=1;
	FOR(y,N) {
		if(LR[y+1][N]-LR[y+1][1]==0) L++;
		if(LR[y+1][N-1]-LR[y+1][0]==0) R++;
	}
	if(LR[1][N-1]-LR[1][1]==0 && (S[0][0]=='.'||S[0][N-1]=='.')) U=1;
	if(LR[N][N-1]-LR[N][1]==0 && (S[N-1][0]=='.'||S[N-1][N-1]=='.')) D=1;
	FOR(x,N) {
		if(UD[N][x+1]-UD[1][x+1]==0) U++;
		if(UD[N-1][x+1]-UD[0][x+1]==0) D++;
	}
	
	ma=max({ma,L,R,U,D});
	
	if(LR[1][N]==0 && LR[N][N]==0 && UD[N][1]==0 && UD[N][N]==0) ma=max(ma,4);
	
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
