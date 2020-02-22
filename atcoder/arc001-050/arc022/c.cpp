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
vector<int> E[100001];

int sx,sy;
int ma;

pair<int,int> dfs(int cur,int pre) {
	vector<pair<int,int> > V;
	int i;
	
	FOR(i,E[cur].size()) {
		int tar=E[cur][i];
		if(tar==pre) continue;
		V.push_back(dfs(tar,cur));
	}
	
	V.push_back(make_pair(1,cur));
	
	sort(V.begin(),V.end());
	reverse(V.begin(),V.end());
	if(V.size()>=2) {
		int tar=V[0].first+V[1].first;
		if(tar>ma) {
			ma=tar;
			sx=V[0].second+1;
			sy=V[1].second+1;
		}
	}
	
	return make_pair(V[0].first+1,V[0].second);
}

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	dfs(0,-1);
	_P("%d %d\n",sx,sy);
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


