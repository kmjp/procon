#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T,N,A[1010];
int L[101][101];
int R[101][101];

int left(int LL,int RR) {
	int& ret=L[LL][RR];
	int x;
	if(ret<0) {
		ret=0;
		FOR(x,LL) if(A[x]<A[LL] && A[LL]-A[x]<A[RR]-A[LL]) ret=max(ret,left(x,LL)+1);
	}
	return ret;
}
int right(int LL,int RR) {
	int& ret=R[LL][RR];
	int x;
	if(ret<0) {
		ret=0;
		for(x=RR+1;x<N;x++) if(A[x]<A[RR] && A[RR]-A[x]<A[LL]-A[RR]) ret=max(ret,right(RR,x)+1);
	}
	return ret;
}

int dodo(int i) {
	int x;
	int lm=0,rm=0;
	
	// left side
	FOR(x,i) if(A[x]<A[i]) lm=max(lm,left(x,i)+1);
	// right side
	for(x=i+1;x<N;x++) if(A[x]<A[i]) rm=max(rm,right(i,x)+1);
	
	return lm+rm+1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	
	MINUS(L);
	MINUS(R);
	
	int ma=-1;
	FOR(i,N) ma=max(ma,dodo(i));
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cin>>T;
	while(T--) solve();
	return 0;
}
