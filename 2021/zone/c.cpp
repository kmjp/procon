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
int C[5][3030];

int ok(int v) {
	int ok[4][1<<5]={};
	
	int i,j,x;
	ok[0][0]=1;
	FOR(i,N) {
		int mask=0;
		FOR(j,5) if(C[j][i]>=v) mask|=1<<j;
		FOR(j,3) FOR(x,1<<5) if(ok[j][x]) ok[j+1][x|mask]=1;
	}
	
	
	return ok[3][31];
	
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		FOR(j,5) cin>>C[j][i];
	}
	
	int ret=0;
	for(i=29;i>=0;i--) if(ok(ret+(1<<i))) ret+=1<<i;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
