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

ll N,M,L,R;
ll mo=1000000007;
ll ret;

ll comb(ll N_, ll C_) {
	const int NUM_=700001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}
ll hcomb(int P_,int Q_) { return (P_==0&&Q_==0)?1:comb(P_+Q_-1,Q_);}


ll pat(int a,int b,int ma) {
	ll tot=0;
	for(int over=0;over*b+M*a<=ma && over<=N-M;over++) {
		ll pat=comb(N-M,over)%mo*hcomb(N+1,ma-(over*b+M*a))%mo;
		if(over%2==0) {
			tot+=pat;
		}
		else {
			tot+=mo-pat;
		}
	}
	return (tot%mo+mo)%mo*comb(N,M)%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>L>>R;
	
	for(i=L;i<=R;i++) ret+=hcomb(N,i);
	for(int la=1;la<=R;la++) {
		ret-=(pat(la,la,R)-pat(la+1,la,R))-(pat(la,la,L-1)-pat(la+1,la,L-1));
	}
	
	
	cout<<(ret%mo+mo)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
