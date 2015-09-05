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

int N;
pair<int,int> B[101010];
int H[101010],W[101010];
ll sum[101010];
ll mo=1000000007LL;
ll tot;
const int NUM_=110001;
ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll combi(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>B[i].second>>B[i].first;
	
	
	sort(B,B+N);
	FOR(i,N) H[i]=B[N-1-i].first,W[i]=B[N-1-i].second;
	FOR(i,N) sum[i+1]=sum[i]+H[i];
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	ll pat=0,invsum=0;
	for(i=2;i<N;i++) {
		
		y=i-1;
		if(y>=1) {
			(pat += inv[y+1]%mo*inv[y+2]%mo*H[y])%=mo;
			(invsum += inv[y+1]%mo*inv[y+2])%=mo;
		}
		ll tp=pat-invsum*H[i]%mo;
		tp=(tp+mo)%mo;
		(tot += fact[i+1]*2%mo*tp%mo*fact[N-(i+1)]%mo*combi(N,i+1)%mo*W[i])%=mo;
	}
	
	cout<<tot%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
