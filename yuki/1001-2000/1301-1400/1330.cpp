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


int N,M,P;
int A[202020],B[202020];
int C[61];

ll dp[1000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>P;
	int ma=0;
	FOR(i,N) {
		cin>>A[i];
		ma=max(ma,A[i]);
		x=1;
		while(A[i]%P==0) A[i]/=P, x++;
		C[x]=max(C[x],A[i]);
	}
	
	dp[0]=1;
	FOR(i,900) {
		if(1LL*dp[i]*ma>M) {
			cout<<i+1<<endl;
			return;
		}
		for(j=1;j<=31;j++) dp[i+j]=max(dp[i+j],dp[i]*C[j]);
	}
	cout<<-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
