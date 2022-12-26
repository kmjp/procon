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

ll A,B,P,Q;
const ll mo=998244353;

const int MAT=2;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);};};

Mat M[101010];
Mat RM[101010];



ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


ll modlog(int g,int a) {  // return g^x=a mod a
	map<int,int> M;
	ll cur=1;
	int sq=sqrt(mo);
	int i;
	FOR(i,sq) {
		M[cur]=i;
		cur=cur*g%mo;
	}
	
	ll step=cur;
	cur=1;
	ll num=0;
	int lp=0;
	while(1) {
		ll x=a*modpow(cur)%mo;
		if(lp++>sq+5) return 1LL<<50;
		if(M.count(x)) return num+M[x];
		cur=cur*step%mo;
		num+=sq;
	}
}

Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	ll mo2=4*mo*mo;
	int x,y,z; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(x,n) FOR(z,n) FOR(y,n) {
		r.v[x][y] += a.v[x][z]*b.v[z][y];
		if(r.v[x][y]>mo2) r.v[x][y] -= mo2;
	}
	FOR(x,n) FOR(y,n) r.v[x][y]%=mo;
	return r;
}

Mat powmat(ll p,Mat a,int n=MAT) {
	int i,x,y; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(i,n) r.v[i][i]=1;
	while(p) {
		if(p%2) r=mulmat(r,a,n);
		a=mulmat(a,a,n);
		p>>=1;
	}
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>P>>Q;
	
	if(B==0) {
		x = modlog(A,P);
		if(x<2) x+=mo-1;
		cout<<x<<endl;
	}
	else {
		map<pair<ll,ll>,int> mp;
		
		M[0].v[0][0]=M[0].v[1][1]=1;
		M[1].v[0][0]=A;
		M[1].v[1][0]=1;
		M[1].v[0][1]=mo-B;
		
		for(i=0;i<=100000;i++) {
			if(i>1) {
				M[i]=mulmat(M[i-1],M[1]);
			}
			
			ll p=(2*M[i].v[0][0]+A*modpow(B)%mo*M[i].v[0][1])%mo;
			ll q=(2*M[i].v[1][0]+A*modpow(B)%mo*M[i].v[1][1])%mo;
			
			if(i>=2&&p==P&&q==Q) {
				cout<<i<<endl;
				return;
			}
			mp[{p,q}]=i;
			
		}
		
		
		RM[0]=M[0];
		ll rb=modpow(B);
		RM[1].v[1][1]=A*rb%mo;
		RM[1].v[0][1]=1;
		RM[1].v[1][0]=(mo-1)*rb%mo;
		RM[1]=powmat(100000,RM[1]);
		for(i=1;i<=100000;i++) {
			if(i>1) {
				RM[i]=mulmat(RM[i-1],RM[1]);
			}
			ll p=(P*RM[i].v[0][0]+Q*RM[i].v[0][1])%mo;
			ll q=(P*RM[i].v[1][0]+Q*RM[i].v[1][1])%mo;
			
			if(mp.count({p,q})) {
				ll ret=i*100000LL+mp[{p,q}];
				cout<<ret<<endl;
				return;
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
