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

int N;
string S;
ll dp[201][201][4][101];
ll mo=1000000007;
ll momo[4] = {1,10,100,91};

ll dpdp(int L,int R,int len,int m) {
	if(L<0 || R>=N) return 0;
	len %= 4;
	ll& ret =dp[L][R][len][m];
	if(ret>=0) return ret;
	ret=0;
	
	// take
	if(S[L]==S[R]) {
		int m2=(m*10+S[R]+S[L]*momo[(len+1)%4])%101;
		if(m2==0) ret++;
		ret += dpdp(L-1,R+1,len+2,m2);
	}
	
	ret += dpdp(L-1,R,len,m);
	ret += dpdp(L,R+1,len,m);
	ret += mo-dpdp(L-1,R+1,len,m);
	ret %= mo;
	return ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(dp);
	
	cin>>N>>S;
	ll ret=0;
	FORR(c,S) c-='0';
	
	FOR(y,N) {
		FOR(x,y) if(S[x]==S[y]) {
			if(S[x]==0) ret++;
			ret += dpdp(x-1,y+1,2,S[x]*10+S[y]);
		}
		if(S[y]==0) ret++;
		ret += dpdp(y-1,y+1,1,S[y]);
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
