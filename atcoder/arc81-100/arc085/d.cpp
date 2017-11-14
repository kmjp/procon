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

int N,X,Y;
int A[2020];
int memoX[2020][2020];
int memoY[2020][2020];

int turnY(int op,int left);
int turnX(int op,int left) {
	if(memoX[left][op]>=0) return memoX[left][op];
	// all
	int ret=abs(A[0]-A[op]);
	if(left>1) ret=max(ret,turnY(left-1,left-1));
	if(left>1) ret=max(ret,turnX(op,left-1));
	return memoX[left][op]=ret;
}
int turnY(int op,int left) {
	if(memoY[left][op]>=0) return memoY[left][op];
	// all
	int ret=abs(A[0]-A[op]);
	if(left>1) ret=min(ret,turnX(left-1,left-1));
	if(left>1) ret=min(ret,turnY(op,left-1));
	return memoY[left][op]=ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Y;
	FOR(i,N) cin>>A[i];
	reverse(A,A+N);
	A[N]=Y;
	MINUS(memoX);
	MINUS(memoY);
	cout<<turnX(N,N)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
