#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,M;
int A[202020];
vector<pair<int,int>> E[202020];
ll dist[101010];
ll S[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	FOR(i,M) {
		cin>>x>>y>>k;
		E[x-1].push_back({y-1,k});
		E[y-1].push_back({x-1,k});
	}
	
	FOR(i,N) dist[i]=1LL<<60;
	dist[0]=0;
	S[0]=A[0];
	priority_queue<pair<ll,int>> Q;
	Q.push({0,0});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		if(dist[cur]!=co) continue;
		FORR2(e,c,E[cur]) {
			if(co+c==dist[e]) {
				S[e]=max(S[e],S[cur]+A[e]);
			}
			if(co+c<dist[e]) {
				S[e]=S[cur]+A[e];
				dist[e]=co+c;
				Q.push({-dist[e],e});
			}
			
		}
	}
	cout<<S[N-1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
