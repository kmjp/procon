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
const ll mo=998244353;

ll from[5050],to[5050];

ll hoge(int N,int K) {
	int i,j;
	ZERO(from);
	from[0]=1;
	FOR(i,2*N) {
		ZERO(to);
		FOR(j,K+1) {
			if(j) (to[j-1]+=from[j])%=mo;
			if(j+1<=K) (to[j+1]+=from[j])%=mo;
		}
		
		swap(from,to);
	}
	return from[0];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	ll a=hoge(N,K);
	ll b=hoge(N,K-1);
	cout<<(a+mo-b)%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
