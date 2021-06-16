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
string S[2020];
int dp[2020][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	
	
	for(y=H-1;y>=0;y--) {
		for(x=W-1;x>=0;x--) {
			if(x==W-1&&y==H-1) continue;
			if((x+y)%2==0) {
				dp[y][x]=-10000;
				
				if(y+1<H) dp[y][x]=max(dp[y][x],dp[y+1][x]+(S[y+1][x]=='+'?1:-1));
				if(x+1<W) dp[y][x]=max(dp[y][x],dp[y][x+1]+(S[y][x+1]=='+'?1:-1));
				
			}
			else {
				dp[y][x]=10000;
				
				if(y+1<H) dp[y][x]=min(dp[y][x],dp[y+1][x]+(S[y+1][x]=='+'?-1:1));
				if(x+1<W) dp[y][x]=min(dp[y][x],dp[y][x+1]+(S[y][x+1]=='+'?-1:1));
			}
		}
	}
	
	if(dp[0][0]>0) {
		cout<<"Takahashi"<<endl;
	}
	else if(dp[0][0]==0) {
		cout<<"Draw"<<endl;
	}
	else cout<<"Aoki"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
