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
int B[202020],W[202020];
ll A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	ll p=0;
	FOR(i,N) {
		cin>>B[i];
		if(B[i]>=0) p+=B[i];
	}
	sort(B,B+N);
	reverse(B,B+N);
	FOR(i,M) cin>>W[i];
	sort(W,W+M);
	reverse(W,W+M);
	ll ret=p;
	ll bs=0,ws=0;
	FOR(i,min(N,M)) {
		bs+=B[i];
		ws+=W[i];
		ll a=bs;
		if(B[i]>=0&&bs<p) a=p;
		ret=max(ret,ws+a);
		
	}
	cout<<ret<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
