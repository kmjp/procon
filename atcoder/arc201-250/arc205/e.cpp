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
int A[404040];
const ll mo=998244353;
ll dp[1<<10][1<<10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,1<<10) FOR(j,1<<10) dp[i][j]=1;
	
	cin>>N;
	
	FOR(i,N) {
		cin>>A[i];
		x=A[i]>>10;
		y=A[i]%(1<<10);
		
		int mask=0;
		ll ret=1;
		FOR(mask,1<<10) if((mask|y)==mask) (dp[x][mask]*=A[i])%=mo;
		FOR(mask,1<<10) if((mask|x)==x) (ret*=dp[mask][y])%=mo;
		cout<<ret<<endl;
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
