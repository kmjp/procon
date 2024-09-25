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

int N,M,K;
string S,T;
vector<pair<int,int>> dp[555][555];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	cin>>S>>T;
	FOR(i,N) {
		if(S[i]>='a'&&S[i]<='z') S[i]=S[i]-'a';
		if(S[i]>='A'&&S[i]<='Z') S[i]=S[i]-'A'+26;
		S[i]++;
	}
	FOR(i,M) {
		if(T[i]>='a'&&T[i]<='z') T[i]=T[i]-'a';
		if(T[i]>='A'&&T[i]<='Z') T[i]=T[i]-'A'+26;
		T[i]++;
	}
	dp[0][0].push_back({0,0});
	
	FOR(x,N+1) FOR(y,M+1) {
		sort(ALL(dp[x][y]));
		dp[x][y].erase(unique(ALL(dp[x][y])),dp[x][y].end());
		while(dp[x][y].size()&&dp[x][y].back().first>dp[x][y][0].first+K) dp[x][y].pop_back();
		FORR2(co,b,dp[x][y]) {
			if(x<N) {
				int s1=b%100;
				int s2=b/100%100;
				int s3=b/10000;
				if(K<=2) s3=0;
				if(K<=1) s2=0;
				if(K<=0) s1=0;
				int tco=co+1;
				while(s1==S[x]||s2==S[x]||s3==S[x]) {
					tco++;
					s3=s2;
					s2=s1;
					s1=0;
					if(K<=2) s3=0;
					if(K<=1) s2=0;
					if(K<=0) s1=0;
				}
				dp[x+1][y+(y<M&&S[x]==T[y])].push_back({tco,s2*10000+s1*100+S[x]});
			}
			if(y<M) {
				int s1=b%100;
				int s2=b/100%100;
				int s3=b/10000;
				if(K<=2) s3=0;
				if(K<=1) s2=0;
				if(K<=0) s1=0;
				int tco=co+1;
				while(s1==T[y]||s2==T[y]||s3==T[y]) {
					tco++;
					s3=s2;
					s2=s1;
					s1=0;
					if(K<=2) s3=0;
					if(K<=1) s2=0;
					if(K<=0) s1=0;
				}
				dp[x][y+1].push_back({tco,s2*10000+s1*100+T[y]});
			}
			
		}
		
	
	}
	
	cout<<dp[N][M][0].first<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
