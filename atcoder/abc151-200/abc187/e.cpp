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
vector<int> E[202020];
int L[202020],R[202020];
int D[202020];
int id;
ll S[202020],TS;
int A[202020],B[202020];
int Q;

void dfs(int cur,int pre=-1) {
	if(pre>=0) D[cur]=D[pre]+1;
	L[cur]=id++;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur);
	R[cur]=id;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>A[i]>>B[i];
		E[A[i]].push_back(B[i]);
		E[B[i]].push_back(A[i]);
	}
	
	dfs(1);
	
	cin>>Q;
	while(Q--) {
		int T,E,X;
		cin>>T>>E>>X;
		x=A[E-1];
		y=B[E-1];
		if(T==1&&D[x]<D[y]) {
			TS+=X;
			S[L[y]]+=-X;
			S[R[y]]-=-X;
		}
		if(T==1&&D[x]>D[y]) {
			S[L[x]]+=X;
			S[R[x]]-=X;
		}
		if(T==2&&D[x]<D[y]) {
			S[L[y]]+=X;
			S[R[y]]-=X;
		}
		if(T==2&&D[x]>D[y]) {
			TS+=X;
			S[L[x]]+=-X;
			S[R[x]]-=-X;
		}
	}
	
	FOR(i,N) S[i+1]+=S[i];
	FOR(i,N) cout<<TS+S[L[i+1]]<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
