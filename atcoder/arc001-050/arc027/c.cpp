#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
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
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int X,Y,N;
int T[400],H[400];
pair<double,int> P[400];
ll dp[402][402];

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>X>>Y>>N;
	FOR(i,N) cin>>T[i]>>H[i];
	FOR(x,401) FOR(y,401) dp[x][y]=-1;
	dp[X][Y]=0;
	ll ret=0;
	FOR(i,N) {
		FOR(x,401) FOR(y,401) if(dp[x][y]>=0) {
			int dy=min(T[i]-1,y);
			int dx=max(1,T[i]-dy);
			if(y>=dy && x>=dx) {
				dp[x-dx][y-dy]=max(dp[x-dx][y-dy],dp[x][y]+H[i]);
				ret=max(ret,dp[x-dx][y-dy]);
			}
		}
	}
	cout << ret << endl;
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


