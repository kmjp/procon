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

int N,X,Y;
int A[202020];
ll L[202020][3];
ll R[202020][3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Y;
	L[0][1]=L[0][2]=-1LL<<60;
	FOR(i,N) {
		cin>>A[i];
		L[i+1][0]=L[i][0]+A[i];
		L[i+1][1]=max(L[i][0]+X,L[i][1]+X);
		L[i+1][2]=max(L[i][1]+A[i],L[i][2]+A[i]);
	}
	R[N+1][1]=R[N+1][2]=-1LL<<60;
	for(i=N-1;i>=0;i--) {
		R[i+1][0]=R[i+2][0]+A[i];
		R[i+1][1]=max(R[i+2][0]+Y,R[i+2][1]+Y);
		R[i+1][2]=max(R[i+2][1]+A[i],R[i+2][2]+A[i]);
	}
	
	for(i=1;i<N-1;i++) {
		cout<<L[i+1][2]+R[i+1][2]-A[i]<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
