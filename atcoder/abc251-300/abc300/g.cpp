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

ll N,P;
const int prime_max = 1000000;
vector<int> prime;
int NP,divp[prime_max];

void cprime(int ma) {
	if(NP) return;
	for(int i=2;i<=ma;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

vector<ll> cand;
ll ret=0;
void dfs(ll cur,int step,int ma) {
	if(cur>N) return;
	if(step>=ma) return;
	
	if(cur*prime[step]<=N) {
		cand.push_back(cur*prime[step]);
		dfs(cur*prime[step],step,ma);
	}
	dfs(cur,step+1,ma);
}
void dfs2(ll cur,int step,int ma) {
	if(cur>N) return;
	if(step>=ma) return;
	if(cur*prime[step]<=N) {
		ret+=lower_bound(ALL(cand),N/(cur*prime[step])+1)-cand.begin();
		dfs2(cur*prime[step],step,ma);
	}
	dfs2(cur,step+1,ma);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N>>P;
	cprime(P);
	
	cand.push_back(1);
	dfs(1,0,min(7,NP));
	sort(ALL(cand));
	
	ret+=lower_bound(ALL(cand),N+1)-cand.begin();
	dfs2(1,7,NP);
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
