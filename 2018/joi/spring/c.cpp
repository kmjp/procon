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

const ll mo=1000000007;
ll comb(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}
ll perm(ll N_, ll C_) {
	const int NUM_=2000003;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return fact[N_]*factr[N_-C_]%mo;
}

int H,W;
ll memo[3030][3030][2];
ll rp2[3030];
ll hoge(int x,int y,int need) {
	if(x==0 || y==0) return 1-need;
	if(memo[x][y][need]>=0) return memo[x][y][need];
	
	
	return memo[x][y][need]=(hoge(x-1,y,need)+4*y*hoge(x-1,y-1,0))%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	rp2[0]=1;
	FOR(i,3020) rp2[i+1]=rp2[i]*((mo+1)/2)%mo;
	cin>>H>>W;
	MINUS(memo);
	ll ret=0;
	for(y=0;y<=H && y*2<=W;y++) {
		ll pat=comb(H,y)*perm(W,2*y)%mo*rp2[y]%mo;
		for(x=0;x+y*2<=W&&y+2*x<=H;x++) {
			ll pat2=perm(H-y,2*x)*comb(W-2*y,x)%mo*rp2[x]%mo;
			
			int lx=W-y*2-x;
			int ly=H-x*2-y;
			if(x||y) ret+=pat*pat2%mo*hoge(lx,ly,0)%mo;
			else ret+=pat*pat2%mo*hoge(lx,ly,1)%mo;
		}
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
