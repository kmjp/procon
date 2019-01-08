#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll memo[2][10101][101];
ll mo=1000000007;
int N,D;
string K;

ll dp(int top,int d,int m) {
	if(d==N) return m==0;
	if(memo[top][d][m]>=0) return memo[top][d][m];
	
	ll ret=0;
	int i;
	if(top) {
		FOR(i,K[d]) ret+=dp(0,d+1,(m+i)%D);
		ret+=dp(1,d+1,(m+K[d])%D);
	}
	else {
		FOR(i,10) ret+=dp(0,d+1,(m+i)%D);
	}
	return memo[top][d][m]=ret%mo;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>D;
	N=K.size();
	FORR(c,K) c-='0';
	
	MINUS(memo);
	cout<<(dp(1,0,0)+mo-1)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
