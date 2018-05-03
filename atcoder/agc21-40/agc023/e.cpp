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

int N;
int A[202020];
int cnt[202020];
ll mo=1000000007;
ll D[202020];
ll Z[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s%mo;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> num,ds,dr;


ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		cnt[A[i]]++;
	}
	for(i=N;i>=1;i--) cnt[i]+=cnt[i+1];
	D[0]=1;
	ll S=1;
	for(i=1;i<=N;i++) {
		cnt[i]-=N-i;
		if(cnt[i]<=0) return _P("0\n");
		S=S*cnt[i]%mo;
		if(cnt[i]==1) {
			D[i]=D[i-1];
			Z[i]=Z[i-1]+1;
		}
		else {
			D[i]=D[i-1]*(cnt[i]-1)%mo*modpow(cnt[i])%mo;
			Z[i]=Z[i-1];
		}
	}
	
	
	ll ret=0;
	FOR(x,N) {
		
		y=lower_bound(Z+1,Z+N+1,Z[A[x]])-Z;
		(ret+=S*D[A[x]]%mo*(dr(A[x])-dr(y)+mo)%mo*((mo+1)/2))%=mo;
		(ret+=S*(x-num(A[x])))%=mo;
		y=lower_bound(Z+1,Z+N+1,Z[A[x]]+1)-Z-1;
		if(y>A[x]) (ret-=S*(ds(y)-ds(A[x])+mo)%mo*modpow(D[A[x]])%mo*((mo+1)/2))%=mo;
		ret=(ret%mo+mo)%mo;
		
		num.add(A[x],1);
		ds.add(A[x],D[A[x]]);
		dr.add(A[x],modpow(D[A[x]]));
	}
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

