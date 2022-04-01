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

int H,W;
int A[55],B[55];
ll Ffrom[2555],Fto[2555],Gfrom[2555],Gto[2555],F[2555],G[2555];
ll P[2525];
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1; a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll comb(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>s;
		FORR(c,s) if(c=='1') B[y]++;
	}
	FOR(y,H) {
		cin>>A[y];
	}
	Ffrom[0]=Gfrom[0]=1;
	FOR(y,H) {
		ZERO(Fto);
		ZERO(Gto);
		
		int e1,e0,o1,o0;
		FOR(e1,B[y]+1) {
			o1=B[y]-e1;
			o0=A[y]-e1;
			e0=W-e1-o0-o1;
			if(o1<0||o0<0||e0<0) continue;
			ll pat=comb(e1+o1,e1)*comb(e0+o0,e0)%mo;
			FOR(i,2501) (Fto[i+e1+e0]+=pat*Ffrom[i])%=mo;
		}
		FOR(e1,A[y]+1) {
			o1=o0=A[y]-e1;
			e0=W-e1-o0-o1;
			if(o1<0||o0<0||e0<0) continue;
			ll pat=comb(e1+o1,e1)*comb(e0+o0,e0)%mo;
			FOR(i,2501) (Gto[i+e1+e0]+=pat*Gfrom[i])%=mo;
		}
		
		swap(Ffrom,Fto);
		swap(Gfrom,Gto);
	}
	
	ll p2=1;
	FOR(i,H*W) p2=p2*modpow(2)%mo;
	FOR(i,H*W+1) P[i]=comb(H*W,i)*p2%mo;
	
	for(i=H*W;i>=0;i--) {
		
		FOR(j,H*W+1) {
			(F[j]+=Ffrom[i]*P[j])%=mo;
			(G[j]+=Gfrom[i]*P[j])%=mo;
		}
		
		if(i) {
			//x+1‚ÅŠ„‚é
			FOR(j,H*W) {
				(P[j+1]+=mo-P[j])%=mo;
			}
			assert(P[H*W]==0);
			for(j=H*W-1;j>=0;j--) {
				(P[j+1]+=P[j])%=mo;
				(P[j]=mo-P[j])%=mo;
			}
		}
	}
	ll Fv=F[H*W];
	ll Gv=G[H*W];
	ll dFv=0,dGv=0;
	FOR(i,H*W) {
		ll a=(mo-H*W+2*i)*modpow(H*W)%mo;
		a=modpow(a-1);
		(dFv+=F[i]*a)%=mo;
		(dGv+=G[i]*a)%=mo;
	}
	ll p=((dFv*Gv-Fv*dGv)%mo+mo)%mo;
	ll q=Gv*Gv%mo;
	cout<<(p*modpow(q))%mo<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
