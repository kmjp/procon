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
string S;
int nex[42][2];
ll dp[42][42][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	M=S.size();
	
	FOR(i,M+1) {
		FOR(j,2) {
			string T=S.substr(0,i)+(char)('0'+j);
			for(x=i+1;x>=0;x--) {
				if(S.substr(0,x)==T.substr(T.size()-x)) {
					nex[i][j]=x;
					break;
				}
			}
		}
	}
	
	ll ret=(1LL<<(N-M));
	for(int same=0;same<M;same++) {
		for(int state=0;state<=M;state++) {
			ZERO(dp);
			dp[0][state][0]=1;
			FOR(i,N) {
				int mask=3;
				if(i+same+1==N) {
					mask=1<<((S[i-(N-M)]^1)-'0');
				}
				if(i+same>=N) {
					mask=1<<(S[i-(N-M)]-'0');
				}
				
				
				FOR(x,M+1) {
					if(mask&1) {
						dp[i+1][nex[x][0]][nex[x][0]==M] += dp[i][x][0];
						dp[i+1][nex[x][0]][1] += dp[i][x][1];
					}
					if(mask&2) {
						dp[i+1][nex[x][1]][nex[x][1]==M] += dp[i][x][0];
						dp[i+1][nex[x][1]][1] += dp[i][x][1];
					}
				}
			}
			ret+=dp[N][state][1];
		}
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
