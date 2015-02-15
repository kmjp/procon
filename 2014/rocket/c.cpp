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
#include <numeric>
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

int N,K;
pair<int,int> P[200001];
int E[200001];

ll dodo(int target) {
	int lose=0,win=0,oth=0;
	int i;
	vector<ll> V1,V2;
	
	FOR(i,N) {
		if(P[i].first>target) lose++,V1.push_back(P[i].second);
		else if(P[i].first+1<target) win++,V1.push_back(P[i].second);
		else oth++,V2.push_back(P[i].second);
	}
	int mwin=N-K-win;
	
	V1.push_back(0);
	V2.push_back(0);
	sort(V1.begin(),V1.end());
	sort(V2.begin(),V2.end());
	partial_sum(V1.begin(), V1.end(), V1.begin());
	partial_sum(V2.begin(), V2.end(), V2.begin());
	
	ll mi=1LL<<50;
	for(int x=0;x<V1.size();x++) {
		int y = target - x;
		if(y<mwin) y=mwin;
		if(y>=V2.size()) continue;
		mi = min(mi,V1[x]+V2[y]);
	}
	return mi;
}
ll dodo2(int target) {
	int i;
	vector<ll> V;
	FOR(i,N) V.push_back(P[i].second);
	V.push_back(0);
	sort(V.begin(),V.end());
	partial_sum(V.begin(), V.end(), V.begin());
	if(target>=V.size()) return 1LL<<50;
	return V[target];
	
}

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>N>>K;
	K--;
	if(K==N) return _P("0\n");
	FOR(i,N) cin>>P[i].first>>P[i].second;
	sort(P,P+N);
	reverse(P,P+N);
	
	ll tot=min(dodo(P[K].first),dodo(P[K].first+1));
	tot=min(tot,dodo2(P[K].first+2));
	if(tot>=1LL<<50) tot=-1;
	cout << tot << endl;
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


