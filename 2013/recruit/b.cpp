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

ll mo=1000000009;
ll dpdp[21][21][1025];

void solve() {
	int f,i,j,k,l,x,y,xx,rr,bb;
	int N,T;
	
	cin>>T;
	FOR(xx,T) {
		int R,B,Rn,Rk,Bn,Bk;
		cin>>R>>B>>Rn>>Rk>>Bn>>Bk;
		
		ZERO(dpdp);
		dpdp[0][0][0]=1;
		
		FOR(i,R+B) {
			FOR(rr,R+1) {
				bb=i-rr;
				if(bb<0 || bb>B) continue;
				
				int mask;
				FOR(mask,1<<9) {
					if(dpdp[rr][bb][mask]==0) continue;
					int rm=(1<<(min(Rn,i+1)))-1;
					int bm=(1<<(min(Bn,i+1)))-1;
					int nrm=((mask<<1)&511) | 1;
					int nbm=((mask<<1)&511) | 0;
					
					if(rr<R && __builtin_popcount(nrm&rm)<Rk) {
						dpdp[rr+1][bb][nrm] += dpdp[rr][bb][mask];
						dpdp[rr+1][bb][nrm] %= mo;
					}
					if(bb<B && __builtin_popcount((~nbm)&bm)<Bk) {
						dpdp[rr][bb+1][nbm] += dpdp[rr][bb][mask];
						dpdp[rr][bb+1][nbm] %= mo;
					}
				}
				
			}
		}
		
		ll re=0;
		FOR(i,512) re+=dpdp[R][B][i];
		cout << re%mo << endl;
	}
}


int main(int argc,char** argv){
	string s;
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


