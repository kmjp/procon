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

ll N;
int M;
const ll mo=998244353;
ll dp[7020];
vector<ll> P;
vector<int> Q[7020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<ll> D;
	for(ll a=1;a*a<=N;a++) if(N%a==0) {
		D.push_back(a);
		if(a*a!=N) D.push_back(N/a);
	}
	ll a=N;
	for(x=2;1LL*x*x<=a;x++) if(a%x==0) {
		P.push_back(x);
		while(a%x==0) a/=x;
	}
	if(a>1) P.push_back(a);
	
	sort(ALL(D));
	M=D.size();
	dp[0]=1;
	FOR(y,M) {
		ll a=D[y];
		FOR(i,P.size()) {
			x=0;
			while(a%P[i]==0) x++,a/=P[i];
			Q[y].push_back(x);
		}
		
		FOR(x,y) if(D[y]%D[x]==0) {
			ll pat=1;
			FOR(i,P.size()) {
				if(Q[x][i]==Q[y][i]) pat=pat*(Q[x][i]+1)%mo;
			}
			(dp[y]+=dp[x]*pat)%=mo;
		}
	}
	cout<<dp[M-1]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
