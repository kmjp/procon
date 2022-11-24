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

int N,M,K;
vector<int> E[3030];
int C[3030];
const ll mo=998244353;
ll FP[3030];
ll FL[3030];
ll FS[3030];
ll TP[3030];
ll TL[3030];
ll TS[3030];

const int NUM_=4001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,N) cin>>C[i];
	
	FP[0]=1;
	ll sum=0;
	while(K--) {
		ZERO(TP);
		ZERO(TL);
		ZERO(TS);
		
		FOR(i,N) {
			FORR(e,E[i]) {
				(TP[e]+=FP[i]*inv[E[i].size()])%=mo;
				(TL[e]+=FL[i]*inv[E[i].size()])%=mo;
				(TS[e]+=FS[i]*inv[E[i].size()])%=mo;
			}
		}
		
		FOR(i,N) {
			if(C[i]==0) {
				(TS[i]+=2*TL[i]+TP[i])%=mo;
				(TL[i]+=TP[i])%=mo;
			}
			else {
				(sum+=TS[i])%=mo;
			}
			FP[i]=TP[i];
			FL[i]=TL[i];
			FS[i]=TS[i];
		}
	}
	cout<<sum<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
