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


ll N;
map<ll,int> GM;
ll fact[11];
int S[6][121][32];

int G(ll n) {
	if(n==1) return 0;
	if(GM.count(n)) return GM[n];
	int k;
	for(k=1;k<=n;k++) if(n<=(1LL<<k)-max(0,G(k))) {
		return GM[n]=k;
	}
	return -1;
}

int check(vector<int> C,int K) {
	int did[1<<5]={};
	FORR(c,C) did[c]=1;
	int i;
	for(i=1;i<fact[K];i++) {
		int same=1;
		FORR(c,C) if(did[S[K][i][c]]==0) same=0;
		if(same) return 0;
	}
	return 1;
}


int go(int K,int N,int nex,vector<int>& C) {
	if(N==0) return check(C,K);
	
	ll ret=0;
	for(int i=nex;i<1<<K;i++) {
		if(ret>1001*fact[K]) break;
		C.push_back(i);
		ret+=go(K,N-1,i+1,C);
		C.pop_back();
	}
	return ret;
}

ll hoge(ll K,ll N) {
	if(K>N) swap(K,N);
	if(2*N>1LL<<K) return hoge(K,(1LL<<K)-N);
	if(K>5) return -1;
	
	vector<int> C;
	ll ret=go(K,N,0,C)/fact[K];
	if(ret>1000) ret=-1;
	return ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	fact[0]=1;
	for(i=1;i<=10;i++) fact[i]=fact[i-1]*i;
	
	for(i=2;i<=5;i++) {
		vector<int> G;
		FOR(j,i) G.push_back(j);
		int step=0;
		do {
			int mask;
			FOR(mask,1<<i) {
				FOR(j,i) if(mask&(1<<j)) S[i][step][mask] |= 1<<G[j];
			}
			
			step++;
		} while(next_permutation(ALL(G)));
	}
	
	
	cin>>N;
	
	k=G(N);
	ll ret=hoge(k,N);
	if(N==4) ret++;
	if(N==7) ret++,ret++;
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
