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
ll mo;
ll p2[5050];
ll ok[5050];

__int128 dp[5050];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>mo;
	
	p2[0]=1;
	FOR(i,5010) p2[i+1]=p2[i]*2%mo;
	
	ok[1]=ok[2]=1;
	for(i=3;i<=N;i++) {
		if(i>2501&&i!=N) continue;
		ZERO(dp);
		for(j=1;2*j<i;j++) {
			dp[2*j+1]=ok[j];
		}
		ll ng=0;
		for(j=1;j<=i;j++) {
			(dp[j]+=dp[j-1])%=mo;
			dp[j]%=mo;
			for(x=1;j+3*x+1<i;x++) {
				(dp[j+3*x+1]+=dp[j]*ok[x]);
			}
			if((i-j)%2==0) 	(ng+=(ll)dp[j]*ok[(i-j)/2])%=mo;
		}
		(ok[i]=p2[i-2]+mo-ng)%=mo;

	}
	
	cout<<ok[N]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
