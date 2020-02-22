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
 
int N;
int R[101010];
int S[101010];
int H[101010];
int T[101010][4];
 
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>R[i]>>H[i];
		H[i]--;
		S[R[i]]++;
		T[R[i]][H[i]]++;
	}
	FOR(i,100100) S[i+1]+=S[i];
	
	FOR(i,N) {
		int D=T[R[i]][H[i]]-1;
		int W=S[R[i]-1]+T[R[i]][(H[i]+1)%3];
		int L=N-1-D-W;
		_P("%d %d %d\n",W,L,D);
	}
}
 
 
int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}