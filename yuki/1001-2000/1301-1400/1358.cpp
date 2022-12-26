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
ll A[3];
ll Y;
const ll mo=1000000007;


ll ext_gcd(ll p,ll q,ll& x, ll& y) { // get px+qy=gcd(p,q)
	if(q==0) return x=1,y=0,p;
	ll g=ext_gcd(q,p%q,y,x);
	y-=p/q*x;
	return g;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>A[0]>>A[1]>>A[2]>>Y;
		sort(A,A+3);
		ll a=A[0];
		ll b=A[1];
		ll x2,y2;
		ll g=ext_gcd(a,b,x2,y2);
		ll lca=a*b/g;
		ll ret=0;
		for(i=0;A[2]*i<=Y;i++) {
			ll x=x2;
			ll y=y2;
			ll c=Y-i*A[2];
			
			if(c%g) continue;
			ll c2=c%lca;
			x*=c2/g;
			y*=c2/g;
			if(x<0) {
				ll v=(-x+(b/g)-1)/(b/g);
				x+=v*(b/g);
				c2+=a*v*(b/g);
			}
			
			if(y<0) {
				ll v=(-y+(a/g)-1)/(a/g);
				y+=v*(a/g);
				c2+=b*v*(a/g);
			}
			c2-=(x/(b/g))*lca;
			c2-=(y/(a/g))*lca;
			if(c>=c2) {
				ret+=(c-c2)/lca+1;
				ret%=mo;
			}
		}
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
