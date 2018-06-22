#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

int N;
int A[101010];
int P[101010];

const int DI=100;

ll mo=(441LL<<21)+1;
ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}
vector<ll> fft(vector<ll> v, bool rev=false) {
	int n=v.size(),i,j,m;
	
	for(i=0,j=1;j<n-1;j++) {
		for(int k=n>>1;k>(i^=k);k>>=1);
		if(i>j) swap(v[i],v[j]);
	}
	for(int m=2; m<=n; m*=2) {
		ll wn=modpow(5,(mo-1)/m);
		if(rev) wn=modpow(wn);
		for(i=0;i<n;i+=m) {
			ll w=1;
			for(int j1=i,j2=i+m/2;j2<i+m;j1++,j2++) {
				ll t1=v[j1],t2=w*v[j2]%mo;
				v[j1]=t1+t2;
				v[j2]=t1+mo-t2;
				while(v[j1]>=mo) v[j1]-=mo;
				while(v[j2]>=mo) v[j2]-=mo;
				w=w*wn%mo;
			}
		}
	}
	if(rev) {
		ll rv = modpow(n);
		FOR(i,n) v[i]=v[i]*rv%mo;
	}
	return v;
}


void carry(vector<ll>& V) {
	ll ca=0;
	FORR(c,V) {
		c+=ca;
		ca=0;
		if(c>=DI) {
			ca = c/DI;
			c %= DI;
		}
	}
	while(ca) {
		V.push_back(ca%DI);
		ca/=DI;
	}
		
	while(V.back()==0 && V.size()>1) V.pop_back();
}
vector<ll> MultPoly(vector<ll> P,vector<ll> Q,bool resize=false) {
	if(resize) {
		int maxind=0,pi=0,qi=0,i;
		int s=2;
		FOR(i,P.size()) if(norm(P[i])) pi=i;
		FOR(i,Q.size()) if(norm(Q[i])) qi=i;
		maxind=pi+qi+1;
		while(s*2<maxind) s*=2;
		P.resize(s*2);Q.resize(s*2);
	}
	P=fft(P), Q=fft(Q);
	for(int i=0;i<P.size();i++) P[i]=P[i]*Q[i]%mo;
	P=fft(P,true);
	carry(P);
	return P;
}
vector<ll> AddPoly(vector<ll> P,vector<ll> Q) {
	int i,m=max(P.size(),Q.size());
	vector<ll> R(m+1);
	FOR(i,m) {
		if(i<P.size()) R[i]+=P[i];
		if(i<Q.size()) R[i]+=Q[i];
		if(R[i]>=DI) {
			R[i]-=DI;
			R[i+1]++;
		}
	}
	while(R.back()==0 && R.size()>1) R.pop_back();
	return R;
}

pair<vector<ll>,vector<ll>> hoge(int L,int R) {
	vector<ll> ret,F;
	if(R-L==1) {
		F.push_back(max(1,L));
		ret.push_back(F[0]*P[L]);
		carry(F);
		carry(ret);
	}
	else {
		int M=(L+R)/2;
		auto LL=hoge(L,M);
		auto RR=hoge(M,R);
		auto a=MultPoly(RR.first,LL.second,true);
		ret=AddPoly(LL.first,a);
		F=MultPoly(RR.second,LL.second,true);
	}
	return {ret,F};
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	for(i=N-1;i>=0;i--) {
		P[N-i-1]=bt(A[i]);
		bt.add(A[i],1);
	}
	auto ret=AddPoly(hoge(0,N).first,vector<ll>(1,1));
	
	
	reverse(ALL(ret));
	int first=1;
	FORR(c,ret) {
		if(first==1) {
			if(c==0) continue;
			_P("%lld",c);
			first=0;
		}
		else {
			_P("%02lld",c);
		}
	}
	_P("\n");
	//cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
