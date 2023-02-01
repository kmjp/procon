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

int N,Q;
int C[2];
vector<int> E[505050];
const ll mo=998244353;
const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll catalan(int n) {
	return fact[2*n]*factr[n]%mo*factr[n+1]%mo;
}

ll ret=1;
void dfs(int L,int R) {
	if((R-L)%2) {
		cout<<0<<endl;
		exit(0);
	}
	int num=1;
	L++;
	while(L<R) {
		if(E[L].size()) {
			dfs(L,E[L][0]);
			L=E[L][0];
		}
		else {
			num++;
			L++;
		}
	}
	ret=ret*catalan(num/2)%mo;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	cin>>N>>Q;
	C[0]=N/2;
	C[1]=N-N/2;
	if(N%2) N++;
	E[0].push_back(N);
	FOR(i,Q) {
		int L,R;
		cin>>L>>R;
		E[L-1].push_back(R);
	}
	
	FOR(i,N) if(E[i].size()) {
		sort(ALL(E[i]));
		E[i].erase(unique(ALL(E[i])),E[i].end());
		if(E[i][0]==i) E[i].erase(E[i].begin());
		if(E[i].empty()) continue;
		
		FOR(j,E[i].size()-1) {
			E[E[i][j]].push_back(E[i][j+1]);
		}
		E[i].resize(1);
		for(j=i+1;j<E[i][0];j++) {
			int f=0;
			FORR(e,E[j]) {
				if(e>=E[i][0]) f=1;
			}
			if(f) {
				E[j].push_back(E[i][0]);
				E[i][0]=j;
				break;
			}
		}
	}
	
	ret=1;
	dfs(0,N);
	FOR(i,C[0]) ret=ret*(i+1)%mo;
	FOR(i,C[1]) ret=ret*(i+1)%mo;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
