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

ll N;
int M,K;
ll mo=1000000007;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll fact(ll N) {
	ll v=0;
	pair<ll,ll> P[]= {
	{0,1},
	{50000000,67347853},
	{100000000,927880474},
	{150000000,261384175},
	{200000000,933245637},
	{250000000,112390913},
	{300000000,668123525},
	{350000000,386027524},
	{400000000,429277690},
	{450000000,462639908},
	{500000000,733333339},
	{550000000,696628828},
	{600000000,724464507},
	{650000000,92255682},
	{700000000,957939114},
	{750000000,217598709},
	{800000000,203191898},
	{850000000,823845496},
	{900000000,586445753},
	{950000000,315103615},
	{1000000000,698611116},
	{1100000000,698611116},
	};
	int i=0;
	ll ret=0;
	while(1) {
		if(P[i].first>N) {
			i--;
			v=P[i].first;
			ret=P[i].second;
			break;
		}
		i++;
	}
	while(v<N) {
		v++;
		ret=ret*v%mo;
	}
	return ret;
	
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	/*
	ll f=1;
	for(i=1;i<mo;i++) {
		f=f*i%mo;
		if(i%50000000==0) {
			cout<<"{"<<i<<","<<f<<"},"<<endl;
		}
	}
	*/
	
	cin>>N>>K>>M;
	
	if(N>=mo) return _P("0\n");
	if(N<K) {
		vector<int> V;
		FOR(i,N) V.push_back(i);
		ll ret=0;
		do {
			int ten=0;
			FOR(y,N) FOR(x,y) if(V[x]>V[y]) ten++;
			if(ten%K==M) ret++;
			
		} while(next_permutation(ALL(V)));
		cout<<ret<<endl;
		return;
	}
	
	cout<<fact(N)*modpow(K)%mo<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
