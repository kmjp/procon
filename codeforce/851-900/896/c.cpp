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
ll N,M;
const ll mo=998244353;
ll P[122];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		
		ZERO(P);
		
		
		for(x=0;x<=60;x++) {
			//ã‰º
			
			//depth x‚Ì—v‘f”
			ll L=1LL<<x;
			ll R=min((2LL<<x)-1,N);
			if(R<L) continue;
			// Ž©•ªŽ©g
			(P[1]+=(R-L+1))%=mo;
			
			for(y=x+1;y<=60;y++) {
				ll L2=1LL<<y;
				ll R2=min((2LL<<y)-1,N);
				if(R2<L2) continue;
				P[y-x+1]+=(R2-L2+1);
				
			}
			
			for(y=x+1;y<=60;y++) {
				//¶‘¤‚Ì”
				ll L2=1LL<<y;
				ll R2=min((2LL<<y)-1,N);
				if(R2<L2) continue;
				R2++;
				ll d=1LL<<(y-x-1);
				ll Ln=(R2-L2)>>(y-x);
				ll Ld=min((R2-L2)%(1LL<<(y-x)),1LL<<(y-x-1));
				
				for(k=x+1;k<=60;k++) {
					ll L3=1LL<<k;
					ll R3=min((2LL<<k)-1,N);
					if(R3<L3) continue;
					R3++;
					ll d=1LL<<(k-x-1);
					ll Rn=(R3-L3)>>(k-x);
					ll Rd=max(0LL,(R3-L3)%(1LL<<(k-x))-(1LL<<(k-x-1)));
					P[y-x+k-x+1]+=min(Ln,Rn)%mo*((1LL<<(y-x-1))%mo)%mo*((1LL<<(k-x-1))%mo)%mo;
					if(Ln==Rn) P[y-x+k-x+1]+=(Ld%mo)*(Rd%mo)%mo;
					if(Ln>Rn) P[y-x+k-x+1]+=((1LL<<(y-x-1))%mo)*(Rd%mo)%mo;
					if(Ln<Rn) P[y-x+k-x+1]+=((1LL<<(k-x-1))%mo)*(Ld%mo)%mo;
					P[y-x+k-x+1]%=mo;
					//cout<<P[y-x+k-x+1]<<endl;
				}
			}
		}
		
		ll ret=0;
		FOR(i,121) if(P[i]) {
			ll pre=0;
			ll oth=modpow(M,N-i)*(P[i]%mo)%mo;
			
			for(j=1;j<=M;j++) {
				ll a=modpow(j,i);
				ret+=oth*j%mo*(a-pre)%mo;
				pre=a;
			}
		}
		ret=(ret%mo+mo)%mo;
		cout<<ret<<endl;
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
