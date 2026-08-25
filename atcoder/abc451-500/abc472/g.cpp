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
string S[33];


int id[30][30];
int num[30];
int sum[30][30];

int dp[30][1<<15];
int mask2[30][30];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int mask;
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		int cur=-1;
		FOR(x,W) if(S[y][x]!='#') {
			if(x==0||S[y][x-1]=='#') cur++;
			id[y][x]=cur;
			if(S[y][x]=='+') sum[y][cur]++;
			if(S[y][x]=='-') sum[y][cur]--;
		}
		num[y]=cur+1;
	}
	
	int ma=0;
	for(y=H-1;y>=0;y--) {
		if(y!=H-1) {
			FOR(x,W) if(S[y][x]!='#'&&S[y+1][x]!='#') mask2[y][id[y][x]]|=1<<id[y+1][x];
		}
		FOR(mask,1<<num[y]) {
			int m2=0;
			FOR(i,num[y]) {
				if((mask&(1<<i))==0) dp[y][mask]+=sum[y][i];
				else m2|=mask2[y][i];
			}
			if(y!=H-1) dp[y][mask]+=dp[y+1][m2];
			if(y==0) ma=max(ma,dp[y][mask]);
		}
		FOR(i,num[y]) FOR(mask,1<<num[y]) dp[y][mask]=max(dp[y][mask],dp[y][mask|(1<<i)]);
	}
	
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
