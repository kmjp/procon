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
string S;
const ll mo=998244353;
int C[101010];
ll P[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	ll ret=0;
	for(int M=1;M<N;M++) if(N%M==0) {
		FOR(i,M) C[i]=2;
		FOR(i,N) if(S[i]=='.') C[i%M]=1;
		P[M]=1;
		FOR(i,M) P[M]=P[M]*C[i]%mo;
	}
	
	for(i=1;i<N;i++) if(N%i==0) {
		for(j=i*2;j<=N;j+=i) {
			(P[j]+=mo-P[i])%=mo;
		}
		ret+=P[i];
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
