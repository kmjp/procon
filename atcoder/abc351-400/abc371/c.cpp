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

int N,M[2];
int A[8][8];
int B[8][8];
int C[8][8];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	cin>>M[0];
	FOR(i,M[0]) {
		cin>>x>>y;
		A[x-1][y-1]=A[y-1][x-1]=1;
	}
	cin>>M[1];
	FOR(i,M[1]) {
		cin>>x>>y;
		B[x-1][y-1]=B[y-1][x-1]=1;
	}
	FOR(i,N) for(j=i+1;j<N;j++) {
		cin>>C[i][j];
		C[j][i]=C[i][j];
	}
	int mi=1<<30;
	vector<int> V;
	FOR(i,N) V.push_back(i);
	do {
		int sum=0;
		FOR(x,N) FOR(y,N) {
			if(A[x][y]!=B[V[x]][V[y]]) sum+=C[V[x]][V[y]];
		}
		mi=min(mi,sum/2);
		
	} while(next_permutation(ALL(V)));
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
