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

int T;
int M,X;
int C[55],H[55];
ll dp[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>M>>X;
		int HS=0;
		FOR(i,M) {
			cin>>C[i]>>H[i];
			HS+=H[i];
		}
		FOR(i,HS+1) dp[i]=-1LL<<60;
		dp[0]=0;
		FOR(i,M) {
			for(j=HS-H[i];j>=0;j--) if(dp[j]>=C[i]) chmax(dp[j+H[i]],dp[j]-C[i]);
			FOR(j,HS+1) dp[j]+=X;
		}
		int ma=0;
		FOR(i,HS+1) if(dp[i]>=0) ma=i;
		cout<<ma<<endl;
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
