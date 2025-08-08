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

int T;
ll H,W,K;
const ll mo=998244353;
const int NUM_=1400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll comb(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	
	cin>>T;
	while(T--) {
		cin>>H>>W>>K;
		int need=H-1+W-1;
		if(K<need) {
			cout<<0<<endl;
		}
		else if(K==need) {
			cout<<comb(need,W-1)<<endl;
		}
		else if(K==need+1) {
			ll sum=1LL*(H-1)*W+H*(W-1);
			cout<<comb(need,W-1)*((sum-need)%mo)%mo<<endl;
		}
		else {
			assert(K==need+2);
			ll sum=(1LL*(H-1)*W+H*(W-1)-need)%mo;
			ll sum2=sum*(sum-1)/2%mo;
			ll ret=comb(need,W-1)*sum2%mo;
			
			//2*2で自由に行ける場所がある
			ll pat2=comb(H-2+W-2,W-2)*(H+W-3)%mo;
			ret=(ret-pat2+mo)%mo;
			
			//下左下移動
			//下左下移動は、右移動の前と後以外で使える
			if(H>=3) {
				x=H-3,y=1,k=W;
				ll a=fact[x+y+k]*factr[x]%mo*factr[k]%mo-fact[x+y+k]*factr[x]%mo*factr[k+y]*2%mo+mo;
				ret+=a;
			}
			//右上右
			if(W>=3) {
				x=W-3,y=1,k=H;
				ll a=fact[x+y+k]*factr[x]%mo*factr[k]%mo-fact[x+y+k]*factr[x]%mo*factr[k+y]*2%mo+mo;
				ret+=a;
			}
			
			cout<<ret%mo<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
