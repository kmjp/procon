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
int C[1010],D[1010];
ll ma[1010];
ll pat[1010];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>C[i];
	FOR(i,N) cin>>D[i];
	FOR(i,K+1) ma[i]=-1;
	ma[0]=0;
	pat[0]=1;
	FOR(i,K) {
		FOR(j,N) if(i+C[j]<=K && ma[i]+D[j]>=ma[i+C[j]]) {
			if(ma[i]+D[j]>ma[i+C[j]]) ma[i+C[j]]=ma[i]+D[j], pat[i+C[j]]=0;
			(pat[i+C[j]]+=pat[i])%=mo;
		}
		
	}
	
	ll rma=-1,rpat=0;
	FOR(i,K+1) {
		if(ma[i]>rma) rma=ma[i], rpat=0;
		if(ma[i]==rma) rpat+=pat[i];
	}
	cout<<rma<<endl;
	cout<<rpat%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
