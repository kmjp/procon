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

int T,N;
int C[16][16];
string G[16],W[16];
int dp[1<<16][16];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		ZERO(C);
		FOR(i,N) {
			cin>>G[i]>>W[i];
			FOR(j,i) {
				if(G[i]==G[j]||W[i]==W[j]) {
					C[i][j]=C[j][i]=1;
				}
			}
		}
		int mask;
		FOR(mask,1<<N) FOR(i,N) dp[mask][i]=0;
		int ma=1;
		FOR(i,N) dp[1<<i][i]=1;
		FOR(mask,1<<N) FOR(i,N) if(dp[mask][i]) {
			ma=max(ma,__builtin_popcount(mask));
			FOR(j,N) if(C[i][j]&&(mask&(1<<j))==0) dp[mask|(1<<j)][j]=1;
		}
		cout<<N-ma<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
