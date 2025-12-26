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

int T,N;
int A[303][303];
int C[303];
int D[303];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		ZERO(C);
		FOR(y,N) {
			FOR(x,N) cin>>A[y][x];
			FOR(x,N) if(A[y][N-1-x]!=1) break;
			C[x]++;
		}
		
		int ma=0;
		for(i=1;i<=N;i++) {
			ZERO(D);
			FOR(x,N+1) D[min(x,i-1)]+=C[x];
			for(x=i-1;x>0;x--) if(D[x]>1) D[x-1]+=D[x]-1;
			FOR(x,i) if(D[x]==0) break;
			if(x==i) ma=i;
			
		}
		cout<<ma<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
