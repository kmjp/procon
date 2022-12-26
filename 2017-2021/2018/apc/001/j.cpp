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

ll a,b,c,A,B,C;
ll mo=1000000007;
const int CN=401;
ll C_[CN][CN];
ll pat[101][101];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll hoge1d(int a,int A) {
	return a;
}
ll hoge2d(int a,int A,int b,int B) {
	ll ret=0;
	// 2planes
	ret-=a*b;
	// 1planes
	ret+=a*modpow(hoge1d(b,B),A/a);
	ret+=b*modpow(hoge1d(a,A),B/b);
	return (ret+mo)%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,CN) for(j=0;j<=i;j++) C_[i][j]=(j==0||j==i)?1:(C_[i-1][j-1]+C_[i-1][j])%mo;

	cin>>a>>b>>c>>A>>B>>C;
	if(A%a || B%b || C%c) return _P("0\n");
	
	ll ret=0;
	// 3planes
	ret=a*b*c;
	// 2planes
	ret-=a*b*modpow(hoge1d(c,C),A/a*B/b);
	ret-=b*c*modpow(hoge1d(a,A),B/b*C/c);
	ret-=c*a*modpow(hoge1d(b,B),C/c*A/a);
	// 1planes
	ret+=a*modpow(hoge2d(b,B,c,C),A/a);
	ret+=b*modpow(hoge2d(c,C,a,A),B/b);
	ret+=c*modpow(hoge2d(a,A,b,B),C/c);
	ret=(ret%mo+mo)%mo;
	
	// nontribial
	int p,q,p2,q2;
	for(p=A/a;p>=1;p--) for(q=B/b;q>=1;q--) {
		pat[p][q]=C_[A/a][p]*C_[B/b][q]%mo*modpow(c,(A/a-p)*(B/b-q))%mo;
		for(p2=p;p2<=A/a;p2++) for(q2=q;q2<=B/b;q2++) {
			if(p==p2 && q==q2) continue;
			pat[p][q] -= pat[p2][q2]*C_[p2][p]%mo*C_[q2][q]%mo;
		}
		pat[p][q]=(pat[p][q]%mo+mo)%mo;
		ll way=modpow(modpow(b,p)+modpow(a,q)+mo-1,C/c)-modpow(modpow(b,p),C/c)-modpow(modpow(a,q),C/c)+1;
		if(p<A/a && q<B/b) (ret+=a*b*c*(way%mo+mo)%mo*pat[p][q])%=mo;
	}
	
	
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
