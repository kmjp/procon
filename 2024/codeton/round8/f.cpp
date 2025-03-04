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

int N,Q;
const int DI=500;
ll A[DI*DI+5];
ll V[DI+1],C[DI+1];

void build(int b) {
	int L=b*DI;
	int R=(b+1)*DI;
	
	ll cur=0;
	int i;
	for(i=L;i<R;i++) cur=floor(sqrtl(cur+A[i]));
	V[b]=cur;
	
	ll v=cur+1;
	for(i=R-1;i>=L;i--) {
		if(v>=(1LL<<31)) {
			C[b]=1LL<<62;
			return;
		}
		v=v*v-A[i];
	}
	C[b]=v;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>A[DI*DI-N+i];
	FOR(i,DI) build(i);
	
	while(Q--) {
		cin>>i;
		x=DI*DI-N+i-1;
		
		cin>>A[x];
		build(x/DI);
		
		ll cur=0;
		FOR(i,DI) cur=V[i]+(cur>=C[i]);
		cout<<cur<<endl;
		
	}
	
		
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
