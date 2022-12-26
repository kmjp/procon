#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
int mat[16][16];
ll dp[1<<16];
ll p2[600];
ll p2r[600];
ll mo=1000000007;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=p2r[0]=1;
	p2[1]=2;
	p2r[1]=(mo+1)/2;
	for(i=2;i<=590;i++) p2[i]=p2[i-1]*p2[1]%mo,p2r[i]=p2r[i-1]*p2r[1]%mo;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		mat[x-1][y-1]=mat[y-1][x-1]=1;
	}
	
	dp[1]=dp[2]=1;
	for(int mask=3;mask<1<<N;mask++) {
		if((mask&3)==0 || (mask&3)==3) continue;
		dp[mask]=1;
		for(int smask=(mask-1)&mask; smask>0; smask=(smask-1)&mask) {
			if((smask&3)==0) continue;
			int oth=mask^smask;
			int num=0;
			FOR(x,N) if(smask&(1<<x)) {
				FOR(y,N) if(oth&(1<<y)) {
					num+=mat[x][y];
				}
			}
			dp[mask]+=mo-dp[smask]*p2r[num]%mo;
		}
		dp[mask]%=mo;
	}
	
	ll ret=1;
	for(int mask=0;mask<1<<N;mask++) if(mask&1) {
		int left=((1<<N)-1)^mask;
		for(int smask=left; smask>0; smask=(smask-1)&left) {
			if((smask&2)==0) continue;
			if(dp[mask]==0 || dp[smask]==0) continue;
			
			int num=0;
			FOR(x,N) if(mask&(1<<x)) {
				FOR(y,N) if(smask&(1<<y)) {
					num+=mat[x][y];
				}
			}
			if(num) continue;
			num=0;
			FOR(x,N) FOR(y,N) if(mat[x][y]) {
				if((mask&(1<<x)) && ((mask&(1<<y))==0)) num++;
				if((smask&(1<<x)) && ((smask&(1<<y))==0)) num++;
			}
			ret+=mo-dp[mask]*dp[smask]%mo*p2r[num]%mo;
		}
	}
	cout<<ret%mo*p2[M]%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
