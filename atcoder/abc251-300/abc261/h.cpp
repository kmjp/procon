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


int N,M,V;
vector<pair<int,int>> E[202020];
int in[202020];
ll X[202020],Y[202020];
int vis[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>V;
	V--;
	FOR(i,N) X[i]=1LL<<60, Y[i]=0;
	
	FOR(i,M) {
		cin>>x>>y>>k;
		x--,y--;
		E[y].push_back({x,k});
		in[x]++;
	}
	priority_queue<pair<ll,int>> Q;
	FOR(i,N) if(in[i]==0) {
		X[i]=Y[i]=0;
		Q.push({0,i});
		FORR2(e2,v2,E[i]) {
			if(chmin(X[e2],Y[i]+v2)) Q.push({-X[e2],e2});
		}
	}
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		if(co!=X[cur]) continue;
		FORR2(e,v,E[cur]) {
			Y[e]=max(Y[e],X[cur]+v);
			if(--in[e]==0) {
				FORR2(e2,v2,E[e]) {
					if(chmin(X[e2],Y[e]+v2)) {
						Q.push({-X[e2],e2});
					}
				}
			}
		}
	}
	
	if(X[V]>1LL<<50) {
		cout<<"INFINITY"<<endl;
	}
	else {
		cout<<X[V]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
