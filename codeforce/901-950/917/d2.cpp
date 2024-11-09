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

int T,N,K;
int P[202020];
int Q[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> Ps[19],Qs;
const ll mo=998244353;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		
		ll ret=0;
		FOR(i,N) cin>>P[i];
		FOR(i,K) {
			cin>>Q[i];
			// “¯ˆêP“à
			(ret+=1LL*N*(Qs(K)-Qs(Q[i])))%=mo;
			Qs.add(Q[i],1);
		}
		
		// Q‚ª18ˆÈã‚Ìê‡•K‚¸Ÿ‚Â
		if(K>=20) {
			ret+=1LL*N*(N-1)/2%mo*(1LL*(K-19)*(K-19+1)/2%mo)%mo;
			ret%=mo;
		}
		FOR(i,N) {
			for(j=-18;j<=18;j++) {
				ll pat=K-abs(j);
				if(pat<=0) continue;
				if(j>=0) {
					ll tar=min(2*N+1LL,(ll)P[i]<<j);
					(ret+=1LL*pat*(Ps[0](2*N+1LL)-Ps[0](tar)))%=mo;
				}
				else {
					(ret+=1LL*pat*(Ps[-j]((1<<19)-1)-Ps[-j](P[i])))%=mo;
				}
			}
			FOR(j,19) {
				ll a=min(((1LL<<19)-1),(ll)P[i]<<j);
				Ps[j].add(a,1);
			}
		}
		
		cout<<ret%mo<<endl;
		
		FOR(i,19) {
			for(j=1;j<=2*N-1;j+=2) {
				ll a=min(((1LL<<19)-1),(ll)j<<i);
				Ps[i].add(a,-1);
			}
		}
		FOR(i,K) Qs.add(i,-1);
		
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
