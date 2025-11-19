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
vector<pair<int,int>> E[101010];
ll D[101010][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>k;
		E[x-1].push_back({y-1,k});
		E[y-1].push_back({x-1,k});
	}
	FOR(i,N) D[i][0]=D[i][1]=1LL<<60;
	priority_queue<pair<ll,int>> Q;
	D[0][0]=D[N-1][1]=0;
	Q.push({0LL,0});
	Q.push({0LL,(N-1)*2+1});
	while(Q.size()) {
		int cur=Q.top().second/2;
		int id=Q.top().second%2;
		ll co=-Q.top().first;
		Q.pop();
		if(D[cur][id]!=co) continue;
		FORR2(e,c,E[cur]) if(chmin(D[e][id],co+c)) {
			Q.push({-D[e][id],e*2+id});
		}
	}
	int ret=0;
	FOR(i,N) if(D[i][0]+D[i][1]==D[N-1][0]) ret++;
	cout<<ret<<endl;
		
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
