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

int N,T,M;
ll mo=1000000009;
int D[1001];

ll dp[2][101][10001];

void solve() {
	int f,i,j,k,l,x,y;
	cin>>N>>T>>M;
	
	dp[0][0][0]=1;
	FOR(i,N) {
		int cur=i%2,tar=cur^1;
		cin>>D[i];
		memmove(dp[tar],dp[cur],sizeof(dp[cur]));
		for(x=N-1;x>=0;x--) for(y=T;y>=0;y--) {
			if(y+D[i]>T) continue;
			dp[tar][x+1][y+D[i]]=(dp[tar][x+1][y+D[i]]+dp[cur][x][y])%mo;
		}
	}
	
	ll ret=0;
	for(x=M;x<=N;x++) FOR(y,T+1) ret+=dp[N%2][x][y];
	cout << ret%mo << endl;
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


