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

const int prime_max = 2000000;
int MU[prime_max+1];
int num[prime_max+1];

void mebius() {
	int i,j;
	for(i=1;i<=prime_max;i++) MU[i]=1, num[i]=i;
	for(int i=2;i<=prime_max;i++) if(num[i]==i) {
		for(j=i;j<=prime_max;j+=i) {
			int x=0;
			MU[j]=-MU[j];
			while(num[j]%i==0) {
				x++;
				num[j]/=i;
			}
			if(x>=2) MU[j]=0;
		}
	}
}
ll N;


ll G(ll N) {
	if(N<12) return 0;
	ll V=pow(N,1.0/3.0);
	ll B=N/V;
	ll sum=0;
	for(ll m=1;2*(m+1)*(2*m+1)<=B;m++) {
		ll s;
		for(s=1;2*(m+s)*(2*m+s)<=B;s++) sum+=N/(2*(m+s)*(2*m+s));
	}
	vector<ll> X;
	for(ll i=1;i<=N/B;i++) {
		ll cnt=0;
		ll s=0;
		for(ll m=1;2*(m+1)*(2*m+1)<=N/i;m++) {
			while(2*(m+s+1)*(2*m+s+1)<=N/i) s++;
			while(2*(m+s)*(2*m+s)>N/i) s--;
			cnt+=s;
		}
		X.push_back(cnt);
	}
	
	for(ll i=1;i<N/B;i++) sum+=i*(X[i-1]-X[i]);
	return sum;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	mebius();

	ll ret=0;
	for(ll a=1;a*a<=N;a+=2) if(MU[a]) ret+=MU[a]*(G(N/(a*a))-G(N/(2*a*a)));
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
