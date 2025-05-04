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

int N,T,M,K;

double memo[31][31];
double memo2[31][31][31][31];

double step(int T,int K) ;

double step2(int T,int K,int num,int sum) {
	if(num==N) return 0;
	if(sum>=M) return 1.0*(N-num)/N*step(T-1,K);
	if(memo2[T][K][num][sum]>=0) return memo2[T][K][num][sum];
	double ret=-1e9;
	for(int i=1;sum+i<=M;i++) ret=max(ret,1.0/N*step(T-1,K-i)+step2(T,K,num+1,sum+i));
	return memo2[T][K][num][sum]=ret;
}

double step(int T,int K) {
	if(K<=0) return 1;
	if(T==0) return 0;
	if(memo[T][K]>=0) return memo[T][K];
	return memo[T][K]=step2(T,K,0,0);
	
}
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T>>M>>K;
	FOR(i,31) FOR(j,31) memo[i][j]=-1;
	FOR(i,31) FOR(j,31) FOR(x,31) FOR(y,31) memo2[i][j][x][y]=-1;
	
	
	double ret=step(T,K);
	_P("%.12lf\n",ret);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
