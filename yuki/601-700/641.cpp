#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
ll A[101010];
ll mo=1000000009;
ll ave;
int cnt[61];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>A[i];
		FOR(j,K) cnt[j] += (A[i]>>j)&1;
	}
	
	if(K==0) return _P("0\n0\n");
	
	ave=((1LL<<K)-1)%mo*((1LL<<(K-1))%mo)%mo;
	ave = ave*N%mo;
	
	cout<<ave<<endl;
	
	ll S1=0,S2=0;
	FOR(i,K) {
		ll a=cnt[i]*((1LL<<i)%mo)%mo;
		ll b=(N-cnt[i])*((1LL<<i)%mo)%mo;
		(S2 += (S1*(a+b)+(a*a+b*b)%mo*((1LL<<(K-1))%mo)%mo))%=mo;
		(S1+=(a+b)*((1LL<<(K-1))%mo))%=mo;
	}
	
	S2 = S2*((1LL<<K)%mo)%mo - ave*ave%mo;
	cout<<(S2%mo+mo)%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
