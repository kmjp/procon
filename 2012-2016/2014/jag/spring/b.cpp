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

ll X,Y,Z,A,B,C,N;
ll ret[1010];

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>X>>Y>>Z>>A>>B>>C>>N;
	if(A>=N) {
		FOR(i,N) ret[i]+=Y*Z*(A/N);
		X-=A/N*N;
		A-=A/N*N;
	}
	if(X-A>N) {
		FOR(i,N) ret[i]+=Y*Z*((X-A)/N);
		X-=(X-A)/N*N;
	}
	if(B>=N) {
		FOR(i,N) ret[i]+=X*Z*(B/N);
		Y-=B/N*N;
		B-=B/N*N;
	}
	if(Y-B>N) {
		FOR(i,N) ret[i]+=X*Z*((Y-B)/N);
		Y-=(Y-B)/N*N;
	}
	if(C>=N) {
		FOR(i,N) ret[i]+=X*Y*(C/N);
		Z-=C/N*N;
		C-=C/N*N;
	}
	if(Z-C>N) {
		FOR(i,N) ret[i]+=X*Y*((Z-C)/N);
		Z-=(Z-C)/N*N;
	}
	
	int num[1010]={};
	FOR(x,X) FOR(y,Y) {
		int d=abs(x-A)+abs(y-B);
		num[d%N]++;
	}
	FOR(z,Z) {
		int d=abs(z-C);
		FOR(i,N) ret[(i+d)%N]+=num[i];
	}
	FOR(i,N) {
		if(i) cout<<" ";
		cout<<ret[i];
	}
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
