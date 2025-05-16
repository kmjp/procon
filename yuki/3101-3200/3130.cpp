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
int A[202020];
int C[3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	sort(A,A+N);
	FOR(i,N) {
		cin>>s;
		if(s=="max") C[0]++;
		if(s=="min") C[1]++;
		if(s=="add") C[2]++;
	}
	
	if(C[0]==N) {
		cout<<A[N-1]<<endl;
		return;
	}
	if(C[1]==N) {
		cout<<0<<endl;
		return;
	}
	if(C[2]==N) {
		ll ret=0;
		FOR(i,N) ret+=A[i];
		cout<<ret<<endl;
		return;
	}
	if(C[2]==0) {
		cout<<A[C[0]-1]<<endl;
		return;
	}
	ll a=0,b=0;
	FOR(i,C[2]-1) a+=A[i];
	a+=A[C[2]+C[0]-1];
	if(C[1]==0) b=1LL<<60;
	else b=A[C[0]+C[2]];
	cout<<min(a,b)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
