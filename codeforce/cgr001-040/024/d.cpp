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
ll mo;

const int NUM_=2000003;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll memo[5050][5050];
ll comb(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

ll hoge(int a,int b) {
	if(memo[a][b]>=0) return memo[a][b];
	ll ret=0;
	
	if(a==0) {
		//追加してもよいししなくてもよい
		ret=1;
		if(b) ret+=b*hoge(0,b-1);
	}
	else {
		ret=a*hoge(a-1,b);
		if(b) ret+=b*hoge(a,b-1);
	}
	
	return memo[a][b]=ret%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>mo;
	MINUS(memo);
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	ll p2[5050];
	p2[0]=1;
	FOR(i,5010) p2[i+1]=p2[i]*2%mo;
	
	ll ret=0;
	//最後に残る2ピン
	for(x=1;x<N;x++) for(y=x+1;y<N;y++) if(x+N-y>N/2) {
		if(x*2>N) continue;
		if(y*2<N) continue;
		//0-xとy-0はすべて抜ける
		int must=x-1+N-1-y;
		//y-x間は抜けても抜かなくても良い
		int ok=y-x-1;
		ret+=hoge(must,ok);
	}
	//最後に残る1ピン
	if(N%2==0) {
		ret+=fact[N-2];
	}
	
	ret=ret%mo*N%mo;
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
