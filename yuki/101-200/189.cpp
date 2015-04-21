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

string M,D;
ll mo=1000000009;

map<int,ll> enumdigsum(string S) {
	const int mdig=200;
	static ll dp[mdig+5][mdig*10+50];
	int tot=0,i,x,y;
	map<int,ll> R;
	
	if(dp[0][0]==0) {
		dp[0][0]=1;
		FOR(i,mdig+2) FOR(y,mdig*10+2) FOR(x,10) (dp[i+1][y+x]+=dp[i][y])%=mo;
	}
	
	reverse(S.begin(),S.end());
	while(S.size()) {
		int x=S[S.size()-1]-'0';
		FOR(i,x) FOR(y,mdig*10+2) if(dp[S.size()-1][y]) (R[y+tot+i] += dp[S.size()-1][y])%=mo;
		tot+=x;
		S.pop_back();
	}
	R[tot]++;
	return R;
}

void solve() {
	
	cin>>M>>D;
	map<int,ll> MM = enumdigsum(M);
	map<int,ll> DD = enumdigsum(D);
	
	ll ret=0;
	ITR(it,MM) if(it->first) ret += it->second*DD[it->first]%mo;
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
