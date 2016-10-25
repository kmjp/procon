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

int H,W,X;
string S[303];
int dp[303][303];
string A,B;
int dif[303][303][303];


int dpdp(int a,int b) {
	if(a==0 || b==0) return 0;
	if(dp[a][b]>=0) return dp[a][b];
	
	return dp[a][b]=min(dpdp(a-1,b),dpdp(a,b-1))+dif[X][a][b];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	
	FOR(x,W-1) {
		for(int d=-(H-1);d<=H-1;d++) {
			r=0;
			FOR(y,H) {
				if(y-d>=0 && y-d<H) r += (S[y][x]==S[y-d][x+1]);
				if(y+1-d<=H && y+1-d>=0) dif[x][y+1][y+1-d]=r;
			}
		}
	}
	
	int ret=0;
	FOR(x,W-1) {
		MINUS(dp);
		X=x;
		ret+=dpdp(H,H);
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
