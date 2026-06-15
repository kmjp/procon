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
string S;
const ll mo=998244353;
ll p2[202020];

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

vector<ll> hoge(int v) {
	vector<ll> ret(v+1);
	ret[0]=1;
	ll sum=0;
	for(int i=v;i>=1;i--) {
		ll pat=0;
		//êÊì™
		for(int num=1;i+(num-1)*(i+1)<=v;num++) {
			ll c=comb(v-i-(num-1)*i,num-1)*p2[v-(i+(num-1)*(i+1))]%mo;
			if(num%2==1) pat+=c;
			else pat+=mo-c;
		}
		for(int num=1;num*(i+1)<=v;num++) {
			ll c=comb(v-num*i,num)*p2[v-(num*(i+1))]%mo;
			if(num%2==1) pat+=c;
			else pat+=mo-c;
		}
		(ret[i]=pat+mo-sum)%=mo;
		sum=pat%mo;
	}
	return ret;
}
vector<ll> merge(vector<ll> A,vector<ll> B) {
	while(A.size()<B.size()) A.push_back(0);
	vector<ll> C(B.size());
	ll s1=0,s2=0;
	int i;
	ll pre=0;
	FOR(i,C.size()) {
		C[i]=mo-s1*s2%mo;
		(s1+=A[i])%=mo;
		(s2+=B[i])%=mo;
		(C[i]+=s1*s2)%=mo;
	}
	return C;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=1;
	FOR(i,201010) p2[i+1]=p2[i]*2%mo;
	
	cin>>N>>S;
	S+='x';
	vector<int> V={0};
	FORR(c,S) {
		if(c=='x') {
			if(V.back()) V.push_back(0);
		}
		else {
			V.back()++;
		}
	}
	V.pop_back();
	sort(ALL(V));
	vector<ll> ret={1};
	FORR(v,V) ret=merge(ret,hoge(v));
	ret.resize(N+1);
	FOR(i,N) cout<<ret[i+1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
