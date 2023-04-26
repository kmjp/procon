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

int N;
string S;
const ll mo=998244353;

int nex[102][26];
ll dp[102][102];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	
	FOR(i,26) nex[N][i]=N;
	for(i=N-1;i>=0;i--) {
		FOR(j,26) nex[i][j]=nex[i+1][j];
		nex[i][S[i]-'a']=i;
	}
	
	ll ret=0;
	FOR(i,26) {
		int s=nex[0][i];
		for(y=s+1;y<N;y++) if(S[s]==S[y]) {
			ZERO(dp);
			dp[s+1][y+1]=1;
			int a,b;
			for(a=s+1;a<=y;a++) for(b=y+1;b<=N;b++) if(dp[a][b]) {
				if(nex[a][i]==y) ret+=dp[a][b];
				FOR(j,26) {
					int na=nex[a][j]+1;
					int nb=nex[b][j]+1;
					(dp[na][nb]+=dp[a][b])%=mo;
				}
			}
		}
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
