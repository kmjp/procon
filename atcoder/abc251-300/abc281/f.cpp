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
int A[151515];

pair<int,int> dfs(int L,int R,int d) {
	if(d<0) return {0,0};
	int M;
	for(M=L;M<R;M++) if(A[M]&(1<<d)) break;
	
	if(M==L) {
		auto p=dfs(L,R,d-1);
		p.second|=1<<d;
		return p;
	}
	if(M==R) {
		auto p=dfs(L,R,d-1);
		return p;
	}
	auto p=dfs(L,M,d-1);
	auto q=dfs(M,R,d-1);
	
	if(p.first<=q.first) {
		p.first|=1<<d;
		p.second|=1<<d;
		return p;
	}
	else {
		q.first|=1<<d;
		return q;
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	sort(A,A+N);
	auto p=dfs(0,N,29);
	cout<<p.first<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
