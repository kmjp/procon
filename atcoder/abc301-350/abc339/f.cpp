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
vector<ll> V={1000000007,1000000009,998244353,987971,987971,974983};
vector<ll> W[1010];
int C;
map<vector<ll>,ll> M;

ll hoge(string a,ll mo) {
	ll ret=0;
	FORR(c,a) ret=(ret*10+(c-'0'))%mo;
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	C=V.size();
	cin>>N;
	FOR(i,N) {
		cin>>s;
		FOR(j,C) W[i].push_back(hoge(s,V[j]));
		M[W[i]]++;
	}
	ll ret=0;
	FOR(x,N) FOR(y,N) {
		vector<ll> Z;
		FOR(i,C) Z.push_back(W[y][i]*W[x][i]%V[i]);
		ret+=M[Z];
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
