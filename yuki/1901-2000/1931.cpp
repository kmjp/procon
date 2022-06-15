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
const ll mo=998244353;
ll A[202020],B[202020];
ll C,D;
vector<int> cand[202020];
map<int,int> di[202020];
ll modpow(ll a, ll n = mo-2, ll mo_=mo) {
	ll r=1;a%=mo_;
	while(n) r=r*((n%2)?a:1)%mo_,a=a*a%mo_,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i]>>B[i];
	}
	FOR(i,N) {
		x=B[i];
		for(j=2;j*j<=x;j++) if(x%j==0) {
			cand[j].push_back(i);
			while(x%j==0) x/=j, di[i][j]++;
		}
		if(x>1) cand[x].push_back(i), di[i][x]++;
	}
	ll P=1;
	D=1;
	for(i=2;i<=200000;i++) if(cand[i].size()) {
		int ma=0;
		FORR(c,cand[i]) ma=max(ma,di[c][i]);
		D=D*modpow(i,ma)%mo;
		ll sum=0;
		ll p=modpow(i,ma);
		ll m=p/i*(i-1);
		FORR(c,cand[i]) {
			sum+=A[c]*modpow(i,ma-di[c][i])%p*modpow(B[c]/modpow(i,di[c][i]),m-1,p)%p;
		}
		sum%=p;
		if(sum==0) {
			P=P*p%mo;
		}
		else {
			while(sum%i==0) {
				sum/=i;
				P=P*i%mo;
			}
		}
	}
	FOR(i,N) {
		C+=A[i]*D%mo*modpow(B[i])%mo;
	}
	
	
	cout<<C%mo*modpow(P)%mo<<" "<<D*modpow(P)%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
