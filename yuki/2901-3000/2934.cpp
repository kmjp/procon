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

__int128 dp[101010][170];
ll N,K;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>K;
	N=min(N,163LL);
	K++;
	FOR(i,N+1) dp[0][i]=1;
	FOR(i,101000) {
		FOR(x,N+1) FOR(y,10) if(x+y<=N) dp[i+1][x+y]+=dp[i][x];
		__int128 sum=dp[i+1][N];
		if(sum>=K) {
			int cur=i+1;
			while(cur>0) {
				FOR(x,10) {
					if(dp[cur-1][N-x]>=K) {
						cout<<x;
						N-=x;
						break;
					}
					else {
						K-=dp[cur-1][N-x];
					}
				}
				cur--;
			}
			cout<<endl;
			return;
		}
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
