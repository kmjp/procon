#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int H,W;
string S[404];
ll dp[808][404][404];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	dp[0][0][0]=1;
	FOR(i,H+W) {
		int y1,y2;
		FOR(y1,H) for(y2=y1;y2<H;y2++) {
			int x1=i-y1;
			int x2=i-y2;
			if(x1<0||x1>=W||x2<0||x2>=W) continue;
			if(y1==H-2&&x1==W-1&&y2==H-1&&x2==W-2) {
				cout<<dp[i][y1][y2]<<endl;
				return;
			}
			//RR
			if(i!=0&&x1+1<W&&x2+1<W&&S[y1][x1+1]=='.'&&S[y2][x2+1]=='.') (dp[i+1][y1][y2]+=dp[i][y1][y2])%=mo;
			//RD
			if(x1+1<W&&y2+1<H&&S[y1][x1+1]=='.'&&S[y2+1][x2]=='.') (dp[i+1][y1][y2+1]+=dp[i][y1][y2])%=mo;
			//DR
			if(i!=0&&y1+1<H&&x2+1<W&&S[y1+1][x1]=='.'&&S[y2][x2+1]=='.'&&y1+1!=y2) (dp[i+1][y1+1][y2]+=dp[i][y1][y2])%=mo;
			//DD
			if(i!=0&&y1+1<H&&y2+1<H&&S[y1+1][x1]=='.'&&S[y2+1][x2]=='.') (dp[i+1][y1+1][y2+1]+=dp[i][y1][y2])%=mo;
		}
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
