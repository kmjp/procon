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

int N;
int A[4],X[4],Y[4];
char S[11][11];
ll dp[10][10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(A[3],100) FOR(A[2],A[3]) FOR(A[1],A[2]) FOR(A[0],A[1]) {
		
		FOR(y,10) FOR(x,10) S[y][x]='.';
		FOR(r,4) {
			FOR(y,10) FOR(x,10) {
				if(abs(A[r]/10-y)==abs(A[r]%10-x) && abs(A[r]/10-y)<=2) S[y][x]='X';
				if(abs(A[r]/10-y)<=2 && abs(A[r]%10-x)==0) S[y][x]='X';
				if(abs(A[r]/10-y)<=0 && abs(A[r]%10-x)<=2) S[y][x]='X';
			}
		}
		ZERO(dp);
		FOR(x,10) {
			FOR(y,10) if(S[y][x]=='.') {
				if(x==0) dp[y][x]=1;
				else {
					if(y) dp[y][x]+=dp[y-1][x-1];
					if(y<9) dp[y][x]+=dp[y+1][x-1];
					dp[y][x]+=dp[y][x-1];
				}
			}
		}
		ll ret=0;
		FOR(y,10) ret+=dp[y][9];
		if(ret==1) {
			FOR(y,10) FOR(x,10) S[y][x]='.';
			FOR(r,4) S[A[r]/10][A[r]%10]='C';
			FOR(y,10) cout<<S[y]<<endl;
			return;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
