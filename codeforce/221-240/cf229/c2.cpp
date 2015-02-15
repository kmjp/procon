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

int N,K,W,L;
string S;
int sum[10][100010];
int sum2[100010];

void solve() {
	int f,i,j,k,l,x,y;

	cin>>N>>K>>W;
	cin>>S;
	L=S.size();
	FOR(i,L) {
		sum[i%K][1+i/K] = sum[i%K][i/K] + (S[i]=='1');
		sum2[i+1] = sum2[i] + (S[i]=='1');
	}
	
	FOR(i,W) {
		cin>>x>>y;
		x--;y--;
		int numc=sum2[y+1]-sum2[x];
		int tc = sum[y%K][1+y/K]-sum[y%K][(x+K-1)/K];
		int lc = numc-tc;
		_P("%d\n",lc + (y-x+1)/K - tc);
	}
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


