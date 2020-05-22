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

int H,W;
ll dp[17][1<<15];
const ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	vector<int> cand;
	FOR(i,1<<W) if((i&(i<<1))==0) cand.push_back(i);
	dp[0][0]=1;
	FOR(y,H) {
		FORR(c,cand) if(dp[y][c]) FORR(c2,cand) {
			if(c&c2) continue;
			if(c&(c2<<1)) continue;
			if((c<<1)&c2) continue;
			(dp[y+1][c2]+=dp[y][c])%=mo;
		}
	}
	ll ret=0;
	FOR(i,1<<W) ret+=dp[H][i];
	cout<<(ret+mo-1)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
