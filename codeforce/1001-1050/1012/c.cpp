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

int T,N,L,K;
const ll mo=1000000007;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll from[27][101];
ll to[27][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		ZERO(from);
		cin>>N>>L>>K;
		for(l=1;l<=L;l++) {
			ZERO(to);
			FOR(k,K+1) {
				// ‰Žè¬Œ÷Šm—¦
				int p=modpow(l+k);
				(to[k][0]+=p)%=mo;
				FOR(x,N) (to[k][(x+1)%N]+=p*from[k][x])%=mo;
				int kp=(1LL+mo-p)*(l+k-1)%mo*modpow(2*l+k-2)%mo; //Œ®ŒðŠ·
				int lp=(1LL+mo-p)*(l-1)%mo*modpow(2*l+k-2)%mo; //ùŒðŠ·
				
				ll dp2[202]={};
				if(lp) {
					int p=lp*modpow(l+k-1)%mo;
					//‚¢‚¸‚ê“–‚½‚é
					dp2[0]+=1LL*p*((l-1)/N)%mo;
					dp2[N]-=1LL*p*((l-1)/N)%mo;
					dp2[1]+=p;
					dp2[1+(l-1)%N]+=mo-p;
					
					FOR(x,N) {
						y=(x+2)%N;
						dp2[0]+=1LL*p*((l-1)/N)%mo*from[k][x]%mo;
						dp2[N]+=mo-1LL*p*((l-1)/N)%mo*from[k][x]%mo;
						dp2[y]+=p*from[k][x]%mo;
						dp2[y+(l-1)%N]+=mo-p*from[k][x]%mo;
						
					}
					if(k) {
						ll fail=1LL*p*k%mo;
						FOR(x,N) (to[k][(x+l)%N]+=fail*to[k-1][x])%=mo;
					}
				}
				if(kp) {
					//‚¢‚¸‚ê“–‚½‚é
					int p=kp*modpow(l+k-1)%mo;
					dp2[0]+=1LL*p*((l+k-1)/N)%mo;
					dp2[N]-=1LL*p*((l+k-1)/N)%mo;
					dp2[1]+=p;
					dp2[1+(l+k-1)%N]+=mo-p;
					
					FOR(x,N) {
						y=(x+2)%N;
						dp2[0]+=1LL*p*((l+k-1)/N)%mo*from[k][x]%mo;
						dp2[N]+=mo-1LL*p*((l+k-1)/N)%mo*from[k][x]%mo;
						dp2[y]+=p*from[k][x]%mo;
						dp2[y+(l+k-1)%N]+=mo-p*from[k][x]%mo;
						
					}
				}
				FOR(x,2*N) {
					(to[k][x%N]+=dp2[x])%=mo;
					(dp2[x+1]+=dp2[x])%=mo;
				}
			}
			swap(from,to);
			/*
			FOR(k,K+1) {
				cout<<l<<" "<<k<<" ";
				FOR(x,N) cout<<from[k][x]<<" ";
				cout<<endl;
			}
			*/
		}
		
		FOR(i,N) cout<<from[K][i]<<" ";
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
