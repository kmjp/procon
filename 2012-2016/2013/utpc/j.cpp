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

int N,M,K;
vector<pair<int,int> > E[100001],RE[100001];
ll D[100001];

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>x>>y>>j;
		E[x].push_back(make_pair(y,j));
		RE[y].push_back(make_pair(x,j));
	}
	FOR(i,N) D[i]=1LL<<50;
	D[0]=0;
	
	set<pair<ll,int> > S;
	S.insert(make_pair(0,0));
	j=0;
	while(!S.empty()) {
		pair<ll,int> k=*S.begin();
		j++;
		x=k.second;
		S.erase(S.begin());
		if(D[x]!=k.first) continue;
		
		FOR(i,RE[x].size()) {
			int tar=RE[x][i].first;
			if(D[tar]>D[x]+RE[x][i].second) {
				D[tar]=D[x]+RE[x][i].second;
				S.insert(make_pair(D[tar],tar));
			}
		}
	}
	
	priority_queue<pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll,int> > > Q;
	Q.push(make_pair(0,0));
	while(!Q.empty()) {
		ll co=Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		
		if(co > 0 && cur==0) {
			_P("%lld\n",co);
			if(--K==0) break;
		}
		
		FOR(i,E[cur].size()) {
			int tar=E[cur][i].first;
			Q.push(make_pair(co-D[cur]+E[cur][i].second+D[tar],tar));
		}
	}
	
	while(K--) _P("-1\n");
	
	
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


