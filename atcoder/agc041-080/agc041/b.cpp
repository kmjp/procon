#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


int N,V,P;
ll M;
ll A[101010];
ll B[101010];

int ok(int cur) {
	int i;
	if(cur<0) return 0;
	if(N-cur<=P) return 1;
	if(V<=P) {
		return (A[cur]+M>=A[N-P]);
	}
	else {
		int NN=N-(P-1);
		int NV=V-P;
		ll cand=A[cur]+M;
		vector<ll> B;
		ll dif=0;
		FOR(i,NN) if(i!=cur) {
			if(A[i]>cand) return 0;
			if(A[i]+M<=cand) {
				NV--;
			}
			else {
				dif+=cand-A[i];
			}
		}
		return (1LL*NV*M<=dif);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>V>>P;
	FOR(i,N) cin>>A[i];
	int ret=N-1;
	sort(A,A+N);
	for(i=20;i>=0;i--) if(ok(ret-(1<<i))) ret-=1<<i;
	
	cout<<N-ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
