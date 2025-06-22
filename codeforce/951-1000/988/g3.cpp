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
int A[202020];
const ll mo=998244353;

ll dp[1010101];

set<ll> enumpr(ll n) {
	set<ll> V;
	for(ll i=2;i*i<=n;i++) while(n%i==0) V.insert(i),n/=i;
	if(n>1) V.insert(n);
	return V;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		auto a=enumpr(x);
		vector<int> V;
		FORR(b,a) V.push_back(b);
		int mask;
		y=V.size();
		
		ll sum=0;
		if(i==0) {
			sum=1;
		}
		else {
			FOR(mask,1<<y) if(mask) {
				x=1;
				FOR(j,y) if(mask&(1<<j)) x*=V[j];
				sum+=dp[x];
			}
			sum%=mo;
		}
		if(i==N-1) {
			cout<<sum<<endl;
		}
		FOR(mask,1<<y) if(mask) {
			x=1;
			FOR(j,y) if(mask&(1<<j)) x*=V[j];
			if(__builtin_popcount(mask)%2==0) {
				(dp[x]+=mo-sum)%=mo;
			}
			else {
				(dp[x]+=sum)%=mo;
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
