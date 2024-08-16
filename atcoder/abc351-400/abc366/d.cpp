#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,Q;
int A[101][101][101];
ll SA[101][101][101];

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N;
	FOR(x,N) FOR(y,N) FOR(z,N) {
		cin>>A[z][y][x];
		SA[z][y+1][x+1]=SA[z][y+1][x]+SA[z][y][x+1]-SA[z][y][x]+A[z][y][x];
	}
	
	cin>>Q;
	while(Q--) {
		int Lx,Rx,Ly,Ry,Lz,Rz;
		cin>>Lx>>Rx>>Ly>>Ry>>Lz>>Rz;
		Lx--,Ly--,Lz--;
		ll sum=0;
		for(i=Lz;i<Rz;i++) sum+=SA[i][Ry][Rx]-SA[i][Ry][Lx]-SA[i][Ly][Rx]+SA[i][Ly][Lx];
		cout<<sum<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
