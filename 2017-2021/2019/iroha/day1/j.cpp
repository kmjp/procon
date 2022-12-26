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

int Q;
ll N,K;
ll mo=1000000007;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
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

ll issq(ll V) {
	if(V<0) return -1;
	ll a=sqrt(V);
	if(a*a==V) return a;
	if((a-1)*(a-1)==V) return a-1;
	if((a+1)*(a+1)==V) return a+1;
	return -1;
}

vector<int> sqeq(ll a,ll b,ll c) {
	vector<int> R;
	if(a<0) a=-a,b=-b,c=-c;
	ll D=b*b-4*a*c;
	if(D<0) return R;
	ll S=issq(D);
	if(S==-1) return R;
	if((-b+S)%(2*a)==0) R.push_back((-b+S)/(2*a));
	if((-b-S)%(2*a)==0) R.push_back((-b-S)/(2*a));
	if(R.size()==2 && R[0]==R[1]) R.pop_back();
	return R;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>N>>K;
		
		if(K==0) {
			cout<<2<<endl;
			continue;
		}
		
		ll ret=0;
		
		vector<int> S;
		if(N%2==0) {
			S=sqeq(2,-2*(N/2),K);
		}
		else {
			S=sqeq(2,-2*(N/2)-1,K);
			auto X=sqeq(2,-2*(N/2)+1,-(N/2)+K);
			FORR(x,X) S.push_back(x);
		}
		FORR(x,S) {
			if(x>=0 && x<=N/2) ret+=comb(N/2,x);
		}
		
		cout<<ret%mo<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
