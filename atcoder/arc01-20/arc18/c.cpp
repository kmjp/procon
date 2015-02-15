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
pair<int,int> P[1000000];

void solve() {
	int i,j,k,x,y,l;
	
	cin>>N>>M;
	cin>>x>>y>>l;
	y%=l;
	if(y==0) {
		if(x>=l) return _P("%d\n",2*(N-1));
		return _P("0\n");
	}
	FOR(i,N*M) P[i]=make_pair(x,i),x=(x+y)%l;
	sort(P,P+N*M);
	ll f=0;
	FOR(y,N) {
		vector<int> V;
		FOR(x,M) {
			int sy=P[y*M+x].second/M,sx=P[y*M+x].second%M;
			f += abs(sy-y);
			V.push_back(sx);
		}
		sort(V.begin(),V.end());
		FOR(x,M) f+=abs(x-V[x]);
	}
	cout << f << endl;
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


