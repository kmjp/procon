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

int N,Q;
string S;
string A[202020],B[202020];

int outL(int cur) {
	if(cur>=N) return 0;
	int i;
	FOR(i,Q) {
		if(S[cur]==A[i][0]) {
			if(B[i]=="L") cur--;
			if(B[i]=="R") cur++;
		}
		if(cur<0) return 1;
		if(cur>=N) return 0;
	}
	return 0;
}

int outR(int cur) {
	if(cur<0) return 0;
	int i;
	FOR(i,Q) {
		if(S[cur]==A[i][0]) {
			if(B[i]=="L") cur--;
			if(B[i]=="R") cur++;
		}
		if(cur<0) return 0;
		if(cur>=N) return 1;
	}
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q>>S;
	FOR(i,Q) cin>>A[i]>>B[i];
	
	int L=-1;
	for(i=20;i>=0;i--) if(outL(L+(1<<i))) L+=1<<i;
	int R=N;
	for(i=20;i>=0;i--) if(outR(R-(1<<i))) R-=1<<i;
	
	int ret=N;
	FOR(i,N) if(i<=L || i>=R) ret--;
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
