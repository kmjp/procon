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

ll N,K,seed,A,B,M;
ll F[2020202];
vector<ll> W[4];
multiset<ll> L[3],R[3];
ll S[3];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>seed>>A>>B>>M;
	F[0]=seed;
	FOR(i,2*N) {
		F[i+1]=(F[i]*A+B)%M;
	}
	FOR(i,N) {
		x=F[i]%3+1;
		W[x].push_back(F[N+i]*x);
	}
	FOR(i,K+1) W[2].push_back(0);
	FOR(i,3*K+10) W[1].push_back(0);
	FOR(i,4) {
		sort(ALL(W[i]));
		reverse(ALL(W[i]));
	}
	FOR(i,3) {
		vector<ll> C;
		FOR(j,W[3].size()) {
			C.push_back(W[3][j]);
		}
		FOR(j,K+1) {
			ll a=W[1][i+j*3]+W[1][i+j*3+1]+W[1][i+j*3+2];
			C.push_back(a);
		}
		sort(ALL(C));
		reverse(ALL(C));
		FOR(j,K) L[i].insert(C[j]), S[i]+=C[j];
	}
	ll ma=0;
	ll sum=0;
	FOR(i,K+1) {
		if(i) sum+=W[2][i-1]+W[1][i-1];
		x=i%3;
		if(i>=3) {
			ll a=W[1][i-1]+W[1][i-2]+W[1][i-3];
			if(L[x].count(a)) {
				L[x].erase(L[x].find(a));
				S[x]-=a;
			}
		}
		while(L[x].size()>K-i) {
			ll a=*L[x].begin();
			S[x]-=a;
			L[x].erase(L[x].begin());
		}
		ma=max(ma,sum+S[x]);
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
