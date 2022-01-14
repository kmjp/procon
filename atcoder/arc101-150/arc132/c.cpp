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


int N,D;
int A[505];
const ll mo=998244353;
ll dp[505][1<<10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D;
	dp[0][0]=1;
	FOR(i,N) {
		cin>>A[i];
		A[i]--;
		int mask;
		FOR(mask,1<<10) if(dp[i][mask]) {
			for(x=i-D;x<=i+D;x++) {
				if(x<0||x>=N) continue;
				if(A[i]!=-2&&x!=A[i]) continue;
				if(mask&(1<<(x-i+D))) continue;
				int nmask=mask|(1<<(x-i+D));
				(dp[i+1][nmask>>1]+=dp[i][mask])%=mo;
			}
		}
	}
	ll ret=0;
	FOR(i,1<<10) ret+=dp[N][i];
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
