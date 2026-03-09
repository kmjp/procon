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

int N,K,B;
int C[1010],S[1010];

ll dp[51][501];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>B;
	vector<pair<int,int>> V;
	vector<int> Ss={0};
	FOR(i,N) {
		cin>>C[i]>>S[i];
		Ss.push_back(S[i]);
	}
	sort(ALL(Ss));
	
	FOR(x,K+1) FOR(y,N+1) dp[x][y]=1LL<<60;
	dp[0][0]=0;
	int ret=0;
	FOR(i,N) {
		S[i]=lower_bound(ALL(Ss),S[i])-Ss.begin();
		for(x=K-1;x>=0;x--) {
			FOR(y,S[i]) {
				dp[x+1][S[i]]=min(dp[x+1][S[i]],dp[x][y]+C[i]);
				if(dp[x+1][S[i]]<=B) ret=max(ret,x+1);
			}
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
