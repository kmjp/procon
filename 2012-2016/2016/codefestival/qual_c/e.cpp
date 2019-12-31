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
int P[505050];
int D[505050];
int S[505050];
int Z[505050];
int ZL[505050];
ll fact[505050];
ll mo=1000000007;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N;
	FOR(i,N) D[i]=1;
	FOR(i,N) {
		cin>>P[i];
		P[i]--;
		if(P[i]>=0) D[P[i]]--;
		else Z[i]++;
	}
	FOR(i,N) {
		S[i]=(i?S[i-1]:0)+D[i];
		ZL[i]=(i?ZL[i-1]:0)+Z[i];
	}
	fact[0]=1;
	FOR(i,505000) fact[i+1]=fact[i]*(i+1)%mo;
	
	ll T=0;
	ll TZ=0;
	FOR(i,N) if(D[i]==1) T=(T+i)%mo;
	
	int K=ZL[N-1];
	ll ret=fact[K];
	FOR(i,N) {
		ll pat;
		
		if(P[i]>=0) {
			pat = fact[K]*P[i]%mo;
			pat += (i?ZL[i-1]:0)*(mo-S[P[i]]*fact[K-1]%mo)%mo;
			pat += bt(P[i])*(mo-fact[K])%mo;
			bt.add(P[i],1);
			(TZ += S[N-1]-S[P[i]])%=mo;
		}
		else {
			pat = T*fact[K-1]%mo;
			pat += (i?ZL[i-1]:0)*(mo-1LL*K*(K-1)/2%mo*fact[K-2]%mo)%mo;
			pat += mo-TZ*fact[K-1]%mo;
		}
		
		ret += pat%mo*fact[N-1-i]%mo;
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
