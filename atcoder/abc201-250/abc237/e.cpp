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
int H[202020];
vector<int> E[202020];
ll D[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>H[i];
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,N) D[i]=-1LL<<60;
	D[0]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,0});
	while(Q.size()) {
		ll co=Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		if(co!=D[cur]) continue;
		FORR(e,E[cur]) {
			ll aco=(H[e]>H[cur])?2*(H[cur]-H[e]):((H[cur]-H[e]));
			if(D[e]<co+aco) {
				D[e]=co+aco;
				Q.push({D[e],e});
			}
		}
	}
	cout<<*max_element(D,D+N)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
