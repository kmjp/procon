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
const ll mo=998244353;
ll memo[4040][4040];

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

ll hoge(int len,int id) {
	if(len<=1) return 1;
	if(id==0||id==len-1) return 0;
	if(memo[len][id]>=0) return memo[len][id];
	int L=id,R=len-(id+1);
	ll ret=0;
	//両サイド
	ret+=hoge(len-2,id-1);
	//左
	if(L>=3) ret+=hoge(len-2,id-2)*comb(L-1,2);
	//右
	if(R>=3) ret+=hoge(len-2,id)*comb(R-1,2);
	//左右
	if(L>=2&&R>=2) ret+=hoge(len-2,id-1)*(L-1)*(R-1);
	
	
	return memo[len][id]=ret%mo;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	MINUS(memo);
	FOR(i,2*N+1) cout<<hoge(2*N+1,i)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
