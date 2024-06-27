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

int T,N;
vector<int> E[202020];
int C[2];
const int DI=600;

pair<vector<ll>,vector<ll>> dfs(int cur,int pre) {
	vector<ll> R[2];
	R[0].resize(1,1);
	R[1].resize(1,2);
	
	FORR(e,E[cur]) if(e!=pre) {
		auto P=dfs(e,cur);
		
		vector<ll> V[2],W[2];
		W[0]=P.first;
		W[1]=P.second;
		V[0].resize(min(DI,(int)R[0].size()+(int)W[0].size()),1LL<<60);
		V[1].resize(min(DI,(int)R[1].size()+(int)W[1].size()),1LL<<60);
		int i,j,l=V[0].size();
		FOR(i,2) {
			ll mi=*min_element(ALL(W[i^1]));
			FOR(j,R[i].size()) {
				chmin(V[i][j],mi+R[i][j]);
				for(int x=0;x<W[i].size()&&j+x+1<V[i].size();x++) chmin(V[i][j+x+1],W[i][x]+R[i][j]+(i+1)*(j+1)*(x+1));
			}
			
		}
		
		swap(V,R);
	}
	
	return {R[0],R[1]};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) E[i].clear();
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		
		ll sum=1LL*N*(N+1);
		auto p=dfs(0,0);
		ll mi=1LL<<60;
		FORR(a,p.first) mi=min(mi,a);
		FORR(a,p.second) mi=min(mi,a);
		cout<<sum-mi<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
