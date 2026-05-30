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
int P[4];
int pat[202020];;
vector<int> Xadd[202020];
vector<int> Xdel[202020];
vector<int> Yadd[202020];
vector<int> Ydel[202020];

ll mo=998244353;
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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	P[0]=N;
	FOR(i,N) {
		cin>>x>>y;
		Xadd[x].push_back(i);
		Xdel[y+1].push_back(i);
		Yadd[N-y].push_back(i);
		Ydel[N-x+1].push_back(i);
	}
	ll ret=0;
	for(i=1;i<N;i++) {
		FORR(a,Xadd[i]) {
			P[pat[a]]--;
			pat[a]|=1;
			P[pat[a]]++;
		}
		FORR(a,Xdel[i]) {
			P[pat[a]]--;
			pat[a]^=1;
			P[pat[a]]++;
		}
		FORR(a,Yadd[i]) {
			P[pat[a]]--;
			pat[a]|=2;
			P[pat[a]]++;
		}
		FORR(a,Ydel[i]) {
			P[pat[a]]--;
			pat[a]^=2;
			P[pat[a]]++;
		}
		if(P[1]>i) continue;
		if(P[2]>N-i) continue;
		int a=i-P[1];
		int b=N-i-P[2];
		(ret+=comb(P[3],a+b)*comb(a+b,a))%=mo;
		
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
