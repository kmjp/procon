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

int H,W,K;
ll dp[101][10];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>H>>W>>K;
	
	vector<int> cand;
	FOR(i,1<<(W-1)) {
		int ng=0;
		FOR(j,8) if(((i>>j)&3)==3) ng=1;
		if(ng==0) cand.push_back(i);
	}

	
	dp[0][0]=1;
	FOR(i,H) {
		FOR(x,W) {
			FORR(c,cand) {
				int y=x;
				if(c&(1<<x)) y++;
				if(x && (c&(1<<(x-1)))) y--;
				(dp[i+1][y]+=dp[i][x])%=mo;
			}
		}
	}
	cout<<dp[H][K-1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
