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

int N;
ll A[10001],D[10001],L[10001],S[10001];
ll RD[12];
ll B;

ll calc(ll dig,ll momo) {
	ll v=1;
	ll cur=10;
	while(dig) {
		if(dig%2) v=(v*cur)%momo;
		cur=(cur*cur)%momo;
		dig>>=1;
	}
	return v;
}

ll rev(ll num, ll momo) {
	ll pw = momo-2;
	ll ret = 1;
	for(ll i = 30; i >= 0; i--) {
		ret = (ret*ret)%momo;
		if((pw>>i)&1) ret = (ret*num)%momo;
	}
	return ret;
}

ll calc2(ll D,ll L,ll B) {
	if(L<=1) return L;
	if(L==1) return 1;
	
	ll vv = calc2(D,L/2,B)*(1+calc(D*(L/2),B))%B;
	if(L%2) vv=(vv+calc(D*(L-1),B))%B;
	return vv;
}

void solve() {
	int f,i,j,k,l,x,y;
	cin>>N;
	FOR(i,N) cin>>A[i]>>L[i];
	cin>>B;
	FOR(i,N) {
		ll hoge=A[i];
		while(hoge) D[i]++,hoge/=10;
	}
	
	ll cc=9;
	for(i=1;i<=11;i++) RD[i]=rev(cc,B),cc=cc*10+9;
	
	for(i=N-2;i>=0;i--) S[i]=S[i+1]+L[i+1]*D[i+1];
	ll ret=0;
	FOR(i,N) ret+=calc2(D[i],L[i],B)*calc(S[i],B)%B*A[i]%B;
	cout << ret%B << endl;
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


