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

int N,M;
vector<pair<int,int> > E[2001];
int C[2001];
 
void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>x;
		E[i].push_back(make_pair(2*N,x));
		E[2*N].push_back(make_pair(i,0));
	}
	FOR(i,N) {
		cin>>x;
		E[N+i].push_back(make_pair(2*N,0));
		E[2*N].push_back(make_pair(N+i,x));
	}
	FOR(i,M) {
		cin>>x>>y>>j>>k;
		x--,y--;
		E[x].push_back(make_pair(N+y,k));
		E[N+y].push_back(make_pair(x,-j));
	}
	
	FOR(i,2001) C[i]=3000000;
	C[N*2]=0;
	bool up=true;
	while(up) {
		up=false;
		FOR(i,2*N+1) {
			FOR(j,E[i].size()) if(C[E[i][j].first] > C[i]+E[i][j].second) {
				up=true;
				C[E[i][j].first] = C[i]+E[i][j].second;
			}
		}
		if(C[2*N]<0) return _P("no\n");
	}
	_P("yes\n");
}
int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


