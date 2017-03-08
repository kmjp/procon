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

ll N,K;
ll dp[51][11];
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	dp[0][0]=dp[0][10]=1;
	FOR(i,10) dp[1][i]=1;
	dp[1][10]=10;
	for(i=2;i<=38;i++) {
		FOR(x,10) {
			dp[i][x]+=dp[i-1][x];
			if(x) dp[i][x]+=dp[i-1][x-1];
			if(x<9) dp[i][x]+=dp[i-1][x+1];
		}
		dp[i][10]=dp[i-1][10];
		for(x=1;x<=9;x++) dp[i][10]+=dp[i][x];
	}
	
	
	cin>>K>>S;
	
	if(S.size()==1) {
		K+=S[0]-'0'+1;
	}
	else {
		K += dp[S.size()-1][10];
		for(i=1;i<S[0]-'0';i++) {
			K += dp[S.size()][i];
		}
		for(i=1;i<S.size();i++) {
			if(S[i]>S[i-1]+1) {
				if(S[i-1]<'9') K += dp[S.size()-i][S[i-1]-'0'+1];
				K += dp[S.size()-i][S[i-1]-'0'];
				if(S[i-1]>='1') K += dp[S.size()-i][S[i-1]-'0'-1];
				break;
			}
			else if(S[i]<S[i-1]-1) {
				break;
			}
			
			if(S[i]==S[i-1]+1) {
				K += dp[S.size()-i][S[i-1]-'0'];
				if(S[i-1]>='1') K += dp[S.size()-i][S[i-1]-'0'-1];
			}
			if(S[i]==S[i-1]) {
				if(S[i-1]>='1') K += dp[S.size()-i][S[i-1]-'0'-1];
			}
		}
		if(i==S.size()) K++;
	}
	
	
	for(i=37;i>=0;i--) {
		if(K>dp[i][10]&&K<=dp[i+1][10]) {
			// i+1 digit
			int d=i+1;
			K -= dp[i][10];
			int S=1,E=9;
			FOR(x,d) {
				for(i=S;i<=E;i++) {
					ll sum=0;
					for(y=S;y<=i;y++) {
						sum+=dp[d-x][y];
					}
					if(sum>=K) {
						K-=sum-dp[d-x][i];
						cout<<i;
						S=max(i-1,0);
						E=min(i+1,9);
						break;
					}
				}
				
			}
			cout<<endl;
			return;
			
			
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
