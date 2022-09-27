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


int H,W,K;
string S[1010101];
vector<ll> dp[1010101],ver[1010101],hol[1010101];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	if(H<=W) {
		FOR(y,H) cin>>S[y];
	}
	else {
		FOR(y,H) {
			cin>>s;
			FOR(x,W) S[x]+=s[x];
		}
		swap(H,W);
	}
	FOR(y,H+2) dp[y].resize(W+2000),ver[y].resize(W+2000),hol[y].resize(W+2000);
	
	dp[0][0]=1;
	if(S[0][0]=='#') dp[0][0]=0;
	ver[1][1]=hol[1][1]=dp[0][0];
	
	for(int sum=1;sum<=H+W-2;sum++) {
		ll cur=0;
		for(y=0;y<H;y++) {
			int x=sum-y;
			if(x<0) break;
			ver[y+1][x+1]=ver[y][x+1];
			hol[y+1][x+1]=hol[y+1][x];
			cur+=mo+hol[y+1][x+1]-hol[y+1][max(0,x-K)];
			cur=(cur%mo+mo)%mo;
			if(x<W&&S[y][x]=='.') dp[y][x]=cur;
			cur+=mo-(ver[y+1][x+1]-ver[max(0,y-K)][x+1]);
			cur=(cur%mo+mo)%mo;
			(ver[y+1][x+1]+=dp[y][x])%=mo;
			(hol[y+1][x+1]+=dp[y][x])%=mo;
			
		
		}
	}
	
	
	cout<<dp[H-1][W-1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
