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
int S,G;
vector<pair<int,int> > E[30001];
int dist[2][30001];
int cost[2][30001];
int X[102],F[102];

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>N>>M>>K;
	cin>>S>>G;
	FOR(i,M) {
		cin>>x>>y>>j;
		E[x].push_back(make_pair(y,j));
		E[y].push_back(make_pair(x,j));
	}
	FOR(i,K) cin>>X[i]>>F[i];
	X[K]=(1<<30)+1;
	K++;
	
	FOR(i,2) {
		FOR(j,N) dist[i][j]=1<<30;
		set<pair<int,int> > Q;
		if(i==0) dist[0][S]=0,Q.insert(make_pair(0,S));
		if(i==1) dist[1][G]=0,Q.insert(make_pair(0,G));
		
		while(!Q.empty()) {
			int co=Q.begin()->first;
			int cur=Q.begin()->second;
			Q.erase(Q.begin());
			if(co!=dist[i][cur]) continue;
			
			FOR(j,E[cur].size()) {
				int tar=E[cur][j].first;
				if(dist[i][tar]<=co+E[cur][j].second) continue;
				dist[i][tar] = co+E[cur][j].second;
				Q.insert(make_pair(dist[i][tar],tar));
			}
		}
		
		FOR(j,N) {
			FOR(k,K) if(dist[i][j]<X[k+1]) break;
			cost[i][j]=F[k];
		}
	}
	
	int mi=cost[0][G];
	FOR(j,N) mi=min(mi,cost[0][j]+cost[1][j]);
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


