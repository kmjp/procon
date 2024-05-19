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


int N;
ll V[101010],L[101010];
const ll mo=998244353LL*15;

const int MAT=4;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);};};

Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	int x,y,z; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(x,n) FOR(z,n) FOR(y,n) {
		r.v[x][y] = (r.v[x][y]+(__int128)a.v[x][z]*b.v[z][y])%mo;
	}
	return r;
}

Mat powmat(ll p,Mat a,int n=MAT) {
	int i,x,y; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(i,n) r.v[i][i]=1;
	while(p) {
		if(p%2) r=mulmat(r,a,n);
		a=mulmat(a,a,n);
		p>>=1;
	}
	return r;
}
__int128 modpow(__int128 a, __int128 n = mo-2) {
	__int128 r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

// í∑Ç≥lenÇÃrepunitêîÇ∆ÅA10^len
template<typename V> pair<V,V> repunit(ll len) {
	if(len==1) return {1,10};
	auto a=repunit<V>(len/2);
	a.first=(a.first*a.second+a.first)%mo;
	a.second=a.second*a.second%mo;
	if(len%2) {
		a.first=(a.first*10+1)%mo;
		a.second=(a.second*10)%mo;
	}
	return a;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll SL=0;
	__int128 num=0;
	FOR(i,N) {
		cin>>V[i]>>L[i];
		SL+=L[i];
		num=(num*modpow(10,L[i])+V[i]*repunit<__int128>(L[i]).first)%mo;
	}
	
	if(SL<=6) {
		int ret=0;
		for(i=1;i<=num;i++) {
			if(i%3==0) ret+=4;
			if(i%5==0) ret+=4;
			if(i%3&&i%5) {
				x=i;
				while(x) ret++, x/=10;
			}
		}
		cout<<ret<<endl;
		return;
	}
	
	Mat A;
	A.v[0][0]=10;
	A.v[0][1]=10;
	A.v[1][1]=10;
	A.v[2][0]=1;
	A.v[2][1]=4;
	A.v[2][2]=1;
	A=powmat(SL-2,A);
	ll ret=(A.v[2][0]*96+A.v[2][1]*48+21)%mo;
	
	
	
	num+=mo-modpow(10,SL-1)+1;
	num%=mo;
	ret+=(num/15)*((8*SL+32)%mo)%mo;
	for(i=100;i<100+(num%15);i++) {
		if(i%3==0) ret+=4;
		if(i%5==0) ret+=4;
		if(i%3&&i%5) ret+=SL%mo;
	}
	
	cout<<ret%998244353<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
