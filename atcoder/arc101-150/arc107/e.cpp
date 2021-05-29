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

int N;
int A[4][505050],B[505050][4];
ll C[3]={};

int mex[3][3]= {{1,2,1},{2,0,0},{1,0,0}};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[0][i];
		if(i<4) B[0][i]=A[0][i];
		C[A[0][i]]++;
	}
	FOR(i,N-1) {
		cin>>B[i+1][0];
		if(i+1<4) A[i+1][0]=B[i+1][0];
		C[B[i+1][0]]++;
	}
	
	for(y=1;y<min(4,N);y++) {
		for(x=1;x<N;x++) {
			A[y][x]=mex[A[y-1][x]][A[y][x-1]];
			C[A[y][x]]++;
		}
	}
	for(x=1;x<min(4,N);x++) {
		for(y=1;y<N;y++) {
			B[y][x]=mex[B[y-1][x]][B[y][x-1]];
			if(y>=4) C[B[y][x]]++;
		}
	}
	
	if(N>=5) {
		for(i=3;i<N;i++) C[A[3][i]]+=N-1-i;
		for(i=4;i<N;i++) C[B[i][3]]+=N-1-i;
	}
	cout<<C[0]<<" "<<C[1]<<" "<<C[2]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
