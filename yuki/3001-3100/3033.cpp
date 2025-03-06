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

ll N,M;
ll A[20],B[20],C[20],D[20];
ll V[4],W[4];
const ll mo=998244353;

ll table[4][4]={
	{-1,3,-3,1},
	{9,-24,21,-6},
	{-26,57,-42,11},
	{24,-36,24,-6},
};

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N>>M;
	FOR(i,M) cin>>A[i]>>B[i]>>C[i]>>D[i];
	
	for(i=1;i<=4;i++) {
		for(x=-15*i;x<=15*i;x++) for(y=-15*i;y<=15*i;y++) for(z=-15*i;z<=15*i;z++) {
			int ok=1;
			FOR(j,M) if(A[j]*x+B[j]*y+C[j]*z+D[j]*i<=0) ok=0;
			V[i-1]+=ok;
		}
	}
	
	FOR(y,4) FOR(x,4) W[3-x]+=V[y]*table[x][y]%mo;
	FOR(x,4) {
		W[x]%=mo;
		(W[x]*=(mo+1)/2)%=mo;
		(W[x]*=(mo+1)/3)%=mo;
	}
	ll ret=0;
	ret=W[0]+W[1]*N%mo+W[2]*N%mo*N%mo+W[3]%mo*N%mo*N%mo*N%mo;
	cout<<(ret%mo+mo)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
