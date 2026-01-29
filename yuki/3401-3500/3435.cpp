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

string A;
int L;
int T[256];
ll D[26][26];
int N,M;
string S[3030];
ll C[3030][26];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A;
	L=A.size();
	FOR(i,L) T[A[i]]=i;
	FOR(y,L) FOR(x,L) cin>>D[y][x];
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>S[i];
		FORR(c,S[i]) c=T[c];
		FOR(j,M) C[j][S[i][j]]++;
	}
	
	FOR(i,N) {
		ll ret=0;
		FOR(j,M) FOR(x,L) ret+=D[S[i][j]][x]*C[j][x];
		cout<<ret<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
