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
int A[1010101];
ll S[1010101];
ll W,B[20],C[20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>W;
	FOR(i,N) cin>>A[i];
	sort(A,A+N);
	reverse(A,A+N);
	FOR(i,N) S[i+1]=S[i]+A[i];
	
	ll ret=0;
	FOR(i,M) cin>>B[i];
	FOR(i,M) cin>>C[i];
	int mask;
	FOR(mask,1<<M) {
		ll w=0,v=0;
		FOR(i,M) if(mask&(1<<i)) w+=B[i], v+=C[i];
		if(w<=W) ret=max(ret,v+S[min(W-w,(ll)N)]);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
