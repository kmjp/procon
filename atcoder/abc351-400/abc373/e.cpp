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
ll K,A[202020],B[202020],S[202020];

int ok(ll A,int x,ll V) {
	if(V<0) return 0;
	if(M==N) return 1;
	ll D=K-V;
	if(x<N-M) {
		if(A+V<B[N-M]) return 0;
		int y=lower_bound(B,B+N,A+V+1)-B;
		int num=y-(N-M);
		ll s=S[y]-S[N-M];
		return (D<num*(A+V+1)-s);
	}
	else {
		int y=lower_bound(B,B+N,A+V+1)-B;
		int num=y-(N-M);
		ll s=S[y]-S[N-M-1]-A;
		return (D<num*(A+V+1)-s);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,N) {
		cin>>A[i];
		B[i]=A[i];
		K-=A[i];
	}
	sort(B,B+N);
	FOR(i,N) S[i+1]=S[i]+B[i];
	FOR(i,N) {
		x=lower_bound(B,B+N,A[i])-B;
		if(ok(A[i],x,K)==0) {
			cout<<-1<<" ";
			continue;
		}
		
		if(ok(A[i],x,0)) {
			cout<<0<<" ";
			continue;
		}
		ll v=K;
		for(j=40;j>=0;j--) if(ok(A[i],x,v-(1LL<<j))) v-=1LL<<j;
		cout<<v<<" ";
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
