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
int X[202020];
const ll mo=924844033;
ll fact[202020];

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
		
		if(s<=256) { //fastpath
			vector<T> R(s*2);
			for(int x=0;x<2*s;x++) for(int y=0;x+y<2*s;y++) (R[x+y]+=P[x]*Q[y])%=mo;
			return R;
		}
		
	}
	P=fft(P), Q=fft(Q);
	for(int i=0;i<P.size();i++) P[i]=(ll)P[i]*Q[i]%mo;
	return fft(P,true);
}
pair<int,vector<vector<ll>>> merge(pair<int,vector<vector<ll>>>& A,pair<int,vector<vector<ll>>>& B) {
	int x,y,i;
	pair<int,vector<vector<ll>>> ret;
	ret.first=A.first;
	
	FOR(y,2) FOR(x,2){
		vector<ll> P=MultPoly(A.second[x],B.second[y*2],1);
		if(X[B.first-1]!=X[B.first]) {
			vector<ll> Q=MultPoly(A.second[x+2],B.second[y*2+1],1);
			if(P.size()<Q.size()+1) P.resize(Q.size()+1);
			FOR(i,Q.size()) (P[i+1]+=Q[i])%=mo;
		}
		ret.second.push_back(P);
	}
	
	return ret;
	
}

vector<pair<int,vector<vector<ll>>>> V;
vector<pair<int,vector<vector<ll>>>> W;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		X[x-1]=1;
	}
	FOR(i,N) {
		vector<vector<ll>> A;
		A.push_back({1,(X[i*2]!=X[i*2+1])});
		A.push_back({1,0});
		A.push_back({1,0});
		A.push_back({1,0});
		V.push_back({i*2,A});
	}
	while(V.size()>1) {
		W.clear();
		FOR(i,(V.size()+1)/2) {
			if(i*2+1==V.size()) {
				W.push_back(V[i*2]);
			}
			else {
				W.push_back(merge(V[i*2],V[i*2+1]));
			}
		}
		swap(V,W);
	}
	
	fact[0]=1;
	FOR(i,201010) fact[i+1]=fact[i]*(i+1)%mo;
	vector<ll> A=V[0].second[0];
	ll ret=0;
	FOR(i,A.size()) if(i<=N) {
		A[i]=A[i]*fact[N-i]%mo;
		if(i%2==0) ret+=A[i];
		else ret+=mo-A[i];
	}
	cout<<ret%mo<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
