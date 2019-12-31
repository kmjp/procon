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

void solve() {
	int f,i,j,k,l,x,y,loop;
	int T;
	cin>>T;
	FOR(loop,T) {
		ll X,P;
		ll mp[32];
		scanf("%lld%lld",&P,&X);
		
		if(X==0) {
			_P("0\n");
			continue;
		}
		if(P==2) {
			_P("%lld\n",(1LL<<X)-1);
			continue;
		}
		
		
		mp[1]=P;
		for(i=1;i<30;i++) mp[i+1]=mp[i]*P;
		
		ll num=0;
		int mo=0;
		int inc=0;
		for(ll cur=1;cur<1LL<<30;cur++) {
			mo++;
			if(mo==P) {
				for(i=1;i<=30;i++) {
					if(mp[i]>cur) break;
					if((cur % mp[i])==0) num++;
				}
				mo=0;
			}
			if(cur-num==X) {
				_P("%lld\n",cur);
				break;
			}
		}
		
	}
}


int main(int argc,char** argv){
	string s;
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


