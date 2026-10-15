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
ll P[101010],Q[101010];
ll M[101010];
vector<int> E[101010];
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>P[i]>>Q[i];
			E[i].clear();
			P[i]=P[i]*modpow(Q[i])%mo;
		}
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		if(N==1) {
			cout<<0<<endl;
			continue;
		}
		ll ret=0;
		ll sum=0;
		FOR(i,N) {
			M[i]=1;
			FORR(e,E[i]) (M[i]*=P[e])%=mo;
			// M[i]:=—×Ú‚ª‘S•”Á‚¦‚é
			Q[i]=0;
			// Q[i]:—t‚Æ‚È‚éŠm—¦
			FORR(e,E[i]) (Q[i]+=M[i]*modpow(P[e])%mo*(mo+1-P[e]))%=mo;
			(Q[i]*=(1-P[i]))%=mo;
			(ret+=Q[i]*sum)%=mo;
			(sum+=Q[i])%=mo;
		}
		
		//—×Ú
		FOR(i,N) FORR(e,E[i]) if(i<e) {
			(ret-=Q[i]*Q[e])%=mo;
			(ret+=(1-P[i])*(1-P[e])%mo*(M[i]*modpow(P[e])%mo)%mo*(M[e]*modpow(P[i])%mo))%=mo;
		}
		//‹——£2
		FOR(i,N) {
			ll sum=0;
			FORR(e,E[i]) {
				(ret-=sum*Q[e])%=mo;
				(sum+=Q[e])%=mo;
			}
			//e1-i-e2
			ll p1=0;
			sum=0;
			FORR(e,E[i]) {
				ll a=M[e]*modpow(P[i])%mo*(1-P[e])%mo;
				(p1+=sum*a)%=mo;
				(sum+=a)%=mo;
			}
			(ret+=(1-P[i])*p1)%=mo;
			// e1-x-e2
			p1=0;
			sum=0;
			FORR(e,E[i]) {
				ll a=Q[e]-(1-P[e])*M[e]%mo*modpow(P[i])%mo*(1-P[i])%mo;
				(a*=modpow(P[i]))%=mo;
				(p1+=sum*a)%=mo;
				(sum+=a)%=mo;
			}
			(ret+=P[i]*p1)%=mo;
			
		}
		
		
		cout<<(ret%mo+mo)%mo<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
