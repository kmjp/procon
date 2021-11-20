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

ll N,K;

ll A[2010101];
ll B[2010101];
map<int,ll> num;
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	ll ret=1;
	for(i=0;i<=K;i++) A[i]=i;
	FOR(i,K) B[i]=N-i;
	for(i=2;i<=1000000;i++) {
		for(j=i;j<=K;j+=i) {
			while(A[j]%i==0) {
				A[j]/=i;
				num[i]--;
			}
		}
		ll s=N-K+1;
		for(ll t=(s+(i-1))/i*i;t<=N;t+=i) {
			k=N-t;
			while(B[k]%i==0) {
				num[i]++;
				B[k]/=i;
			}
		}
	}
	FOR(i,K) if(B[i]>1) ret=ret*2%mo;
	FORR2(a,b,num) {
		ret=ret*(b+1)%mo;
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
