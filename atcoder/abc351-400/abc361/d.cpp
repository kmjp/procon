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
string S,T;
int dp[1<<16][16];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>T;
	int cur=0,tar=0;
	
	FOR(i,N) cur|=(S[i]=='B')<<i;
	FOR(i,N) tar|=(T[i]=='B')<<i;
	int mask;
	FOR(mask,1<<(N+2)) FOR(x,N+2) dp[mask][x]=1<<20;
	dp[cur][N]=0;
	queue<int> Q;
	Q.push(cur*100+N);
	while(Q.size()) {
		int cur=Q.front()/100;
		int emp=Q.front()%100;
		Q.pop();
		
		if(cur==tar&&emp==N) {
			cout<<dp[cur][emp]<<endl;
			return;
		}
		
		FOR(i,N+1) {
			if(i==emp-1||i==emp||i==emp+1) continue;
			int ncur=cur;
			int t=(cur>>i)&3;
			ncur^=t<<i;
			ncur^=t<<emp;
			
			
			int nemp=i;
			if(dp[ncur][nemp]==1<<20) {
				dp[ncur][nemp]=dp[cur][emp]+1;
				Q.push(ncur*100+nemp);
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
