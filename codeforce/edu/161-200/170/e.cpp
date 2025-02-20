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
const ll mo=998244353;

ll from[505],to[505];
ll F[505],T[505];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	// 1‚Ì”z’u
	from[0]=1;
	FOR(i,M) {
		ZERO(to);
		FOR(j,M+1) {
			(to[j+1]+=from[j])%=mo;
			if(j) (to[j-1]+=from[j])%=mo;
		}
		swap(from,to);
	}
	
	
	F[0]=1;
	FOR(i,N-1) {
		ZERO(T);
		FOR(x,M+1) FOR(y,M+1) if(x+y<=M) (T[x+y]+=F[x]*from[y])%=mo;
		swap(F,T);
	}
	ll ret=0;
	FOR(i,M+1) ret+=from[i]*F[i]%mo;
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
