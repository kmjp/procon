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

ll mo=1000000007;

ll comb(int P_,int Q_) {
	static const int N_=1020;
	static ll C_[N_][N_];
	
	if(C_[0][0]==0) {
		int i,j;
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j])%mo;
	}
	if(P_<0 || P_>N_ || Q_<0 || Q_>P_) return 0;
	return C_[P_][Q_];
}

void solve() {
	int f,i,j,k,l,x,y;
	int H,W,X,Y,D,L;
	
	cin>>H>>W;
	cin>>X>>Y;
	cin>>D>>L;
	
	ll res=(H-X+1)*(W-Y+1);
	res = res*comb(D+L,L) % mo;
	ll tm=0;
	for(int mask=0;mask<16;mask++) {
		x=X,y=Y;
		if(mask&1) x--;
		if(mask&2) x--;
		if(mask&4) y--;
		if(mask&8) y--;
		if(x<0 || y<0) continue;
		if(__builtin_popcount(mask)%2) tm-=comb(x*y,D+L);
		else tm+=comb(x*y,D+L);
	}
	tm=mo+(tm%mo);
	res=(res*(tm%mo))%mo;
	_P("%lld\n",res);
}


int main(int argc,char** argv){
	string s;
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


