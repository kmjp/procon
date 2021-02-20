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


int N,M,X,Y;
vector<vector<int>> E[101010];
ll D[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>X>>Y;
	X--,Y--;
	FOR(i,M) {
		cin>>x>>y>>r>>k;
		E[x-1].push_back({y-1,r,k});
		E[y-1].push_back({x-1,r,k});
	}
	FOR(i,N) D[i]=1LL<<60;
	D[X]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,X});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		if(cur==Y) {
			cout<<co<<endl;
			return;
		}
		if(D[cur]!=co) continue;
		FORR(e,E[cur]) {
			ll t=(co+e[2]-1)/e[2]*e[2]+e[1];
			if(t<D[e[0]]) {
				D[e[0]]=t;
				Q.push({-t,e[0]});
			}
		}
		
	}
	cout<<-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
