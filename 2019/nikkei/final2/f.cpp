#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


int N,K,M;
int NG[1<<20];
vector<int> jump;

ll pat[1<<20];
ll sum[1<<20];
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


template<class T> vector<T> fft(vector<T> v, bool rev=false) {
	int n=v.size(),i,j,m;
	
	for(i=0,j=1;j<n-1;j++) {
		for(int k=n>>1;k>(i^=k);k>>=1);
		if(i>j) swap(v[i],v[j]);
	}
	for(int m=2; m<=n; m*=2) {
		T wn=modpow(5,(mo-1)/m);
		if(rev) wn=modpow(wn);
		for(i=0;i<n;i+=m) {
			T w=1;
			for(int j1=i,j2=i+m/2;j2<i+m;j1++,j2++) {
				T t1=v[j1],t2=(ll)w*v[j2]%mo;
				v[j1]=t1+t2;
				v[j2]=t1+mo-t2;
				while(v[j1]>=mo) v[j1]-=mo;
				while(v[j2]>=mo) v[j2]-=mo;
				w=(ll)w*wn%mo;
			}
		}
	}
	if(rev) {
		ll rv = modpow(n);
		FOR(i,n) v[i]=(ll)v[i]*rv%mo;
	}
	return v;
}

template<class T> vector<T> MultPoly(vector<T> P,vector<T> Q,bool resize=false) {
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
	for(int i=0;i<P.size();i++) P[i]=(ll)P[i]*Q[i]%mo;
	return fft(P,true);
}

void dfs(int L,int R) {
	if(R<=2) return;
	if(L+1==R) return;
	int M=(L+R)/2;
	int cost=0;
	while(M%(1<<cost)==0) cost++;
	dfs(L,M);
	vector<ll> LP(2*(R-L)),LS(2*(R-L)),J(2*(R-L));
	int i;
	for(i=L;i<M;i++) {
		LP[i-L]=pat[i];
		LS[i-L]=sum[i];
	}
	FORR(j,jump) {
		if(j>=R-L) break;
		J[j]=1;
	}
	vector<ll> RP=MultPoly(LP,J,false);
	vector<ll> RS=MultPoly(LS,J,false);
	for(i=M;i<R;i++) if(NG[i]==0) {
		(pat[i]+=RP[i-L])%=mo;
		(sum[i]+=RS[i-L]+RP[i-L]*cost)%=mo;
	}
	
	dfs(M,R);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>M;
	int ON=N;
	N++;
	while(N&(N-1)) N++;
	FOR(i,K) {
		cin>>x;
		NG[x]=1;
	}
	
	FOR(i,M) {
		cin>>x;
		jump.push_back(x);
	}
	
	pat[1]=1;
	sum[1]=0;
	dfs(0,N);
	cout<<sum[ON]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
