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

int H,W;
string S[101];
int SY,SX;
int dp[101][101][101][101];
int sum[105][105];

int range(int L,int R,int T,int B) {
	if(L>R || T>B) return 0;
	if(L>=W || R<0 || T>=H || B<0) return 0;
	return sum[B+1][R+1]-sum[T][R+1]-sum[B+1][L]+sum[T][L];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			if(S[y][x]=='E') S[y][x]='.', SY=y,SX=x;
			if(S[y][x]=='o') sum[y+1][x+1]=1;
			sum[y+1][x+1] += sum[y][x+1] + sum[y+1][x] - sum[y][x];
		}
	}
	
	int L,R,U,D;
	for(L=0;SX-L>=0;L++) for(R=0;SX+R<W;R++) for(U=0;SY-U>=0;U++) for(D=0;SY+D<H;D++) {
		int& ret=dp[L][R][U][D];
		//_P("%d %d %d %d : %d\n",L,R,U,D,ret);
		int AL=max(SX-L,R);
		int AR=min(SX+R,W-1-L);
		int AT=max(SY-U,D);
		int AB=min(SY+D,H-1-U);
		
		dp[L][R+1][U][D]=max(dp[L][R+1][U][D], ret+((AR+1<W-L)?range(AR+1,AR+1,AT,AB):0));
		dp[L+1][R][U][D]=max(dp[L+1][R][U][D], ret+((R+1<=AL)?range(AL-1,AL-1,AT,AB):0));
		dp[L][R][U][D+1]=max(dp[L][R][U][D+1], ret+((AB+1<H-U)?range(AL,AR,AB+1,AB+1):0));
		dp[L][R][U+1][D]=max(dp[L][R][U+1][D], ret+((D+1<=AT)?range(AL,AR,AT-1,AT-1):0));
	}
	
	cout<<dp[SX][W-1-SX][SY][H-1-SY]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
