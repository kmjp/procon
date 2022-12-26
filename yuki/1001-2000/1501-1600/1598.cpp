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

int K;
ll dp[1<<16][1000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	dp[0][500]=1;
	int mask;
	FOR(mask,1<<16) {
		k=__builtin_popcount(mask);
		FOR(j,1000) if(dp[mask][j]) {
			FOR(y,4) FOR(x,4) if((mask&(1<<(y*4+x)))==0) {
				int tar=j;
				if(y) {
					if((mask&(1<<((y-1)*4+x)))==0) tar-=k;
					else tar+=k;
				}
				if(y<3) {
					if((mask&(1<<((y+1)*4+x)))==0) tar-=k;
					else tar+=k;
				}
				if(x) {
					if((mask&(1<<(y*4+x-1)))==0) tar-=k;
					else tar+=k;
				}
				if(x<3) {
					if((mask&(1<<(y*4+x+1)))==0) tar-=k;
					else tar+=k;
				}
				dp[mask^(1<<(y*4+x))][tar]+=dp[mask][j];
			}
		}
	}
	
	cin>>K;
	cout<<dp[(1<<16)-1][500+K]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
