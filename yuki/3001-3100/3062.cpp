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
int A[3030];
int C[3030];
int B[3030];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	x=-1;
	FOR(i,N) {
		cin>>A[i];
		A[i]--;
		if(A[i]==N-1) x=i;
	}
	if(x==-1) {
		cout<<0<<endl;
		return;
	}
	rotate(A,A+x,A+N);
	FOR(i,N) B[i]=N;
	FOR(i,N) {
		FOR(j,N) if(A[j]==N-1) {
			B[i]=min(B[i],A[(i+j)%N]);
		}
	}
	ll ret=N;
	for(i=N-2;i>=0;i--) {
		int cand=0;
		ZERO(C);
		FOR(j,N) if(A[j]==i) {
			cand++;
			FOR(k,N) if(A[k]==N-1) C[(j-k+N)%N]++;
		}
		if(cand) {
			x=0;
			FOR(j,N) if(C[j]==cand&&B[j]>=i) x++;
			ret=ret*x%mo;
		}
		else {
			FOR(j,N) if(B[j]>=i) cand++;
			ret=ret*(cand-(N-1-i))%mo;
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
