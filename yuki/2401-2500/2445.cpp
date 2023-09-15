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
ll mo;
ll from[1<<20][2],to[1<<20][2];
ll A[20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>mo;
	from[0][0]=1;
	FOR(i,N) {
		FOR(j,N) {
			cin>>A[j];
			A[j]%=mo;
		}
		ZERO(to);
		FOR(j,1<<N) if(__builtin_popcount(j)==i) FOR(x,N) FOR(y,2) if((j&(1<<x))==0) {
			int c=__builtin_popcount(j&((1<<N)-(1<<x)))%2;
			(to[j^(1<<x)][y^c]+=from[j][y]*A[x])%=mo;
		}
		
		swap(from,to);
	}
	ll ret=from[(1<<N)-1][1];
	cout<<(ret%mo+mo)%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
