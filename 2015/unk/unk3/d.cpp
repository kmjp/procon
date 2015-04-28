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

ll N;
ll mo=1000000007;
ll memo[1010000][2];

/*
ll dodo(int left,int ring){
	if(left<=0) return 1;
	
	ll& ret=memo[left][ring];
	if(ret>=0) return ret;
	
	ret=0;
	if(ring) {
		ret = dodo(left-1,1) * dodo(left-2,0) % mo;
	}
	else {
		ret = dodo(left-1,0) * (dodo(left-2,0)+dodo(left-2,1)) % mo;
	}
	return ret;
}
*/

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N;
	
	memo[0][0]=memo[0][1]=1;
	memo[1][0]=memo[1][1]=1;
	
	for(i=2;i<=N;i++) {
		memo[i][0]=memo[i-1][0] * (memo[i-2][0]+memo[i-2][1]) % mo;
		memo[i][1]=memo[i-1][1] * memo[i-2][0] % mo;
	}
	cout<<(memo[N][0]+memo[N][1])%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
