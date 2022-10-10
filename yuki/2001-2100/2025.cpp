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

int N,L;
int C[4];

ll dp[5][102010];
ll S[5][102010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L;
	FOR(i,N) cin>>C[i];
	
	dp[N][0]=1;
	FOR(i,101010) S[N][i]=1;
	for(j=N-1;j>=0;j--) {
		FOR(i,101010) {
			dp[j][i]=S[j+1][i];
			if(i>C[j]) dp[j][i]-=S[j+1][i-C[j]-1];
			
			S[j][i]=dp[j][i];
			if(i) S[j][i]+=S[j][i-1];
		}
	}
	
	int Q;
	cin>>Q;
	while(Q--) {
		ll K;
		cin>>K;
		
		if(dp[0][L]<K) {
			cout<<-1<<endl;
			continue;
		}
		
		int cur=L;
		int R[4]={};
		FOR(i,N) {
			int ma=min(cur,C[i]);
			for(j=20;j>=0;j--) if(ma>=(1<<j)) {
				ll su=S[i+1][cur-(ma-(1<<j))-1]-S[i+1][cur-ma-1];
				if(su<K) {
					K-=su;
					ma-=1<<j;
				}
			}
			
			R[i]=ma;
			cur-=ma;
			cout<<R[i]<<" ";
		}
		cout<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
