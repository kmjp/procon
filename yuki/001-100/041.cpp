#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll mo = 1000000009;
ll dp[200000];
ll sum[200000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	dp[0]=1;
	for(j=1;j<=9;j++) FOR(i,100001) (dp[i+j]+=dp[i])%=mo;
	FOR(i,100001) sum[i]=((i?sum[i-1]:0)+dp[i])%mo;
	
	cin>>x;
	FOR(i,x) {
		ll M;
		cin>>M;
		cout<<sum[M/111111]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
