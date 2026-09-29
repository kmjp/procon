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
ll L,R;
ll N;

ll C[64][64];
ll dp[64];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(y,64) {
		FOR(x,y+1) {
			if(x==0||x==y) C[y][x]=1;
			else C[y][x]=C[y-1][x]+C[y-1][x-1];
		}
	}
	
	
	
	cin>>T;
	while(T--) {
		cin>>L>>R;
		
		R++;
		ZERO(dp);
		while(L<R) {
			//L‚ÌÅ¬ƒrƒbƒg
			ll a=L&(-L);
			//R-L
			ll b=1;
			while(b*2<=R-L) b*=2;
			a=min(a,b);
			int p=__builtin_popcountll(L);
			x=0;
			while(a>>(x+1)<<(x+1)==a) x++;
			FOR(i,x+1) dp[p+i]+=C[x][i];
			for(i=60;i>=0;i--) dp[i]=max(dp[i],dp[i+1]);
			L+=a;
		}
		
		cout<<dp[0]<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
