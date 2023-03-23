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
int A[40],B[40];
ll BM;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>A[i]>>B[i];
		A[i]--,B[i]--;
	}
	FOR(i,N) {
		cin>>x;
		BM|=((ll)x)<<i;
	}
	int mask;
	int ret=100;
	map<ll,int> memo;
	int L=M/2,R=M-L;
	FOR(mask,1<<L) {
		ll CM=BM;
		int step=0;
		FOR(i,L) if(mask&(1<<i)) {
			CM^=1LL<<A[i];
			CM^=1LL<<B[i];
			step++;
		}
		if(memo.count(CM)==0) memo[CM]=100;
		chmin(memo[CM],step);
	}
	FOR(mask,1<<R) {
		ll CM=0;
		int step=0;
		FOR(i,R) if(mask&(1<<i)) {
			CM^=1LL<<A[L+i];
			CM^=1LL<<B[L+i];
			step++;
		}
		if(memo.count(CM)) ret=min(ret,memo[CM]+step);
	}
	
	
	
	if(ret==100) ret=-1;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
