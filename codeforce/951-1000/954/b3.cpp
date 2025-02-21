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

int T,H,W;
int A[101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		int mi=1<<30;
		FOR(y,H) FOR(x,W) {
			cin>>A[y][x];
		}
		
		FOR(y,H) FOR(x,W) {
			int ma=0;
			if(y) ma=max(ma,A[y-1][x]);
			if(x) ma=max(ma,A[y][x-1]);
			if(y+1<H) ma=max(ma,A[y+1][x]);
			if(x+1<W) ma=max(ma,A[y][x+1]);
			if(A[y][x]>ma) A[y][x]=ma;
			
		}
		FOR(y,H) {
			FOR(x,W) cout<<A[y][x]<<" ";
			cout<<endl;
		}
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
