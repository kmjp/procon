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
int A[2020],B[2020],E[2020];

ll dp[9][9][34];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N) {
		cin>>s;
		if(s.back()=='X') {
			E[i]=1;
			s.pop_back();
		}
		B[i]=atoi(s.c_str());
	}
	dp[0][0][0]=1;
	FOR(i,N) if(E[i]==0) {
		for(j=7;j>=0;j--) {
			for(x=0;x<=4-A[i];x++) for(y=0;y<=33-B[i];y++) (dp[j+1][x+A[i]][y+B[i]]+=dp[j][x][y])%=mo;
		}
	}
	ll ret=0;
	FOR(i,N) if(E[i]) {
		int a=4-A[i];
		int b=33-B[i];
		if(B[i]==0) ret+=dp[8][a][b];
	}
	cout<<ret%mo<<endl;
		
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
