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

int N,M;
int K[151];
int X[151][11];
int D[151][11];
ll V[151][76][11];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	memset(V,0x3f,sizeof(V));
	
	ll ret=1LL<<60;
	FOR(i,N) {
		cin>>K[i];
		FOR(j,K[i]) {
			cin>>X[i][j]>>D[i][j];
			if(i==0) {
				V[i][0][j]=0;
			}
			else {
				FOR(x,M+1) FOR(y,K[i-1]) V[i][x][j]=min(V[i][x][j],V[i-1][x][y]+abs(X[i][j]-X[i-1][y])*(D[i][j]+D[i-1][y]));
			}
			if(i==1) {
				V[i][1][j]=0;
			}
			else if(i>=2) {
				FOR(x,M) FOR(y,K[i-2]) V[i][x+1][j]=min(V[i][x+1][j],V[i-2][x][y]+abs(X[i][j]-X[i-2][y])*(D[i][j]+D[i-2][y]));
			}
			
			if(i==N-1) {
				FOR(x,M+1) ret=min(ret,V[i][x][j]);
			}
			if(i==N-2) {
				FOR(x,M) ret=min(ret,V[i][x][j]);
			}
			
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
