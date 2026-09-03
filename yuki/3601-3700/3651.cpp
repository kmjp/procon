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
ll K;
int nex[230303][61];
int D[230303];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=200000;i++) {
		for(j=i;j<=200000;j+=i) D[j]+=i;
	}
	for(i=1;i<=200000;i++) {
		nex[i][0]=D[i]%100003;
	}
	FOR(j,60) {
		FOR(i,200001) nex[i][j+1]=nex[nex[i][j]][j];
	}
	
	cin>>N>>K;
	K--;
	if(K) {
		K--;
		x=0;
		for(i=1;i<=N;i++) if(N%i==0) x+=i;
		N=x%100003;
	}
	
	FOR(i,60) if(K&(1LL<<i)) N=nex[N][i];
	cout<<N<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
