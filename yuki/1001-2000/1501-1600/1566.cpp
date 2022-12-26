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

int N,M;
int A[7][7];
int B[7][7];
int X[101],Y[101],K[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>X[i]>>Y[i]>>K[i];
		X[i]--,Y[i]--,K[i]^=1;
	}
	
	ll ret=0;
	if(N<=6) {
		int mask;
		FOR(mask,1<<(2*N-1)) {
			FOR(y,N) A[y][0]=(mask>>y)&1;
			for(x=1;x<N;x++) A[0][x]=(mask>>(N-1+x))&1;
			for(y=1;y<N;y++) for(x=1;x<N;x++) A[y][x]=A[y-1][x-1]^A[y-1][x]^A[y][x-1];
			FOR(y,N) FOR(x,N) B[y+1][x+1]=A[y][x]^B[y][x+1]^B[y+1][x]^B[y][x];
			int ok=1;
			FOR(i,M) if(A[Y[i]][X[i]]!=K[i]) ok=0;
			FOR(y,N) FOR(x,N) {
				for(i=2;max(y,x)+i<=N;i++) {
					if(B[y+i][x+i]^B[y][x+i]^B[y+i][x]^B[y][x]) ok=0;
				}
			}
			ret+=ok;
		}
	}
	else {
		ret=1;
		FOR(i,M) if(K[i]) ret=0;
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
