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

int K;
int L,R;
string S,T;
int dp[505050][41];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>S>>T;
	L=S.size();
	R=T.size();
	if(abs(L-R)>K) {
		cout<<"No"<<endl;
		return;
	}
	MINUS(dp);
	dp[0][20]=K;
	FOR(i,L+1) {
		for(x=-K;x<=K;x++) if(dp[i][x+20]>=0) {
			y=dp[i][x+20];
			
			if(i+x<R&&S[i]==T[i+x]) chmax(dp[i+1][x+20],y);
			if(y) {
				// S‚ð1•¶Žšíœremove
				chmax(dp[i+1][x+20-1],y-1);
				// replace
				if(i+x<R) chmax(dp[i+1][x+20],y-1);
				// S‚ð1•¶Žš’Ç‰Á
				chmax(dp[i][x+20+1],y-1);
			}
		}
	}
	if(dp[L][R-L+20]>=0) {
		cout<<"Yes"<<endl;
	}
	else {
		cout<<"No"<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
