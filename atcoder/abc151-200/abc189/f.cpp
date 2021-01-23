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


int N,M,K;
int A[101010];
int NG[101010];
long double dp[202020],S[202020];

long double hoge(double v) {
	int i;
	
	for(i=N-1;i>=0;i--) {
		if(NG[i]) {
			dp[i]=v;
		}
		else {
			dp[i]=1+(S[i+1]-S[i+1+M])/M;
		}
		S[i]=S[i+1]+dp[i];
	}
	return dp[0];
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	int p=-1,cur=0;
	FOR(i,K) {
		cin>>A[i];
		if(p+1!=A[i]) cur=0;
		p=A[i];
		NG[A[i]]=1;
		cur++;
		if(cur==M) return _P("-1\n");
	}
	
	long double L=0,R=1e12;
	FOR(i,300) {
		long double M=(L+R)/2;
		if(hoge(M)>M) L=M;
		else R=M;
	}
	_P("%.12lf\n",(double)L);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
