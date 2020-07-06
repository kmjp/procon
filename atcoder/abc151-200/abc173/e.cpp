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
pair<int,int> A[202020];
const ll mo=1000000007;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	int p=0;
	FOR(i,N) {
		cin>>x;
		A[i]={abs(x),x};
		if(x>0) p=1;
	}
	sort(A,A+N);
	
	ll ret=1;
	if(p==0 || K==N) {
		if(K%2==0) {
			FOR(i,K) (ret*=(mo+A[N-1-i].second))%=mo;
		}
		else {
			FOR(i,K) (ret*=(mo+A[i].second))%=mo;
		}
	}
	else {
		int pm=mo,mm=0;
		int s=0;
		FOR(i,K) {
			(ret*=(mo+A[N-1-i].second))%=mo;
			if(A[N-1-i].second>0) pm=A[N-1-i].second;
			if(A[N-1-i].second<0) mm=A[N-1-i].second, s^=1;
		}
		
		if(ret && s==1) {
			int p2=-1,m2=1,z=0;
			for(i=N-1-K;i>=0;i--) {
				if(A[i].second>0&&p2==-1) p2=A[i].second;
				if(A[i].second<0&&m2==1) m2=A[i].second;
				if(A[i].second==0) z++;
			}
			
			if((mm==0 || p2==-1) && (pm==mo||m2==1)) {
				if(z) ret=0;
			}
			else if(mm==0 || p2==-1) {
				(ret*=(m2+mo))%=mo;
				(ret*=modpow(pm))%=mo;
			}
			else if(pm==mo||m2==1) {
				(ret*=(p2))%=mo;
				(ret*=modpow(mm+mo))%=mo;
			}
			else if(1LL*p2*pm>=1LL*m2*mm) {
				(ret*=(p2))%=mo;
				(ret*=modpow(mm+mo))%=mo;
			}
			else {
				(ret*=(m2+mo))%=mo;
				(ret*=modpow(pm))%=mo;
			}
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
