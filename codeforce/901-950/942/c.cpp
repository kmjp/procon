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

int T,N;
ll K,B[202020],C[202020];
const ll mo=998244353;

ll modpow(ll a, ll n=mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll comb(ll P_,ll Q_) {
	if(P_<0 || Q_<0 || Q_>P_) return 0;
	ll p=1,q=1;
	Q_=min(Q_,P_-Q_);
	P_%=mo;
	for(int i=1;i<=Q_;i++) p=p*P_%mo, q=q*i%mo,P_--;
	
	return p*modpow(q,mo-2)%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N) cin>>B[i+1];
		vector<ll> cand;
		FOR(i,20) {
			cand.push_back(comb(K+i-1,i));
		}
		FOR(i,20) {
			for(j=N;j>=1;j--) if(((j)>>i<<i)==(j)&&((j)>>i)%2) {
				int cur=j;
				int step=1;
				for(x=0;x<=19;x++) if(cur<=N) {
					if(cur&(1<<(i+x))) {
						cur+=1<<(i+x);
						if(cur<=N) {
							(B[cur]+=mo-B[j]*cand[step++]%mo)%=mo;
						}
					}
				}
			}
		}
		FOR(j,N) cout<<B[j+1]<<" ";
		cout<<endl;
		
		
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
