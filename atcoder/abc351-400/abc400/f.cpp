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

int N,C[804],X[404];

unordered_map<int,ll> memo[408][408];

ll dfs(int L,int R,int s) {
	if(L>=R) return 0;
	if(L>=N) return dfs(L-N,R-N,s);
	if(memo[L][R-L].count(s)) return memo[L][R-L][s];
	
	ll ret=1LL<<60;
	
	if(s==N) {
		int c=C[L];
		for(int p=L;p<R;p++) if(C[p]==c) {
			ret=min(ret,dfs(L+1,p,c)+dfs(p+1,R,N)+X[c]+p-L+1);
		}
	}
	else {
		ret=dfs(L,R,N);
		for(int p=L;p<R;p++) if(C[p]==s) {
			ret=min(ret,dfs(L,p,N)+dfs(p+1,R,s));
		}
	}
	return memo[L][R-L][s]=ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N;
	FOR(i,N) {
		cin>>C[i];
		C[i]--;
		C[N+i]=C[i];
	}
	FOR(i,N) cin>>X[i];
	ll ret=1LL<<60;
	FOR(i,N) ret=min(ret,dfs(i,i+N,N));
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
