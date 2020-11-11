#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W;
int N,M;
int A[1555][1555];
int B[1555][1555];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>N>>M;
	FOR(i,N) {
		cin>>x>>y;
		A[x-1][y-1]=1;
	}
	FOR(i,M) {
		cin>>x>>y;
		A[x-1][y-1]=2;
	}
	FOR(y,H) {
		int ok=0;
		FOR(x,W) {
			if(A[y][x]==1) ok=1;
			if(A[y][x]==2) ok=0;
			B[y][x]|=ok;
		}
		ok=0;
		for(x=W-1;x>=0;x--) {
			if(A[y][x]==1) ok=1;
			if(A[y][x]==2) ok=0;
			B[y][x]|=ok;
		}
	}
	FOR(x,W) {
		int ok=0;
		FOR(y,H) {
			if(A[y][x]==1) ok=1;
			if(A[y][x]==2) ok=0;
			B[y][x]|=ok;
		}
		ok=0;
		for(y=H-1;y>=0;y--) {
			if(A[y][x]==1) ok=1;
			if(A[y][x]==2) ok=0;
			B[y][x]|=ok;
		}
	}
	int ret=0;
	FOR(y,H) FOR(x,W) ret+=B[y][x];
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
