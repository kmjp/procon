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


ll N,M,TM,K;
const ll mo=998244353;
ll H[1<<20][50];
ll p3[50];

int L,R;
ll rev(ll a) {
	return H[a&((1<<R)-1)][0]+(a>>R)*p3[R];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p3[0]=1;
	FOR(i,48) p3[i+1]=p3[i]*3;
	
	cin>>N>>K;
	L=K/2;
	R=K-L;
	TM=M=N;
	FOR(i,K) M=2*M/3;
	FOR(i,R) TM=2*TM/3;
	ll ret=M;
	if(M<=5000000) {
		FOR(i,M) {
			ll cur=i;
			FOR(j,K) cur=(cur*3+2)/2;
			ret+=cur%mo;
		}
	}
	else {
		int mask;
		FOR(mask,1<<R) {
			H[mask][0]=mask;
			FOR(i,R) H[mask][0]=(H[mask][0]*3+2)/2;
		}
		for(i=1;i<=48;i++) {
			FOR(mask,1<<R) {
				if((N>>(i-1))<p3[L]) continue;
				ll f=mask+(p3[L]<<(i-1));
				ll a=f/(1<<R)%mo;
				ll b=f%(1<<R);
				(H[mask][i]=H[mask][i-1]+H[b][i-1]+((a*(p3[R]%mo)%mo)*((1LL<<(i-1))%mo)))%=mo;
			}
		}
		
		ll ss=0;
		FOR(mask,1<<L) {
			ll a=mask;
			FOR(i,L) a=(a*3+2)/2;
			if(rev(a)>=N) continue;
			ll b=a;
			for(i=48;i>=0;i--) {
				if(TM/p3[L]<(1LL<<i)) continue;
				if(b+(1LL<<i)*p3[L]<TM&&rev(b+(1LL<<i)*p3[L])<N) b+=(1LL<<i)*p3[L];
			}
			ll num=(b-a)/p3[L]+1;
			ll s=a;
			
			ss+=num;
			FOR(i,48) if(num&(1LL<<i)) {
				
				int cm=s&((1<<R)-1);
				ll t=s>>R;
				(ret+=H[cm][i]+(((t%mo)*(p3[R]%mo)%mo*((1LL<<i)%mo))))%=mo;
				s+=p3[L]<<i;
			}
			
		}
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
