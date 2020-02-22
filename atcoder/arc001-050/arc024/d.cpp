#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
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
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int N;
int isis[1001][1001];
pair<int,int> P[1001];
set<pair<int,int> > S;

void dodo(int L,int R) {
	int p=(L+R)/2,i,x;
	if(L+1>=R) return;
	set<int> s;
	for(i=L;i<R;i++) s.insert(P[i].second);
	x = P[p].first;
	ITR(it,s) if(isis[x][*it]==0) isis[x][*it]=1, S.insert(make_pair(x,*it));
	dodo(L,p);
	dodo(p+1,R);
}

void solve() {
	int f,i,j,k,l,x,y;
	cin>>N;
	FOR(i,N) {
		cin>>P[i].first>>P[i].second;
		isis[P[i].first][P[i].second] = 1;
	}
	sort(P,P+N);
	dodo(0,N);
	
	_P("%d\n", S.size());
	ITR(it,S) _P("%d %d\n",it->first,it->second);
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


