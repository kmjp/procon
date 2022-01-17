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


int A,N;
int dp[1010101];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>N;
	FOR(i,1000000) dp[i]=1<<20;
	dp[1]=0;
	queue<int> Q;
	Q.push(1);
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		if(x==N) {
			cout<<dp[x]<<endl;
			return;
		}
		ll B=1LL*x*A;
		if(B<1000000) {
			if(dp[B]==1<<20) {
				dp[B]=dp[x]+1;
				Q.push(B);
			}
		}
		if(x>=10&&x%10) {
			string s=to_string(x);
			s=s.back()+s.substr(0,s.size()-1);
			y=atoi(s.c_str());
			if(dp[y]==1<<20) {
				dp[y]=dp[x]+1;
				Q.push(y);
			}
			
		}
		
		
	}
	
	
	cout<<-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
