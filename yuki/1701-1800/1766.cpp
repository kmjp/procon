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
ll dp[202020][3][3];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>s;
		S+=s;
	}
	FORR(c,S) {
		if(c=='.') c=2;
		if(c=='d') c=0;
		if(c=='k') c=1;
	}
	N*=16;
	
	dp[0][2][2]=1;
	FOR(i,N) {
		FOR(j,3) {
			if(S[i]!=2&&S[i]!=j) continue;
			FOR(x,3) {
				FOR(y,3) {
					if(i%2==1&&y==2&&(j!=2||x!=2)) continue;
					if(i&&S[i-1]==2&&S[i]!=2&&y==S[i]) continue;
					(dp[i+1][y][j]+=dp[i][x][y])%=mo;
				}
			}
		}
	}
	ll ret=0;
	FOR(i,3) FOR(j,3) ret+=dp[N][i][j];
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
