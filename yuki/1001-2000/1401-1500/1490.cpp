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

int H,W,N,M;
int T[202020],U[202020],L[202020],R[202020],A[202020];
ll S[2020][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>N>>M;
	FOR(i,N) {
		cin>>T[i]>>U[i]>>L[i]>>R[i]>>A[i];
	}
	FOR(i,M) {
		int b;
		cin>>y>>x>>b>>r;
		S[max(1,y-b)][max(1,x-b)]+=r;
		S[min(2010,y+b+1)][max(1,x-b)]-=r;
		S[max(1,y-b)][min(2010,x+b+1)]-=r;
		S[min(2010,y+b+1)][min(2010,x+b+1)]+=r;
	}
	FOR(y,H+2) FOR(x,W+2) {
		if(y) S[y][x]+=S[y-1][x];
		if(x) S[y][x]+=S[y][x-1];
		if(y&&x) S[y][x]-=S[y-1][x-1];
	}
	FOR(y,H+2) FOR(x,W+2) {
		if(y) S[y][x]+=S[y-1][x];
		if(x) S[y][x]+=S[y][x-1];
		if(y&&x) S[y][x]-=S[y-1][x-1];
	}
	
	int ret=0;
	FOR(i,N) {
		ll d=S[U[i]][R[i]]-S[T[i]-1][R[i]]-S[U[i]][L[i]-1]+S[T[i]-1][L[i]-1];
		if(d<A[i]) ret++;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
