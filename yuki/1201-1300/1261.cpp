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

int N,M;
const ll mo=1000000007;
int A[1010101];
int EN[1010101];
vector<int> R[1010101];
int Q,X,Y;
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll hoge(ll a,ll b,ll c,ll m) {
	if(a>b) swap(a,b);
	if(b>c) swap(b,c);
	if(a>b) swap(a,b);
	if(a==c) {
		ll ret=modpow(a,M);
		//comb(m+2,2)
		return ret*((m+2)*(m+1)/2%mo)%mo;
	}
	else if(a==b) {
		ll p=modpow(a,M+1)-modpow(c,M+1)+mo;
		ll q=(mo+c-a)*(a+mo-c)%mo;
		return p*c%mo*modpow(q)%mo;
	}
	else if(b==c) {
		ll p=modpow(a,M+1)-modpow(c,M+1)+mo;
		ll q=(mo+c-a)*(a+mo-c)%mo;
		return p*a%mo*modpow(q)%mo;
	}
	ll A=modpow(a,M+2)*(mo+b-c)%mo;
	ll B=modpow(b,M+2)*(mo+c-a)%mo;
	ll C=modpow(c,M+2)*(mo+a-b)%mo;
	ll ret=A+B+C;
	ll q=(mo+a-b)*(mo+b-c)%mo*(mo+c-a)%mo;
	return ret*modpow(mo-q)%mo;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	M-=3;
	for(i=2;i<=N;i++) {
		cin>>A[i];
		A[i]--;
	}
	ll ret=0;
	for(i=2;i<=N;i++) {
		for(j=2*i;j<=N;j+=i) {
			if(j==N) EN[i]=1;
			if(j<N&&N%j==0) ret+=hoge(A[i],A[j],A[N],M);
			R[j].push_back(i);
		}
	}
	ret%=mo;
	cout<<ret<<endl;
	
	cin>>Q;
	while(Q--) {
		cin>>X>>Y;
		
		if(Y<N) {
			if(EN[Y]) (ret+=hoge(A[X],A[Y],A[N],M))%=mo;
		}
		else {
			FORR(p,R[X]) (ret+=hoge(A[p],A[X],A[N],M))%=mo;
		}
		cout<<ret<<endl;
		if(Y==N) EN[X]=1;
		R[Y].push_back(X);
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
