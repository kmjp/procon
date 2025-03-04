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


int T,A,B,C;
const ll mo=998244353;
const int NUM_=2400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];


ll comb(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}
ll catalan_arrange(int X,int Y,int T=1) {
	if(X+T<=Y) return 0;
	return (comb(X+Y,Y)-comb(X+Y,Y-T)+mo)%mo;
}

ll hcomb(ll P_,ll Q_) { return (P_==0&&Q_==0)?1:comb(P_+Q_-1,Q_);}

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	cin>>T;
	while(T--) {
		cin>>A>>B>>C;
		A+=5;
		//ダメな確率を求める
		ll ret=0;
		FOR(i,C+1) {
			//何枚draw 2 cardを取るか
			ll pat=catalan_arrange(i,4+i,5);
			// draw0中に5枚入る確率
			ll a=comb(i+5,0)*comb(A-(i+5),5)+comb(i+5,1)*comb(A-(i+5),4)+comb(i+5,2)*comb(A-(i+5),3)+comb(i+5,3)*comb(A-(i+5),2)+comb(i+5,4)*comb(A-(i+5),1);
			(pat*=a%mo)%=mo;
			//残りのカード
			(ret+=pat*comb(A+C-(i+5+i),C-i)%mo)%=mo;
		}
		//B毎の挿入
		ret=ret*hcomb(A+C+1,B)%mo;
		ret=ret%mo*fact[A-5]%mo*fact[5]%mo*fact[B]%mo*fact[C]%mo*factr[A+B+C]%mo;
		ret=(1+mo-ret)%mo;
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
