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

int N,X;
string C[404040];
ll V[404040],S[404040][4];
const ll mo=998244353;

ll modpow(ll a, ll n=mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll comb(ll P_,ll Q_) {
	if(P_<0 || Q_<0 || Q_>P_) return 0;
	ll p=1,q=1;
	Q_=min(Q_,P_-Q_);
	for(int i=1;i<=Q_;i++) p=p*P_%mo, q=q*i%mo,P_--;
	
	return p*modpow(q,mo-2)%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	FOR(i,X) {
		cin>>C[i]>>V[i];
		FOR(j,4) S[i+1][j]=S[i][j];
		if(C[i]=="B") {
			S[i+1][0]+=V[i];
		}
		else {
			S[i+1][1]+=V[i];
			(S[i+1][2]+=V[i]*S[i+1][0])%=mo;
			(S[i+1][3]+=V[i]*S[i+1][0]%mo*S[i+1][0])%=mo;
		}
	}
	ll NR=S[X][1],NB=S[X][0];
	
	ll RR=(NR>=4?comb(NR,4)*modpow(NR-1)%mo*modpow(NR-3)%mo:0);
	ll BB=(NB>=4?comb(NB,4)*modpow(NB-1)%mo*modpow(NB-3)%mo:0);
	ll RB=0;
	
	FOR(i,X) if(C[i]=="R") {
		RB+=((-S[i+1][0]*NB-S[i+1][0]*S[i+1][0])%mo*(S[X][1]-S[i+1][1])+(NB+2*S[i+1][0])*(S[X][2]-S[i+1][2])-(S[X][3]-S[i+1][3]))%mo*V[i];
	}
	RB=(RB%mo+mo)%mo;
	if(RB) RB=RB*modpow(NR-1)%mo*modpow(NB-1)%mo;
	
	cout<<(RR+BB+RB)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
