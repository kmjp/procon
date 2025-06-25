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
vector<string> S;

const ll mo=998244353;

ll dp[1404040];


ll modpow(ll a, ll n = mo-2) {
	ll r=1; a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}



const int NUMC=2;
class Trie {
public:
	vector<vector<int> > V;
	void create() { // 0 is for backtrack
		V.clear();
		V.push_back(vector<int>(NUMC+3));
	}
	void add(string s) {
		int cur=0;
		FORR(c,s) {
			V[cur][NUMC+1]++;
			if(V[cur][c+1]==0) {
				V.push_back(vector<int>(NUMC+4));
				V[cur][c+1]=V.size()-1;
				V.back()[0]=cur;
			}
			cur=V[cur][c+1];
		}
		V[cur][NUMC+1]++;
		V[cur][NUMC+2]++;
		
		while(1) {
			if(V[cur][1]&&V[cur][2]) (dp[cur]=dp[V[cur][1]]*dp[V[cur][2]])%=mo;
			else dp[cur]=0;
			if(V[cur][NUMC+2]) {
				(dp[cur]+=modpow(2,V[cur][NUMC+1]-1))%=mo;
			}
			if(cur==0) break;
			cur=V[cur][0];
		}
		
		
	}
};
Trie t;



void solve() {
	int i,j,k,l,r,x,y; string s;
	t.create();
	cin>>N;
	FOR(i,N) {
		cin>>s;
		FORR(c,s) c-='A';
		t.add(s);
		cout<<dp[0]<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
