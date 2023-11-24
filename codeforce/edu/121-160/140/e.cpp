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

int N,M;
int C[303030];
int X[55];
int A[55][55];
int S[1<<20],T[1<<20];
int need[1<<20];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>C[i];
		C[i]--;
		if(i) A[C[i]][C[i-1]]=A[C[i-1]][C[i]]=1;
	}
	A[C[0]][C[0]]=1;
	A[C[N-1]][C[N-1]]=1;
	
	FOR(i,M) cin>>X[i];
	int mask;
	FOR(mask,1<<20) {
		ll sum=0;
		FOR(i,20) if(mask&(1<<i)) sum+=X[i];
		FOR(x,20) FOR(y,20) if(A[x][y]&&(mask&(1<<x))==0&&(mask&(1<<y))==0) sum=(1<<30)-1;
		S[mask]=sum;
		FOR(x,20) FOR(y,20) if(A[x][y+20]&&((mask&(1<<x))==0)) need[mask]|=1<<y;
		sum=0;
		FOR(i,20) if(mask&(1<<i)) sum+=X[i+20];
		FOR(x,20) FOR(y,20) if(A[x+20][y+20]&&(mask&(1<<x))==0&&(mask&(1<<y))==0) sum=1LL<<30;
		T[mask]=sum;
	}
	
	FOR(i,20) {
		FOR(mask,1<<20) if(mask&(1<<i)) {
			chmin(S[mask^(1<<i)],S[mask]);
			chmin(T[mask^(1<<i)],T[mask]);
		}
	}
	int ret=1<<30;
	FOR(mask,1<<20) ret=min(ret,S[mask]+T[need[mask]]);
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
