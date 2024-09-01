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

ll F[101][3];
ll N,K;
string S="yuusaan";

char dfs(ll N,ll K) {
	if(N==1) return S[K];
	
	ll len=F[N-1][0]+F[N-1][1]+F[N-1][2];
	if(K==0) return 'y';
	if(K==2*len+1) return 's';
	if(K==2+4*len) return 'n';
	if(K<2*len+1) return dfs(N-1,(K-1)%len);
	return dfs(N-1,(K-2)%len);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	F[1][0]=3;
	F[1][1]=2;
	F[1][2]=2;
	for(i=2;i<=100;i++) {
		F[i][0]=F[i-1][0]+(F[i-1][1]+F[i-1][2])*3;
		F[i][1]=(F[i-1][1]+F[i-1][2])*2;
		F[i][2]=(F[i-1][1]+F[i-1][2])*2;
	}
	
	cin>>N>>K;
	K--;
	if(N>28) {
		if(K<(N-28)) {
			cout<<"y"<<endl;
			return;
		}
		K-=(N-28);
		N=28;
	}
	cout<<dfs(N,K)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
