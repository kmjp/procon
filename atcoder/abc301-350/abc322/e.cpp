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

int N,K,P;
ll dp[6][6][6][6][6];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>P;
	int A[5];
	int V[5]={};
	FOR(A[0],6) FOR(A[1],6) FOR(A[2],6) FOR(A[3],6) FOR(A[4],6) dp[A[0]][A[1]][A[2]][A[3]][A[4]]=1LL<<60;
	dp[0][0][0][0][0]=0;
	while(N--) {
		ZERO(V);
		cin>>x;
		FOR(i,K) cin>>V[i];
		for(A[0]=5;A[0]>=0;A[0]--)
		for(A[1]=5;A[1]>=0;A[1]--)
		for(A[2]=5;A[2]>=0;A[2]--)
		for(A[3]=5;A[3]>=0;A[3]--)
		for(A[4]=5;A[4]>=0;A[4]--) {
			chmin(dp[min(A[0]+V[0],P)][min(A[1]+V[1],P)][min(A[2]+V[2],P)][min(A[3]+V[3],P)][min(A[4]+V[4],P)],dp[A[0]][A[1]][A[2]][A[3]][A[4]]+x);
		}
	}
	
	ll ret=1LL<<60;
	FOR(A[0],6) FOR(A[1],6) FOR(A[2],6) FOR(A[3],6) FOR(A[4],6) {
		FOR(i,5) if(i<K&&A[i]<P) break;
		if(i<5) continue;
		ret=min(ret,dp[A[0]][A[1]][A[2]][A[3]][A[4]]);
	}
	if(ret==1LL<<60) ret=-1;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
