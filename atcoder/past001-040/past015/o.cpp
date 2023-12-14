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
ll A,B;

const int prime_max = 1000100;
vector<int> prime;
int NP,divp[prime_max];
map<ll,int> M;

ll ext_gcd(ll p,ll q,ll& x, ll& y) { // get px+qy=gcd(p,q)
	if(q==0) return x=1,y=0,p;
	ll g=ext_gcd(q,p%q,y,x);
	y-=p/q*x;
	return g;
}

pair<ll,ll> crt(ll a1,ll mo1,ll a2,ll mo2) { // return (x,y) y=lcm(a1,a2),x%mo1=a1,x%mo2=a2
	ll g,x,y,z;
	g=ext_gcd(mo1,mo2,x,y);
	a1=(a1%mo1+mo1)%mo1;a2=(a2%mo2+mo2)%mo2;
	if(a1%g != a2%g) return pair<ll,ll>(-1,0); // N/A
	__int128_t lcm=mo1*(mo2/g);
	if(lcm<mo1) return pair<ll,ll>(-2,0); // overflow
	if(x<lcm) x+=lcm;
	
	__int128_t v=a1+((a2-a1)%lcm+lcm)*x%lcm*(mo1/g);
	return make_pair(((v%lcm)+lcm) % lcm,lcm);
}

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

int P[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	
	cin>>N>>A>>B;
	FOR(i,N) P[i]=1;
	FORR(p,prime) {
		auto a=crt(0,p,B%A,A);
		if(a.first<0) continue;
		ll m=a.first;
		ll lcm=a.second;
		m=m+(B-m+lcm-1)/lcm*lcm;
		
		ll x=(m-B)/A;
		while(x<N) {
			P[x]=0;
			x+=lcm/A;
		}
	}
	
	
	int ret=0;
	FOR(i,N) if(M.count(A*i+B)||P[i]) ret++;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
