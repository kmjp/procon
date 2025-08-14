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

int N;
ll M;
ll T[10101][101];
ll A[101][101];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>T[0][i];
	FOR(y,N) FOR(x,N) cin>>A[y][x];
	
	map<vector<ll>,int> memo;
	
	FOR(i,10101) {
		FOR(y,N) FOR(x,N) T[i+1][x]=max(T[i+1][x],T[i][y]+A[y][x]);
		
		if(i+1==M) {
			FOR(x,N) cout<<T[i+1][x]<<" ";
			cout<<endl;
			return;
		}
		
		vector<ll> V;
		FOR(x,N) V.push_back(T[i+1][x]-T[i+1][0]);
		if(memo.count(V)) {
			int a=memo[V];
			int cur=i+1;
			ll loop=(M-a)/(cur-a);
			ll add=(T[cur][0]-T[a][0])*loop;
			int dif=(M-a)%(cur-a)+a;
			FOR(x,N) cout<<T[dif][x]+add<<" ";
			cout<<endl;
			return;
		}
		memo[V]=i+1;
		
	}
	assert(0);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
