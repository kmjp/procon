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

string A,B;
ll mo=1000000007;
ll dp[10101][2][2][3][8]; // digit, more, inc3, mod3, mod8

ll dodo(string V) {
	ZERO(dp);
	dp[0][0][0][0][0]=1;
	int d,more,i3,m3,m8,x;
	FOR(d,V.size()) {
		V[d]-='0';
		FOR(more,2) FOR(i3,2) FOR(m3,3) FOR(m8,8) FOR(x,10) {
			if(more==0 && x>V[d]) continue;
			(dp[d+1][more || (x<V[d])][i3 || (x==3)][(m3*10+x)%3][(m8*10+x)%8] += dp[d][more][i3][m3][m8])%=mo;
		}
	}
	ll ret=0;
	FOR(more,2) FOR(i3,2) FOR(m3,3) FOR(m8,8) {
		if((m3==0 || i3==1) && m8) ret += dp[V.size()][more][i3][m3][m8];
	}
	return ret%mo;
}

string decdec(string A) {
	reverse(A.begin(),A.end());
	FORR(r,A) {
		if(r!='0') {
			r--;
			break;
		}
		r='9';
	}
	if(A.back()=='0') A.resize(A.size()-1);
	reverse(A.begin(),A.end());
	return A;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B;
	A=decdec(A);
	cout<<(dodo(B)-dodo(A)+ mo)%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
