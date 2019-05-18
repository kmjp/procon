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

int H,W;
int A[101][101];
int C[10];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	
	FOR(y,H) FOR(x,W) {
		cin>>A[y][x];
		C[A[y][x]]++;
	}
	if(C[0]==H*W) return _P("Yes 0\n");
	if(C[5]==0) return _P("No\n");
	
	if(H>W) {
		swap(H,W);
		FOR(x,100) FOR(y,100) if(x<y) swap(A[x][y],A[y][x]);
	}
	
	int ma=1;
	if(H>1 && W>1) {
		if(C[6]||C[7]) ma=2;
		if(C[8]) ma=3;
		if(C[9]) ma=4;
	}
	else {
		ma=1010;
		FOR(x,W) if(A[0][x]==5) {
			int L=0,R=0;
			FOR(i,x) {
				if(A[0][i]==6) L=max(L,1);
				if(A[0][i]==7) L=max(L,1);
				if(A[0][i]==8) L=max(L,2);
				if(A[0][i]==9) L=max(L,3);
			}
			for(i=x+1;i<W;i++) {
				if(A[0][i]==6) R=max(R,1);
				if(A[0][i]==7) R=max(R,1);
				if(A[0][i]==8) R=max(R,2);
				if(A[0][i]==9) R=max(R,3);
			}
			
			ma=min(ma,L+R+1);
		}
		
	}
	
	cout<<"Yes "<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
