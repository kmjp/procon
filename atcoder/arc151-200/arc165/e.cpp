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

int N,K;
vector<int> E[101];
const ll mo=998244353;

const int NUM_=2000003;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];


unordered_map<int,ll> dp[101];
ll ret;
void dfs(int cur,int pre) {
	unordered_map<int,ll> F;
	F[1]=1;
	
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		unordered_map<int,ll> T;
		FORR2(a,b,F) {
			FORR2(a2,b2,dp[e]) {
				(T[a+a2]+=b*b2)%=mo;
			}
		}
		swap(F,T);
	}
	
	if(cur!=pre) {
		F[1000]=1;
		dp[cur]=F;
	}
	else {
		FORR2(a,b,F) {
			int aa=a/1000;
			int ab=a%1000;
			
			if(ab>K) {
				 (ret+=factr[aa+ab]*fact[ab-1]%mo*fact[aa]%mo*b)%=mo;
			}
		}
	}
	
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	cin>>N>>K;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,N) {
		dfs(i,i);
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
