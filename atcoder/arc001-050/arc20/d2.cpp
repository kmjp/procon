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
int D2[101][101];
ll mo=1000000007;
ll ret=0;

ll dpdp[12][12][4096][31];
ll dpdps[12][4096][31];
ll dpdpe[12][4096][31];


void dfs(int mask,int start,int cur,int tot) {
	int i;
	
	dpdp[start][cur][mask][tot%M]++;
	dpdps[start][mask][tot%M]++;
	dpdpe[cur][mask][tot%M]++;
	
	if(__builtin_popcount(mask)>=6) return;
	FOR(i,N) {
		if(mask & (1<<i)) continue;
		dfs(mask|(1<<i),start,i,tot+D2[cur][i]);
	}
}

void solve() {
	int f,i,j,k,l,x,y,mask,mask2;
	
	cin>>N>>M>>K;
	FOR(i,N-1) cin>>D[i];
	FOR(x,N) FOR(y,N) {
		if(x>y) D2[x][y]=D2[y][x];
		else {
			for(i=x;i<y;i++) D2[x][y]+=D[i];
		}
	}
	
	if(N>12) return;
	FOR(i,N) dfs(1<<i,i,i,0);
	
	
	
	if(K<=6) {
		FOR(i,N) FOR(j,N) if(i!=j) {
			FOR(mask,1<<N) if((mask&(1<<i))&&(mask&(1<<j))) {
				if(__builtin_popcount(mask)==K) ret+=dpdp[i][j][mask][0];
			}
		}
	}
	else {
		FOR(mask,1<<N) {
			if(__builtin_popcount(mask)!=6) continue;
			FOR(mask2,1<<N) {
				if(__builtin_popcount(mask2)!=K-5) continue;
				if(__builtin_popcount(mask2&mask)!=1) continue;
				FOR(i,N) if((1<<i)&mask&mask2) break;
				FOR(j,M) ret+=dpdps[i][mask2][j]*dpdpe[i][mask][(M-j)%M]%mo;
				ret%=mo;
			}
			
		}
	}
	
	
	
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


