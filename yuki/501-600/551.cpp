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

ll mo,P,R;
int Q;
ll A,B,C;


inline int mulmod(int a,int b,int mo) {
	int d,r;
	if(a==0 || b==0) return 0;
	if(a==1 || b==1) return max(a,b);
	__asm__("mull %4;"
	        "divl %2"
		: "=d" (r), "=a" (d)
		: "r" (mo), "a" (a), "d" (b));
	return r;
}

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	a%=mo;
	while(n) {
		if(n&1) r=mulmod(r,a,mo);
		a=mulmod(a,a,mo),n>>=1;
	}
	return r;
}

ll mod_log(ll a,ll b,ll mo) { // a^x=b
	static ll pre_a=-1;
	static unordered_map<ll,int> M;
	static ll a_sq=1;
	static int sq=0;
	int i,j;
	
	if(pre_a!=a) M.clear();
	if(M.empty()) {
		pre_a=a;
		ll ap=1,ar=modpow(a),as=1;
		for(i=0;i*i<mo/8+4;i++) ap=mulmod(ap,ar,mo);
		sq=i;
		for(i=0;i<mo;i+=sq) {
			if(M.count(as)==0) M[as]=i;
			as=mulmod(as,ap,mo);
		}
	}
	
	int c=modpow(b);
	FOR(i,mo) {
		if(M.count(c)) return (mo+M[c]+i)%mo;
		c=mulmod(c,a,mo);
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>P>>R;
	mo=P;
	
	cin>>Q;
	while(Q--) {
		cin>>A>>B>>C;
		ll r=modpow(A);
		A = A*r%mo;
		B = B*r%mo;
		C = C*r%mo;
		
		if(B%2==1) B+=P;
		B/=2;
		C=(P-(C-B*B%P+P)%P)%P;
		
		if(C==0) {
			cout<<(P-B)%mo<<endl;
		}
		else {
			ll a=mod_log(R,C,P);
			if(a%2==1) {
				cout<<-1<<endl;
				continue;
			}
			ll D=modpow(R,a/2);
			
			ll X=(-B+D+2*P)%P;
			ll Y=(-B-D+2*P)%P;
			if(X>Y) swap(X,Y);
			cout<<X<<" "<<Y<<endl;
		}
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
