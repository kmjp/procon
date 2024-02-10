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

ll N,K;
ll L,U;
ll A[202020];

ll sum[604040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>L>>U;
	ll D=U-L;
	FOR(i,N) cin>>A[i];
	sort(A,A+N);
	L=0;
	for(i=50;i>=0;i--) {
		ll TL=L+(1LL<<i);
		ll L1=lower_bound(A,A+N,TL)-A;
		ll R1=A+N-lower_bound(A,A+N,TL+D+1);
		if(L1<=R1) L=TL;
	}
	ll SL=max(0LL,L-K);
	
	FOR(i,N) {
		if(A[i]<=SL) {
			ll pat=(SL-A[i]+K-1)/K;
			sum[0]+=pat;
			int dif=K-(SL-A[i]+K-1)%K;
			sum[dif]++;
			sum[dif+K]++;
		}
		else if(A[i]<=SL+D) {
			sum[min(2*K+2,A[i]-SL+1)]++;
			sum[min(2*K+2,A[i]-SL+1+K)]++;
		}
		else {
			int d=(A[i]-(SL+D))%K;
			//d++;
			if(d==0) d=K;
			assert((A[i]-(SL+D)+K-1)/K>0);
			sum[0]+=(A[i]-(SL+D)+K-1)/K;
			sum[d]--;
			if((A[i]-(SL+D)+K-1)/K>1) sum[d+K]--;
			if(A[i]<=SL+2*K) {
				sum[A[i]-SL+1]++;
				sum[A[i]-SL+1+K]++;
			}
		}
		
	}
	ll mi=1LL<<60;
	FOR(i,2*K+1) {
		if(i) sum[i]+=sum[i-1];
		mi=min(mi,sum[i]);
	}
	cout<<mi<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
