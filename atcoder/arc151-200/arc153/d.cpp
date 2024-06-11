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

int N;
ll A[202020];
ll from[202020];
ll to[202020];
ll S[202020];
ll p10[13];

ll dp[13][202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p10[0]=1;
	FOR(i,10) p10[i+1]=p10[i]*10;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	
	FOR(j,11) FOR(i,N+1) dp[j][i]=1LL<<60;
	dp[0][0]=0;
	FOR(i,10) {
		vector<pair<int,int>> pre;
		int C[11]={};
		FOR(j,N) {
			C[A[j]/p10[i]%10]++;
			pre.push_back({A[j]%p10[i],j});
		}
		sort(ALL(pre));
		reverse(ALL(pre));
		FOR(j,N+1) {
			FOR(x,10) {
				ll cv=dp[i][j];
				int carry=0;
				FOR(y,11) {
					cv+=C[y]*((y+x)%10);
					carry+=C[y]*((y+x)/10);
				}
				chmin(dp[i+1][carry],cv);
			}
			
			if(j<N) {
				x=pre[j].second;
				y=A[x]/p10[i]%10;
				C[y]--;
				C[y+1]++;
			}
		}
	}
	
	
	
	cout<<dp[10][0]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
