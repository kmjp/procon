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

int N,K;
string S;
int A[1<<20];
int C[1<<20];

double V[1<<20];
double W[1<<20];

int can(double r) {
	int i;
	FOR(i,N) {
		V[i+1]=V[i];
		if(S[i]=='o') V[i+1]+=(1-r);
		else V[i+1]-=r;
	}
	W[N]=V[N];
	for(i=N-1;i>=0;i--) W[i]=max(W[i+1],V[i]);
	FOR(i,N) if(C[i]>i&&W[C[i]]-V[i]>=0) return 1;
	return 0;
}






void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	FOR(i,N) {
		A[i+1]=A[i];
		if(S[i]=='o') A[i+1]++;
	}
	
	for(int L=0,R=0;L<N;L++) {
		while(R<N&&A[R]-A[L]<K) R++;
		if(A[R]-A[L]<K) {
			C[L]=-1;
		}
		else {
			C[L]=R;
		}
	}
	double L=0,R=1;
	FOR(i,100) {
		double M=(L+R)/2;
		if(can(M)) {
			L=M;
		}
		else {
			R=M;
		}
	}
	_P("%.12lf\n",L);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
