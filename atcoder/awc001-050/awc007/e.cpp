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

int N,M;
ll X[20],Y[20];
ll S,T;
ll dp[1<<18][18];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S>>T;
	S--,T--;
	Y[0]=S/N;
	X[0]=S%N;
	Y[1]=T/N;
	X[1]=T%N;
	FOR(i,M) {
		ll v;
		cin>>v;
		Y[2+i]=(v-1)/N;
		X[2+i]=(v-1)%N;
	}
	int mask;
	M+=2;
	FOR(mask,1<<M) FOR(i,M) dp[mask][i]=1LL<<60;
	dp[1][0]=0;
	FOR(mask,1<<M) FOR(i,M) if(mask&(1<<i)) {
		FOR(j,M) if((mask&(1<<j))==0) chmin(dp[mask|(1<<j)][j],dp[mask][i]+abs(X[i]-X[j])+abs(Y[i]-Y[j]));
	}
	cout<<dp[(1<<M)-1][1]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
