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
int A[1010];
int did[1010];
vector<int> B[1010];
const ll mo=998244353;
ll P[30303];
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N;
	FOR(i,N-1) cin>>A[i];
	
	ll ret=1;
	for(i=2;i<=1000;i++) if(did[i]==0) {
		for(j=i*2;j<=1000;j+=i) did[j]=1;
		P[0]=1;
		FOR(j,10101) P[j+1]=P[j]*i%mo;
		
		map<int,ll> from,to;
		from[0]=1;
		
		FOR(j,N-1) {
			x=0;
			while(A[j]%i==0) {
				x++;
				A[j]/=i;
			}
			to.clear();
			FORR2(a,b,from) {
				if(x==0) {
					(to[a]+=b*P[a])%=mo;
				}
				else {
					(to[a+x]+=b*P[a+x])%=mo;
					if(a-x>=0) {
						(to[a-x]+=b*P[a-x])%=mo;
					}
					else {
						int add=-(a-x);
						(to[0]+=b*P[add*(j+1)])%=mo;
					}
				}
			}
			
			
			
			swap(from,to);
		}
		ll sum=0;
		FORR2(a,b,from) (sum+=b)%=mo;
		ret=ret*(sum%mo)%mo;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
