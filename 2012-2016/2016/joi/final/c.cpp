#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M,Q;
int U[202020],V[202020],Y[202020];
vector<pair<int,int>> E[101010];

int dist[101010],year[101010];
int sum[401010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(i,M) {
		cin>>U[i]>>V[i];
		U[i]--;
		V[i]--;
		Y[i]=303030;
	}
	FOR(i,Q) {
		cin>>x;
		Y[x-1]=i+1;
	}
	FOR(i,M) {
		E[U[i]].push_back({V[i],Y[i]});
		E[V[i]].push_back({U[i],Y[i]});
	}
	FOR(i,N) dist[i]=303030, year[i]=0;
	queue<int> QQ;
	dist[0]=0;
	year[0]=303030;
	QQ.push(0);
	while(QQ.size()) {
		int cur=QQ.front();
		QQ.pop();
		sum[year[cur]]++;
		FORR(e,E[cur]) {
			if(dist[e.first]>dist[cur]+1) {
				dist[e.first]=dist[cur]+1;
				QQ.push(e.first);
			}
			if(dist[e.first]==dist[cur]+1) year[e.first]=max(year[e.first], min(year[cur],e.second));
		}
	}
	FOR(i,Q) {
		sum[i+1]+=sum[i];
		cout<<sum[i+1]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
