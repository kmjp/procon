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

string S;
ll M,L;

int nex[10000][61];

const ll mo=10000;
ll fib(ll k,ll m) {
	if(k==0) return 0;
	if(k==1) return 1;
	k--;
	ll R[2][2]={{1,0},{0,1}};
	ll A[2][2]={{m,1},{1,0}};
	
	while(k) {
		if(k%2) {
			ll S[2][2];
			S[0][0]=(A[0][0]*R[0][0]+A[0][1]*R[1][0])%mo;
			S[0][1]=(A[0][0]*R[0][1]+A[0][1]*R[1][1])%mo;
			S[1][0]=(A[1][0]*R[0][0]+A[1][1]*R[1][0])%mo;
			S[1][1]=(A[1][0]*R[0][1]+A[1][1]*R[1][1])%mo;
			swap(S,R);
		}
		ll T[2][2];
		T[0][0]=(A[0][0]*A[0][0]+A[0][1]*A[1][0])%mo;
		T[0][1]=(A[0][0]*A[0][1]+A[0][1]*A[1][1])%mo;
		T[1][0]=(A[1][0]*A[0][0]+A[1][1]*A[1][0])%mo;
		T[1][1]=(A[1][0]*A[0][1]+A[1][1]*A[1][1])%mo;
		swap(T,A);
		k>>=1;
	}
	return (R[0][0])%mo;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>M>>L;
	FOR(i,10000) {
		ll a=fib(M,i);
		if(M%2) a=(a+9999)%mo;
		nex[i][0]=a;
	}
	
	ll cur=atoi(S.c_str());
	FOR(j,60) {
		if(L&(1LL<<j)) cur=nex[cur][j];
		FOR(i,10000) nex[i][j+1]=nex[nex[i][j]][j];
	}
	_P("%04lld\n",cur);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
