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
map<string,int> M;

const int NUMC=26;
class Trie {
public:
	vector<vector<int> > V;
	int tar[505050];
	
	pair<vector<int>,int> find(string s) {
		int cur=0;
		vector<int> ret;
		FORR(c,s) {
			cur=V[cur][c+1];
			if(tar[cur]!=-1) ret.push_back(tar[cur]);
		}
		return {ret,cur};
	}
	void create(vector<string> S) { // 0 is for backtrack
		V.clear();
		V.push_back(vector<int>(NUMC+1));
		MINUS(tar);
		sort(S.begin(),S.end());
		FORR(s,S) {
			int cur=0;
			FORR(c,s) {
				if(V[cur][c+1]==0) V.push_back(vector<int>(NUMC+1)),V[cur][c+1]=V.size()-1;
				cur=V[cur][c+1];
			}
		}
	}
};
Trie t;
const ll mo=998244353;
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int le[505050],mor[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>s;
		FORR(c,s) c-='a';
		S.push_back(s);
	}
	t.create(S);
	FOR(i,N) {
		x=t.find(S[i]).second;
		t.tar[x]=i;
	}
	FOR(i,N) {
		auto v=t.find(S[i]).first;
		v.pop_back();
		FORR(a,v) {
			le[i]++, mor[a]++;
		}
	}
	
	FOR(i,N) {
		int oth=N-1-le[i]-mor[i];
		ll a=(1+le[i]+oth*modpow(2))%mo;
		cout<<a<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
