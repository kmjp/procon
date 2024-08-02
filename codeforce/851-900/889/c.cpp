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
int S[555];
const ll mo=1000000007;

ll memo[505][505];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}
ll hoge(int a,int b) {
	if(memo[a][b]>=0) return memo[a][b];
	if(a==b) return 0;
	if(a==0) return b;
	
	ll ret=(hoge(a-1,b)+1+hoge(a,b-1))*modpow(2)%mo;
	return memo[a][b]=ret;
	
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(memo);
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>S[i];
		S[i]--;
	}
	S[N]=M;
	ll ret=0;
	FOR(i,N) ret+=hoge(M-S[i+1],M-S[i]);
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
