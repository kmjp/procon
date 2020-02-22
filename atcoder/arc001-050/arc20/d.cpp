#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

int N,M,K;
int D[101];
ll mo=1000000007;
ll dp[101][1024][31];
ll ret=0;
int dm[1024];


void solve() {
	int f,i,j,k,l,x,y,mask,mask2;
	
	cin>>N>>M>>K;
	FOR(i,N-1) cin>>D[i];
	
	
	FOR(i,1024) FOR(x,K-1) dm[i]+=((i>>x)^(i>>(x+1)))&1;
	
	dp[0][0][0]=1;
	FOR(i,N) {
		FOR(mask,1<<K) {
			FOR(x,M) {
				dp[i+1][mask][(x+D[i]*dm[mask])%M] += dp[i][mask][x];
				dp[i+1][mask][(x+D[i]*dm[mask])%M] %= mo;
				FOR(j,K) {
					if((mask&(1<<j))==0) {
						mask2 = mask | (1<<j);
						dp[i+1][mask2][(x+D[i]*dm[mask2])%M] += dp[i][mask][x];
						dp[i+1][mask2][(x+D[i]*dm[mask2])%M] %= mo;
					}
				}
			}
		}
	}
	
	cout << dp[N][(1<<K)-1][0] << endl;
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


