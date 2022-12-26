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

ll N,K;
ll Q[1010101];
ll mo=1000000007;
vector<int> V[1010101];

int prime_max = 1100000;
int NP,prime[100000],divp[1100000];
map<int,int> M;

map<vector<int>,int> memo;

ll combi(ll N_, ll C_) {
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
ll hcomb(int P_,int Q_) { return (P_==0&&Q_==0)?1:combi(P_+Q_-1,Q_);}

void cprime() {
	if(NP) return;
	for(int i=2;i<=prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>=i&&j<=prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

ll dp[10][31];

ll hoge(vector<int> V) {
	if(memo.count(V)) return memo[V];
	ZERO(dp);
	dp[0][0]=1;
	int num=0;
	int s=0;
	FORR(v,V) {
		s+=v;
		for(int i=num;i>=0;i--) {
			for(int x=0;x<=30;x++) if(dp[i][x]) {
				for(int a=1;a<=v;a++) if(a+x<=30) (dp[i+1][a+x]+=dp[i][x])%=mo;
			}
		}
		num++;
	}
	assert(V.size()<=9 && s<=30);
	
	ll ret=0;
	for(int i=0;i<=V.size();i++) for(int x=0;x<=30;x++) if(dp[i][x]) {
		int k=K-x;
		if(k<0) continue;
		(ret+=dp[i][x]*hcomb(NP-i+1,k))%=mo;
	}
	return memo[V]=ret;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>K;
	prime_max=N;
	cprime();
	FOR(i,NP) {
		for(x=prime[i];x<=N;x+=prime[i]) {
			y=x;
			V[x].push_back(0);
			while(y%prime[i]==0) V[x].back()++, y/=prime[i];
		}
	}
	
	ll ret=0;
	for(i=1;i<=N;i++) {
		sort(ALL(V[i]));
		(ret+=i*hoge(V[i]))%=mo;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
