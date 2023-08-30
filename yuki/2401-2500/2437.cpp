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
string X;
ll memo[102][2][2][11][1<<11];
const ll mo=998244353;

ll hoge(int d,int lz,int le,int cmo,int mask) {
	if(d==N) {
		if(lz) return 0;
		if(cmo) return 0;
		if(mask&1) return 0;
		return 1;
	}
	if(memo[d][lz][le][cmo][mask]>=0) return memo[d][lz][le][cmo][mask];
	ll ret=0;
	int i,j;
	FOR(i,10) {
		if(le==0&&i>X[d]) continue;
		int nmo=(cmo*10+i)%11;
		int nmask=1<<cmo;
		FOR(j,11) if(mask&(1<<j)) nmask|=1<<((j*10+i)%11);
		if(lz&&(i==0)) nmask=0;
		ret+=hoge(d+1,lz&&(i==0),le|(i<X[d]),nmo,nmask);
	}
	
	return memo[d][lz][le][cmo][mask]=ret%mo;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	FORR(x,X) x-='0';
	MINUS(memo);
	
	cout<<hoge(0,1,0,0,0)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
