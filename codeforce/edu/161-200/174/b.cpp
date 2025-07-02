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
int A[707][707];
int C[707*707];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		FOR(i,H*W) C[i]=0;
		FOR(y,H) FOR(x,W) {
			cin>>A[y][x];
			C[A[y][x]-1]|=1;
			if(y&&A[y][x]==A[y-1][x]) C[A[y][x]-1]|=2;
			if(x&&A[y][x]==A[y][x-1]) C[A[y][x]-1]|=2;
			
		}
		int sum=0;
		int ma=0;
		FOR(i,H*W) if(C[i]) {
			sum+=__builtin_popcount(C[i]);
			ma=max(ma,__builtin_popcount(C[i]));
		}
		cout<<sum-ma<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
