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
int A[101010];
ll dp[101010][510];
ll S[101010];
const ll mo=1000000007;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	S[0]=1;
	for(i=1;i<=N;i++) {
		cin>>x;
		
		S[i]+=S[i-1];
		for(j=1;j<=500;j++) {
			S[i]+=dp[i][j];
			(dp[i+j][j]+=dp[i][j])%=mo;
		}
		S[i]%=mo;
		
		
		if(i==N) cout<<S[i]<<endl;
		
		if(x==1) {
			(dp[i+2][1]+=S[i])%=mo;
		}
		else if(x<=500) {
			(dp[i+x][x]+=S[i])%=mo;
		}
		else {
			for(j=i+x;j<=N;j+=x) S[j]+=S[i];
		}
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
