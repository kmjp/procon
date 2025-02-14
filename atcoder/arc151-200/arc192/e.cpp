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

int W,H,L,R,D,U;

ll mo=998244353;
ll comb(ll N_, ll C_) {
	const int NUM_=2400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

ll fix_start(int W,int H) {
	// (0,0)から初めて(W,H)の範囲内
	return (comb(W+H+2,W+1)+mo-1)%mo;
}
ll unfix_start(int W,int H) {
	// (W,H)の範囲内に始点も終点もある
	return (comb(W+H+4,W+2)+mo-1LL*(W+2)*(H+2)%mo-1)%mo;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W>>H>>L>>R>>D>>U;
	ll ret=unfix_start(W,H);
	
	//中で初めて中で終わる
	ret-=unfix_start(R-L,U-D);
	
	//外で初めて中に入る。入口を総当たりする
	// 左から入る
	for(y=D;y<=U;y++) ret-=fix_start(L-1,y)*fix_start(W-L,H-y)%mo;
	// 下から入る
	for(x=L;x<=R;x++) ret-=fix_start(x,D-1)*fix_start(W-x,H-D)%mo;
	
	//中で初めて外に出る
	// 右に出る
	for(y=D;y<=U;y++) ret-=fix_start(R-L,y-D)*fix_start(W-(R+1),H-y)%mo;
	// 上に出る
	for(x=L;x<=R;x++) ret-=fix_start(x-L,U-D)*fix_start(W-x,H-(U+1))%mo;
	
	
	ret=(ret%mo+mo)%mo;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
