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
ll C[101010];

vector<int> ret;
vector<int> dp[1010101];
int from[1010101];


void update(vector<int>& A,vector<int>& B) {
	int i,d=0;
	FORR(a,A) d+=a;
	FORR(a,B) d-=a;
	if(d>0) return;
	if(d==0) {
		for(i=9;i>=1;i--) {
			if(A[i]<B[i]) break;
			if(A[i]>B[i]) return;
		}
	}
	A=B;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=1;i<=9;i++) cin>>C[i];
	
	ret.resize(10);
	FOR(i,N+1) dp[i].resize(10);
	
	FOR(i,N+1) {
		for(j=1;j<=9;j++) if(i+C[j]<=N) {
			dp[i][j]++;
			update(dp[i+C[j]],dp[i]);
			dp[i][j]--;
		}
		update(ret,dp[i]);
	}
	string S;
	FOR(i,9) S+=string(ret[9-i],'9'-i);
	cout<<S<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
