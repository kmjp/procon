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

int A,B,C,N;
double memo[55][55][55][55];

double dp(int A,int B,int C,int N) {
	if(memo[A][B][C][N]>=0) return memo[A][B][C][N];
	double ret=0;
	if(N&&A+B+C>=2) {
		// AA,BB,CC
		double apat=(A+C+B)*(A+C+B-1)/2;
		if(A>=2) ret+=A*(A-1)/2/apat*(1+dp(A-1,B,C,N-1));
		if(B>=2) ret+=B*(B-1)/2/apat*(0+dp(A,B-1,C,N-1));
		if(C>=2) ret+=C*(C-1)/2/apat*(0+dp(A,B,C-1,N-1));
		if(A&&B) ret+=A*B/apat*dp(A,B,C,N-1);
		if(A&&C) ret+=A*C/apat*dp(A,B,C,N-1);
		if(B&&C) ret+=B*C/apat*dp(A,B,C,N-1);
		
	}
	return memo[A][B][C][N]=ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C>>N;
	FOR(i,52) FOR(j,52) FOR(k,52) FOR(l,52) memo[i][j][k][l]=-1;
	
	_P("%.12lf %.12lf %.12lf\n",dp(A,B,C,N),dp(B,A,C,N),dp(C,A,B,N));
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
