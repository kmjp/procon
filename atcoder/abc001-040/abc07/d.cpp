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

ll A,B;

ll ngng(ll v) {
	int d=0,i;
	ll vv=1;
	ll ld=1,ld2=1;
	if(v<=0) return 0;
	if(v==1000000000000000000) v--;
	
	while(vv*10<=v) d++,vv*=10;
	
	FOR(i,d) ld*=10,ld2*=8;
	ll ret=0;
	FOR(i,10) {
		if(i<v/vv) {
			if(i==4 || i==9) ret+=vv;
			else ret+=ld-ld2;
		}
	}
	if(v/vv==4 || v/vv==9) return ret+(v-(v/vv)*vv+1);
	return ret+ngng(v-(v/vv)*vv);
}

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>A>>B;
	cout << ngng(B)-ngng(A-1) << endl;
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


