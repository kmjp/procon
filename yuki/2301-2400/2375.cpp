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

int N,A,B;
int X[55],Y[55],K[55];
int dp[1<<14][14][14];

int dist(int a,int b) {
	return abs(X[a]-X[b])+abs(Y[a]-Y[b]);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B;
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>K[i];
		dp[1<<i][i][i]=1;
	}
	int ma=0;
	int mask;
	FOR(mask,1<<N) FOR(x,N) FOR(y,N) if(dp[mask][x][y]) {
		ma=max(ma,__builtin_popcount(mask));
		FOR(i,N) if((mask&(1<<i))==0) {
			int ok=0;
			if(dist(y,i)>=A) ok=1;
			if(abs(K[i]-K[y])>=B) ok=1;
			if(x!=y&&dist(y,i)+dist(x,i)>=A) ok=1;
			dp[mask|(1<<i)][y][i]|=ok;
		}
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
