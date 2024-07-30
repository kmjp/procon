#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T,N,K;
string S;

vector<pair<int,int>> dp[2][202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K>>S;
		
		FOR(i,N-1) if(S[i]!=S[i+1]) K--;
		
		dp[0][0]={{0,0}};
		FOR(i,N) {
			S[i]-='A';
			vector<pair<int,int>> C[2];
			FOR(x,2) {
				FOR(y,2) {
					int sc=(i&&(x!=y))+(S[i]!=y);
					FORR2(a,b,dp[x][i]) {
						C[y].push_back({a+sc,b+sc});
					}
				}
			}
			FOR(x,2) {
				dp[x][i+1].clear();
				sort(ALL(C[x]));
				FORR2(a,b,C[x]) {
					if(dp[x][i+1].empty()||dp[x][i+1].back().second+1<a) {
						dp[x][i+1].push_back({a,b});
					}
					else {
						chmax(dp[x][i+1].back().second,b);
					}
				}
			}
		}
		
		int cx=-1;
		FOR(x,2) {
			FORR2(a,b,dp[x][N]) if(a<=K&&K<=b) cx=x;
		}
		string R;
		if(cx==-1) {
			cout<<"NO"<<endl;
			continue;
		}
		for(i=N-1;i>=0;i--) {
			int ok=0;
			FOR(x,2) if(ok==0) {
				int dif=(i&&(x!=cx))+(cx!=S[i]);
				FORR2(a,b,dp[x][i]) if(a+dif<=K&&K<=b+dif) {
					R+=cx+'A';
					cx=x;
					K-=dif;
					ok=1;
					break;
				}
			}
		}
		reverse(ALL(R));
		cout<<"YES"<<endl;
		cout<<R<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
