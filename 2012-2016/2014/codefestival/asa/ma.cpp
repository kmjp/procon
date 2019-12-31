#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
int S,T;
vector<pair<int,int> > E[1001];
int dist[2][1001];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	cin>>S>>T;
	if(S==T) return _P("%d\n",S);
	
	S--,T--;
	FOR(i,M) {
		cin>>x>>y>>r;
		x--,y--;
		E[x].push_back(make_pair(r,y));
		E[y].push_back(make_pair(r,x));
	}
	
	FOR(i,N) dist[0][i]=dist[1][i]=1<<30;
	priority_queue<pair<int,int> > Q;
	dist[0][S]=dist[1][T]=0;
	Q.push(make_pair(0,S));
	Q.push(make_pair(0,10000+T));

	while(Q.size()) {
		pair<int,int> p=Q.top();
		Q.pop();
		int type=p.second/10000;
		int cur=p.second%10000;
		if(p.first != -dist[type][cur]) continue;
		
		FOR(i,E[cur].size()) {
			int tar=E[cur][i].second;
			if(dist[type][tar] > E[cur][i].first + dist[type][cur]) {
				dist[type][tar] = E[cur][i].first + dist[type][cur];
				Q.push(make_pair(-dist[type][tar],type*10000+tar));
			}
		}
	}
	FOR(i,N) if(dist[0][i]==dist[1][i] && dist[0][i]<1<<30) return _P("%d\n",i+1);
	_P("-1\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
