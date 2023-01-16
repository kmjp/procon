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

int T;
ll X_,A_,B_;
__int128 X,A,B;

__int128 F(__int128 x, __int128 v) {
	return (x+v-1)/v*v;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>X_>>A_>>B_;
		X=X_;
		A=A_;
		B=B_;
		if(A>B) swap(A,B);
		
		
		set<__int128> S;
		S.insert(X);
		S.insert(F(X,A));
		S.insert(F(X,B));
		S.insert(F(F(X,A),B));
		X=F(F(X,B),A);
		S.insert(X);
		
		__int128 ret=0;
		FORR(s,S) if(s<=X) ret++;
		if(X%B==0) {
			cout<<(ll)ret<<endl;
			continue;
		}
		
		__int128 g=__gcd(A,B);
		X/=g;
		A/=g;
		B/=g;
		
		
		auto Q=F(X,A*B);
		
		ret+=2*((Q-X+B)/B)-1;
		cout<<(ll)(ret%998244353)<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
