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

int N,S,T;
int U[101010],V[101010];
vector<int> E[101010];
int dp[4][202020];

const int mo=998244353;
ll modpow(ll a, ll n = mo-2) {
	ll r=1; a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

template <class T> using vec=vector<T>; //using vec=valarray<T>;

template<class T> vec<T> fft(vec<T> v, bool rev=false) {
	int n=v.size(),i,j,m;
	for(int m=n; m>=2; m/=2) {
		T wn=modpow(5,(mo-1)/m);
		if(rev) wn=modpow(wn);
		for(i=0;i<n;i+=m) {
			T w=1;
			for(int j1=i,j2=i+m/2;j2<i+m;j1++,j2++) {
				T t1=v[j1],t2=v[j2];
				v[j1]=(t1+t2+mo)%mo;
				v[j2]=ll(t1+mo-t2)*w%mo;
				while(v[j1]>=mo) v[j1]-=mo;
				w=(ll)w*wn%mo;
			}
		}
	}
	for(i=0,j=1;j<n-1;j++) {
		for(int k=n>>1;k>(i^=k);k>>=1);
		if(i>j) swap(v[i],v[j]);
	}
	if(rev) {
		ll rv = modpow(n);
		FOR(i,n) v[i]=(ll)v[i]*rv%mo;
	}
	return v;
}

template<class T> vec<T> MultPoly(vec<T> P,vec<T> Q,bool resize=false,bool recover=false) {
	int len=0;
	if(resize) {
		int maxind=0,pi=-1,qi=-1,i;
		int s=2;
		len=P.size()+Q.size()-1;
		FOR(i,P.size()) if(norm(P[i])) pi=i;
		FOR(i,Q.size()) if(norm(Q[i])) qi=i;
		if(pi==-1||qi==-1) return {};
		maxind=pi+qi+1;
		while(s*2<maxind) s*=2;
		
		if(s<=64) { //fastpath
			vec<T> R(s*2);
			for(int x=0;x<=pi;x++) for(int y=0;y<=qi;y++) (R[x+y]+=P[x]*Q[y])%=mo;
			if(recover) R.resize(len);
			return R;
		}
		vec<T> P2(s*2),Q2(s*2);
		FOR(i,pi+1) P2[i]=P[i];
		FOR(i,qi+1) Q2[i]=Q[i];
		swap(P,P2),swap(Q,Q2);
	}
	P=fft(P), Q=fft(Q);
	for(int i=0;i<P.size();i++) P[i]=(ll)P[i]*Q[i]%mo;
	P=fft(P,true);
	if(resize&&recover) P.resize(len);
	return P;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>T;
	S--,T--;
	FOR(i,N-1) {
		cin>>U[i]>>V[i];
		U[i]--,V[i]--;
		E[U[i]].push_back(V[i]);
		E[V[i]].push_back(U[i]);
	}
	FOR(i,N) dp[0][i]=dp[1][i]=dp[2][i]=dp[3][i]=1<<20;
	queue<int> Q;
	dp[0][U[S]]=0;
	dp[1][V[S]]=0;
	dp[2][U[T]]=0;
	dp[3][V[T]]=0;
	Q.push(U[S]);
	Q.push(N+V[S]);
	Q.push(2*N+U[T]);
	Q.push(3*N+V[T]);
	while(Q.size()) {
		int cur=Q.front()%N;
		int id=Q.front()/N;
		Q.pop();
		FORR(e,E[cur]) if(chmin(dp[id][e],dp[id][cur]+1)) Q.push(id*N+e);
	}
	int mi=1<<20;
	mi=min(mi,dp[0][U[T]]);
	mi=min(mi,dp[1][U[T]]);
	mi=min(mi,dp[0][V[T]]);
	mi=min(mi,dp[1][V[T]]);
	
	{
		queue<vec<ll>> Q;
		Q.push({0,1});
		FOR(i,N) {
			int tmi=1<<20;
			tmi=min(tmi,dp[0][i]+dp[2][i]);
			tmi=min(tmi,dp[1][i]+dp[2][i]);
			tmi=min(tmi,dp[0][i]+dp[3][i]);
			tmi=min(tmi,dp[1][i]+dp[3][i]);
			if(tmi==mi) {
				vector<ll> V={0,1};
				ll f=1;
				x=E[i].size()-2;
				for(j=1;j<=E[i].size()-2;j++) {
					f=f*x--%mo;
					V.push_back(f);
				}
				Q.push(V);
			}
			
			
		}
		while(Q.size()>1) {
			auto a=Q.front();
			Q.pop();
			Q.push(MultPoly(a,Q.front(),1));
			Q.pop();
		}
		vec<ll> V=Q.front();
		V.resize(N+1);
		FOR(i,N) cout<<V[i+1]<<" ";
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
