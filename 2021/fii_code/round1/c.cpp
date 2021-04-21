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

int M,N;
int A[5050],B[5050];

short AB[5050][5050];
short BA[5050][5050];
int memo[5050][5050];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M;
	FOR(i,M) {
		cin>>A[i];
		FOR(j,i) AB[i][0]+=A[j]>A[i];
	}
	cin>>N;
	FOR(i,N) {
		cin>>B[i];
		FOR(j,i) BA[i][0]+=B[j]>B[i];
	}
	
	FOR(i,M) {
		FOR(j,N) {
			AB[i][j+1]=AB[i][j]+(B[j]>A[i]);
			BA[j][i+1]=BA[j][i]+(A[i]>B[j]);
		}
	}
	FOR(i,5050) memo[M+1][i]=memo[i][N+1]=-1<<30;
	memo[M][N]=0;
	for(x=M;x>=0;x--) for(y=N;y>=0;y--) {
		int& ret=memo[x][y];
		ret=max({ret,AB[x][y]+memo[x+1][y],BA[y][x]+memo[x][y+1]});
	}
	
	cout<<memo[0][0]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
