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

ll N,M,L;
int A[101010];
int B[101010];
ll S[201010];

ll hoge(ll N,ll L) {
	
	ll sum=0;
	int i;
	FOR(i,N) sum+=B[i];
	FOR(i,2*N) {
		S[i+1]=S[i]+B[(__int128)i*L%N];
	}
		
	ll ret=0;
	ll M2=M%L;
	if(M2) {
		ret=-1LL<<60;
		if(L<=N) {
			FOR(i,N) {
				ll x=(__int128)i*L%N;
				if(x<L) {
					ll y=(1LL*N*M2-x-1)/L;
					ret=max(ret,S[i+y+1]-S[i]);
					
				}
			}
		}
		else {
			FOR(i,N) {
				ll x=(__int128)i*L%N;
				vector<ll> cand={M2,M2-(L/N-(x>=(L%N)))};
				FORR(c,cand) {
					if(c<=0) {
						ret=max(ret,0LL);
					}
					else {
						ll y=((__int128)N*c-x-1)/L;
						ret=max(ret,S[i+y+1]-S[i]);
					}
				}
			}
		}
	}
	return ret+(sum*(M/L));
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>L;
	FOR(i,N) cin>>A[i];
	int g=__gcd(N,L);
	ll ret=-1LL<<60;
	FOR(i,g) {
		FOR(j,N/g) B[j]=A[j*g+i];
		ret=max(ret,hoge(N/g,L/g));
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
