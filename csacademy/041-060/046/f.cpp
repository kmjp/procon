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


int H,W,R1,R2;
string S[1010];
ll mo=1000000007;
ll dp[1010][1010][5]; //U,D,UR,DR,RR
int D;
ll r2=(mo+1)/2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>R1>>R2;
	R1--,R2--;
	FOR(y,H) cin>>S[y];
	
	if(S[R1][0]=='1') return _P("0\n");
	if(S[R2][W-1]=='1') return _P("0\n");
	S[R1][0]='0';
	S[R2][W-1]='0';
	FOR(y,H) S[y]="1"+S[y];
	W+=1;
	S[R1][0]='0';
	
	FOR(y,H) FOR(x,W) if(S[y][x]=='?') D++;
	
	dp[R1][0][4]=1;
	FOR(x,W) {
		// go down
		FOR(y,H-1) if(S[y+1][x]!='1') {
			ll p=1;
			if(x<W-1 && S[y][x+1]=='0') continue;
			if(x<W-1 && S[y][x+1]=='?') p=p*r2%mo;
			if(S[y+1][x]=='?') p=p*r2%mo;
			(dp[y+1][x][1]+=p*(dp[y][x][1]+dp[y][x][3]))%=mo;
			if(y&&S[y-1][x]=='0') continue;
			if(y&&S[y-1][x]=='?') p=p*r2%mo;
			(dp[y+1][x][1]+=p*(dp[y][x][2]+dp[y][x][4]))%=mo;
		}
		// go up
		for(y=H-1;y>=1;y--) if(S[y-1][x]!='1') {
			ll p=1;
			if(S[y-1][x]=='?') p=r2;
			(dp[y-1][x][0]+=p*(dp[y][x][0]+dp[y][x][2]+dp[y][x][4]))%=mo;
		}
		// go right
		FOR(y,H) if(x<W-1 && S[y][x+1]!='1') {
			ll p=1;
			if(S[y][x+1]=='?') p=p*r2%mo;
			
			(dp[y][x+1][3]+=p*dp[y][x][1])%=mo;
			(dp[y][x+1][4]+=p*dp[y][x][3])%=mo;
			
			if(y&&S[y-1][x]=='0') continue;
			if(y&&S[y-1][x]=='?') p=p*r2%mo;
			(dp[y][x+1][2]+=p*dp[y][x][0])%=mo;
			(dp[y][x+1][4]+=p*(dp[y][x][2]+dp[y][x][4]))%=mo;
		}
	}
	
	ll a=(dp[R2][W-1][0]+dp[R2][W-1][1]+dp[R2][W-1][2]+dp[R2][W-1][3]+dp[R2][W-1][4]);
	while(D--) a=a*2%mo;
	
	cout<<a%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
