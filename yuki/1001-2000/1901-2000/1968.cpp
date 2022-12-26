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
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	ll ret=0;
	FOR(i,55) {
		ll L=1;
		ll R=1LL<<i;

		ll a=modpow(1+(2LL<<i));
		ll b=modpow(1+(1LL<<i));
		if(R>N) {
			// x=0...1/(1+(1LL<<i)) 1/2*x^2
			//cout<<"!!"<<modpow(b)<<endl;
			ret+=b*b%mo*modpow(2)%mo;
			break;
		}
		ll n=N;
		ll di=2;
		
		//cout<<modpow(a)<<" "<<modpow(b)<<endl;
		n-=R-1;
		while(n>0) {
			n-=R;
			R*=2;
			if(n<=0) {
				//cout<<"!"<<R<<endl;
				// int((1-x)/R)=(x-1/2*x^2)/R
				ret+=(b-b*b%mo*modpow(2))%mo*modpow(R)%mo;
				ret+=mo-(a-a*a%mo*modpow(2))%mo*modpow(R)%mo;
				break;
			}
			
			n-=L;
			L*=2;
			if(n<=0) {
				// x
				//cout<<"!!!"<<L<<endl;
				ret+=b*b%mo*modpow(2*L)%mo;
				ret+=mo-a*a%mo*modpow(2*L)%mo;
				break;
			}
			
		}
		
		
	}
	
	cout<<(ret%mo+mo)*2%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
