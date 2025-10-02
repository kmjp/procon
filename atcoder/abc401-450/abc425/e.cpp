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

int T;
ll mo;
int N;
int C[5050];

ll PS[20][5050];
ll lef[5050];
map<ll,int> enumpr(ll n) {
	map<ll,int> V;
	for(ll i=2;i*i<=n;i++) while(n%i==0) V[i]++,n/=i;
	if(n>1) V[n]++;
	return V;
}

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T>>mo;
	
	auto M=enumpr(mo);
	vector<int> P;
	ll phi=mo;
	FORR2(a,b,M) {
		P.push_back(a);
		phi=phi/a*(a-1);
	}
	
	lef[1]=1;
	for(i=2;i<=5000;i++) {
		x=i;
		FOR(j,P.size()) {
			PS[j][i]=PS[j][i-1];
			while(x%P[j]==0) {
				PS[j][i]++;
				x/=P[j];
			}
		}
		lef[i]=lef[i-1]*x%mo;
	}
	
	
	
	while(T--) {
		cin>>N;
		int sum=0;
		FOR(i,N) {
			cin>>C[i];
			sum+=C[i];
		}
		vector<int> num(P.size());
		ll ret=lef[sum];
		ll retq=1;
		FOR(j,P.size()) {
			num[j]=PS[j][sum];
		}
		FOR(k,N) {
			(retq*=lef[C[k]])%=mo;
			FOR(j,P.size()) {
				num[j]-=PS[j][C[k]];
			}
		}
		
		ret=ret*modpow(retq,phi-1)%mo;
		FOR(j,P.size()) {
			FOR(x,num[j]) (ret=ret*P[j])%=mo;
		}
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
