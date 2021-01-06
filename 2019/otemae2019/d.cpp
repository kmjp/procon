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


int N,M;
string T[1010];
ll dp[1010][1010][3];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) cin>>T[i];
	
	dp[0][0][0]=1;
	FOR(i,N) {
		for(j=M;j>=0;j--) {
			FOR(y,3) if(dp[i][j][y]) {
				FOR(x,10) {
					if(i==0 && x==0) continue;
					int z=(y*10+x)%3;
					
					if(z==0 && x%5==0) {
						if(j<M&&T[j]=="FizzBuzz") (dp[i+1][j+1][z]+=dp[i][j][y])%=mo;
					}
					else if(z==0 && x%5) {
						if(j<M&&T[j]=="Fizz") (dp[i+1][j+1][z]+=dp[i][j][y])%=mo;
					}
					else if(z && x%5==0) {
						if(j<M&&T[j]=="Buzz") (dp[i+1][j+1][z]+=dp[i][j][y])%=mo;
					}
					else {
						(dp[i+1][j][z]+=dp[i][j][y])%=mo;
					}
				}
				
			}
		}
	}
	
	cout<<(dp[N][M][0]+dp[N][M][1]+dp[N][M][2])%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
