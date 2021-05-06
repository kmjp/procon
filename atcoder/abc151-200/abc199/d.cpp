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

int ok[1<<20];
int N,M;
int E[20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		E[x]|=1<<y;
		E[y]|=1<<x;
	}
	int mask;
	FOR(mask,1<<N) {
		ok[mask]=1;
		FOR(y,N) if(mask&(1<<y)) if(E[y]&mask) ok[mask]=0;
	}
	ll ret=0;
	for(mask=1;mask<(1<<N);mask+=2) if(ok[mask]) {
		int sm=mask^((1<<N)-1);
		for(int x=sm; x>=0; x--) {
			x&=sm;
			if(ok[x]&&ok[x^sm]) ret++;
		}
	}
	cout<<ret*3<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
