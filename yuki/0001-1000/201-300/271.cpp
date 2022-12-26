#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};

ll mo=1000000007;
int N;
ll K;
vector<int> P,P2;


vector<int> toFNS(vector<int> v) { // factorial number system
	static BIT<int,20> bt;
	ZERO(bt.bit);
	
	vector<int> ret;
	reverse(v.begin(),v.end());
	FORR(r,v) ret.push_back(bt(r)), bt.add(r,1);
	reverse(ret.begin(),ret.end());
	return ret;
}


ll fact[101010], totinv[101010];
void FNSinvsuminit(){
	int i;
	ll f=1;
	fact[0]=1;
	totinv[0]=0;
	for(i=1;i<=100000+5;i++) {
		fact[i]=fact[i-1]*i;
		f=f*i%mo;
		if(fact[i]<fact[i-1]) fact[i]=1LL<<62;
		totinv[i]=f%mo*i%mo;
		(totinv[i]*=i-1)%=mo;
		(totinv[i]*=(mo+1)/2)%=mo;
		(totinv[i]*=(mo+1)/2)%=mo;
	}
}

ll FNSinvsum(vector<int> v) {
	ll sum=0,num=0,f=1;
	int i,j;
	
	for(i=v.size()-1;i>=0;i--) {
		sum += totinv[v.size()-1-i]*v[i]%mo;
		sum += f%mo*(1LL*v[i]*(v[i]-1)/2%mo)%mo;
		sum += v[i]*num%mo;
		num=(num+v[i]*f)%mo;
		f=f*(v.size()-i)%mo;
	}
	return sum%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FNSinvsuminit();

	cin>>N>>K;
	FOR(i,N) cin>>x, P.push_back(x);
	P2=P=toFNS(P);
	
	// add K
	FOR(i,N) {
		ll t=K+P2[N-1-i];
		P2[N-1-i]=t%(i+1);
		K=t/(i+1);
	}
	cout<<(mo + K%mo*totinv[N]%mo + FNSinvsum(P2) - FNSinvsum(P))%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
