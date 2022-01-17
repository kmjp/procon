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

string V;
int N;
int need;

ll dp[10101][1024][2];
ll S[10101][1024][2];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>V;
	N=V.size();
	cin>>x;
	FOR(i,x) {
		cin>>y;
		need|=1<<y;
	}
	
	int mask;
	dp[0][0][1]=1;
	FOR(i,N) {
		FOR(mask,1<<10) {
			if(mask==0) {
				FOR(x,10) {
					if(x<V[i]-'0') {
						if(x==0) {
							(dp[i+1][0][0]+=dp[i][mask][1])%=mo;
							(S[i+1][0][0]+=S[i][mask][1]*10)%=mo;
						}
						else {
							(dp[i+1][1<<x][0]+=dp[i][mask][1])%=mo;
							(S[i+1][1<<x][0]+=S[i][mask][1]*10+x*dp[i][mask][1])%=mo;
						}
					}
					if(x==V[i]-'0') {
						if(x==0) {
							(dp[i+1][0][1]+=dp[i][mask][1])%=mo;
						}
						else {
							(dp[i+1][1<<x][1]+=dp[i][mask][1])%=mo;
							(S[i+1][1<<x][1]+=S[i][mask][1]*10+x*dp[i][mask][1])%=mo;
						}
					}
					if(x==0) {
						(dp[i+1][0][0]+=dp[i][mask][0])%=mo;
					}
					else {
						(dp[i+1][1<<x][0]+=dp[i][mask][0])%=mo;
						(S[i+1][1<<x][0]+=S[i][mask][0]*10+x*dp[i][mask][0])%=mo;
					}
				}
			}
			else {
				FOR(x,10) {
					if(x<V[i]-'0') {
						(dp[i+1][mask|1<<x][0]+=dp[i][mask][1])%=mo;
						(S[i+1][mask|1<<x][0]+=S[i][mask][1]*10+x*dp[i][mask][1])%=mo;
					}
					if(x==V[i]-'0') {
						(dp[i+1][mask|1<<x][1]+=dp[i][mask][1])%=mo;
						(S[i+1][mask|1<<x][1]+=S[i][mask][1]*10+x*dp[i][mask][1])%=mo;
					}
					(dp[i+1][mask|1<<x][0]+=dp[i][mask][0])%=mo;
						(S[i+1][mask|1<<x][0]+=S[i][mask][0]*10+x*dp[i][mask][0])%=mo;
				}
			}
		}
	}
	
	ll ret=0;
	FOR(mask,1<<10) if((mask&need)==need) ret+=S[N][mask][0]+S[N][mask][1];
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
