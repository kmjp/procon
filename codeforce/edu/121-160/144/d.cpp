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
ll K,X;
ll A[202020];
ll S[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K>>X;
		FOR(i,N) {
			cin>>A[i];
			S[i+1]=S[i]+A[i];
		}
		ll ma=0;
		if(X>=0) {
			FOR(i,N) {
				ll s=0;
				for(j=0;j<K&&i+j<N;j++) {
					s+=A[i+j]+X;
					ma=max(ma,s);
				}
			}
			ll mi=0;
			FOR(i,N) {
				A[i]-=X;
				S[i+1]=S[i]+A[i];
				if(i+1>=K) {
					mi=min(mi,S[i+1-K]);
					ma=max(ma,S[i+1]-mi+2*K*X);
				}
			}
			
		}
		else {
			FOR(i,N) {
				for(j=N-K;i+j<=N;j++) {
					ll a=S[i+j]-S[i]-1LL*(N-K)*X+(j-(N-K))*X;
					ma=max(ma,a);
				}
			}
			for(i=0;i+N-K<=N;i++) {
				ll su=0;
				ll mi=0;
				FOR(j,N-K) {
					su+=A[i+j]-X;
					ma=max(ma,su-mi);
					mi=min(mi,su);
				}
			}
			
		}
		
		cout<<ma<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
