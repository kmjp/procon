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

int T;
ll N,D;

const int prime_max = 1010101;
vector<int> prime;
int NP,divp[prime_max];
vector<pair<ll,ll>> cand;
void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

void dfs(__int128 cur,int id,ll mul,int la,int ig) {
	//0‚Å‚à—Ç‚¢
	ll p=prime[id];
	cand.push_back({mul,cur});
	if(ig==0) {
		int num=1;
		__int128 tc=cur;
		while(tc<=1LL<<60) {
			dfs(tc,id+1,mul*num,la,1);
			num++;
			tc*=p;
		}
	}
	for(int i=1;i<=la;i++) {
		cur*=p;
		if(cur>1LL<<60) break;
		dfs(cur,id+1,mul*(i+1),i,ig);
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	dfs(1,0,1,100,0);
	
	cin>>T;
	while(T--) {
		cin>>N>>D;
		
		ll num=1,ret=1;
		FORR2(n,v,cand) if(v%D&&v<=N&&n>num) {
			num=n;
			ret=v;
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
