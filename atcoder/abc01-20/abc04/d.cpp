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


ll calc(int x,int num) {
	
	if(x<=-num) return (-x-x-num+1)*num/2;
	if(x>=0) return (x+x+num-1)*num/2;
	
	int y=x+num-1;
	x=-x;
	return (x+1)*x/2+(y+1)*y/2;
}

void solve() {
	int f,i,j,k,l;
	int R,G,B;
	cin>>R>>G>>B;
	
	ll mi=1LL<<50;
	int r,g,b;
	
	for(r=-500;r<=0;r++) {
		for(g=r+R;g<=600;g++) {
			for(b=max(-50,g+G);b<=500;b++) {
				mi=min(mi,calc(r+100,R)+calc(g,G)+calc(b-100,B));
			}
		}
	}
	_P("%lld\n",mi);
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


