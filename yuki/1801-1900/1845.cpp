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

int N;
int A[202020];
string S;

ll dp[202020];
int nex[202020][26];
const ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
	}
	cin>>S;
	FOR(i,26) nex[N][i]=N;
	for(i=N-1;i>=0;i--) {
		S[i]-='a';
		FOR(j,26) nex[i][j]=nex[i+1][j];
		nex[i][S[i]]=i;
	}
	FOR(i,26) if(nex[0][i]<N) dp[nex[0][i]]++;
	ll ret=0;
	FOR(i,N) {
		(ret+=dp[i]*A[i])%=mo;
		FOR(j,26) {
			if(S[i]==j) {
				(dp[nex[i+1][j]]+=dp[i])%=mo;
			}
			else {
				(dp[nex[i+1][j]]+=dp[i]*A[i])%=mo;
			}
		}
	}
	cout<<ret<<endl;
	
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
