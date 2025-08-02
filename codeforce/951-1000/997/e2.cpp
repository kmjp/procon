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


ll mo=998244353;
const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

vector<int> E[202020];

int T,N,M;

ll catalan(int n) {
	return fact[2*n]*factr[n]%mo*factr[n+1]%mo;
}

ll hoge(int L,int R) {
	
	int num=0;
	ll ret=1;
	while(L<R) {
		num++;
		if(E[L].empty()) {
			L++;
		}
		else {
			int x=E[L].back();
			E[L].pop_back();
			ret=ret*hoge(L,x)%mo;
			L=x;
		}
	}
	return ret*catalan(num-1)%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;

	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N+1) E[i].clear();
		FOR(i,M) {
			cin>>x>>y;
			E[x-1].push_back(y);
		}
		FOR(i,N) sort(ALL(E[i]));
		cout<<hoge(0,N)<<endl;
	}

}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
