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

int N,T;
int A[3030],B[3030];
int L[3030][3030];
int R[3030][3030];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		FOR(x,3030) {
			L[i+1][x]=max(L[i+1][x],L[i][x]);
			if(x+A[i]<=T) L[i+1][x+A[i]]=max(L[i+1][x+A[i]],L[i][x]+B[i]);
		}
	}
	for(i=N-1;i>=0;i--) {
		FOR(x,3030) {
			R[i][x]=max(R[i][x],R[i+1][x]);
			if(x+A[i]<=T) R[i][x+A[i]]=max(R[i][x+A[i]],R[i+1][x]+B[i]);
		}
	}
	FOR(i,N+1) {
		FOR(j,T) {
			L[i][j+1]=max(L[i][j],L[i][j+1]);
			R[i][j+1]=max(R[i][j],R[i][j+1]);
		}
	}
	
	
	int ma=0;
	FOR(i,N) {
		FOR(x,T) {
			y=B[i]+L[i][x]+R[i+1][T-1-x];
			ma=max(ma,y);
		}
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
