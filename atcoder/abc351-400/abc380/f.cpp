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

int N,M,L;
int A[12];
int memo[1<<12][1<<12];

int win(int ma,int mb) {
	if(memo[ma][mb]>=0) return memo[ma][mb];
	if(ma==0) return 0;
	
	int can=0;
	int x,y;
	int mc=(1<<(N+M+L))-1-ma-mb;
	FOR(x,(N+M+L)) if(ma&(1<<x)) {
		if(win(mb,ma-(1<<x))==0) can=1;
		FOR(y,(N+M+L)) if((mc&(1<<y))&&A[y]<A[x]) {
			if(win(mb,ma-(1<<x)+(1<<y))==0) can=1;
		}
	}
	
	return memo[ma][mb]=can;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>L;
	FOR(i,N+M+L) cin>>A[i];
	
	MINUS(memo);
	if(win((1<<N)-1,(1<<(N+M))-(1<<N))) {
		cout<<"Takahashi"<<endl;
	}
	else {
		cout<<"Aoki"<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
