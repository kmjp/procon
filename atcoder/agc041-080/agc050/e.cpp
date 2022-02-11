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

const ll mo=998244353;
ll X[3],Y[3],Z[3],A[3];
ll g,a,b,c;
map<ll,int> D[3];

map<ll,int> enumpr(ll n) {
	map<ll,int> V;
	for(ll i=2;i*i<=n;i++) while(n%i==0) V[i]++,n/=i;
	if(n>1) V[n]++;
	return V;
}


ll num(ll v) {
	ll step=g*a*b;
	ll ret=(X[0]/step)%mo*(v%mo)+(v/step)%mo*(X[0]%step%mo)%mo+min(v%step,X[0]%step);
	return ret%mo;
}

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ll G=0;
	FOR(i,3) {
		cin>>X[i]>>Y[i];
		Z[i]=X[i]+Y[i];
		D[i]=enumpr(Z[i]);
	}
	
	
	FOR(i,3) {
		A[i]=Z[i];
		FORR2(d,n,D[i]) {
			x=n-max(D[(i+1)%3][d],D[(i+2)%3][d]);
			FOR(j,x) A[i]/=d;
		}
		g=__gcd(g,A[i]);
	}
	FOR(i,3) {
		FOR(j,2) if(A[j]>A[j+1]) {
			swap(A[j],A[j+1]);
			swap(X[j],X[j+1]);
			swap(Y[j],Y[j+1]);
			swap(Z[j],Z[j+1]);
			swap(D[j],D[j+1]);
		}
	}
	a=__gcd(A[0]/g,A[1]/g);
	b=__gcd(A[0]/g,A[2]/g);
	c=__gcd(A[1]/g,A[2]/g);
	
	vector<pair<ll,ll>> ev;
	ll na=g*a*b;
	ll nb=g*a*c;
	ll nc=g*b*c;
	
	ll cb=X[1]/nb;
	ll cc=X[2]/nc;
	FOR(i,b) {
		ev.push_back({nb*i,0});
		ev.push_back({nb*i+X[1]%nb,1});
	}
	FOR(i,a) {
		ev.push_back({nc*i,2});
		ev.push_back({nc*i+X[2]%nc,3});
	}
	ev.push_back({nb*b,0});
	
	
	
	ll ret=0;
	ll pre=0;
	sort(ALL(ev));
	FORR2(t,m,ev) {
		ll p=(cb%mo)*(cc%mo)%mo;
		ll q=num(t)-num(pre)+mo;
		(ret+=p*q)%=mo;
		pre=t;
		if(m==0) cb++;
		if(m==1) cb--;
		if(m==2) cc++;
		if(m==3) cc--;
	}
	ret%=mo;
	(ret*=A[0]%mo)%=mo;
	(ret*=A[1]%mo)%=mo;
	(ret*=A[2]%mo)%=mo;
	(ret*=modpow(g))%=mo;
	(ret*=modpow(a))%=mo;
	(ret*=modpow(b))%=mo;
	(ret*=modpow(c))%=mo;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
