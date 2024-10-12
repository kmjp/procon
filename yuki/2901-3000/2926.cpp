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
string S;
ll dp[202020][2];
const ll mo=998244353;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	dp[0][0]=1;
	FOR(i,N) {
		FOR(x,2) FOR(y,3) {
			if(S[i]=='L'&&y!=0) continue;
			if(S[i]=='R'&&y!=2) continue;
			if(S[i]=='U'&&y!=1) continue;
			if(x==1&&y==0) continue;
			(dp[i+1][(y==2)]+=dp[i][x])%=mo;
		}
	}
	cout<<(dp[N][0]+dp[N][1])%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
