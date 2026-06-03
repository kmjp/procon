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
ll N;

ll V;
ll dp[20][10][2];
ll p10[19];

ll dfs(int d,int ma,int le) {
	if(d<0) return ma;
	if(dp[d][ma][le]>=0) return dp[d][ma][le];
	ll ret=0;
	int i;
	int v=V/p10[d]%10;
	FOR(i,10) {
		if(le==0&&i>v) break;
		ret+=dfs(d-1,max(ma,i),le|(i<v));
	}
	return dp[d][ma][le]=ret;
	
}

map<ll,ll> M;

ll hoge(ll v) {
	if(M.count(v)) return M[v];
	
	V=v;
	MINUS(dp);
	return M[v]=dfs(18,0,0);
}

ll hoge2(ll v) {
	int ma=0;
	while(v) ma=max(ma,(int)(v%10)),v/=10;
	return ma;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p10[0]=1;
	FOR(i,18) p10[i+1]=p10[i]*10;
		
	cin>>T;
	while(T--) {
		cin>>N;
		if(N<100) {
			ll R=0;
			ll L=1;
			ll U=0;
			while(1) {
				while(U>N) U-=hoge2(L++);
				if(U==N) break;
				U+=hoge2(++R);
			}
			cout<<L<<" "<<R<<endl;
			assert(hoge(R)-hoge(L-1)==N);
		}
		else {
			ll a=888888888888888889LL;
			ll a9=(N+8)/9;
			ll a8=9*a9-N;
			a9-=a8;
			assert(a8*8+a9*9==N);
			ll L=a-a8;
			ll R=a+(a9-1);
			cout<<L<<" "<<R<<endl;
			assert(hoge(R)-hoge(L-1)==N);
			
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
