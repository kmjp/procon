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

string T;
int N;
int A[101][101];

int dp[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	cin>>N;
	FOR(i,T.size()+5) dp[i]=1<<30;
	dp[0]=0;
	FOR(i,N) {
		ZERO(A);
		cin>>x;
		FOR(y,x) {
			cin>>s;
			for(k=0;k+s.size()<=T.size();k++) if(T.substr(k,s.size())==s) A[k][s.size()]=1;
		}
		for(k=100;k>=0;k--) {
			for(j=1;j<=100;j++) if(A[k][j]) chmin(dp[k+j],dp[k]+1);
		}
	}
	
	if(dp[T.size()]==1<<30) {
		cout<<-1<<endl;
	}
	else {
		cout<<dp[T.size()]<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
