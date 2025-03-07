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

int N,F;
int A[15151],B[15151],C[15151];
bitset<15100*61> bs;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>F;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	FOR(i,N) cin>>C[i];
	bs[0]=1;
	FOR(i,N) {
		if(B[i]<A[i]) swap(B[i],A[i]);
		if(C[i]<B[i]) swap(C[i],B[i]);
		if(B[i]<A[i]) swap(B[i],A[i]);
		bs|=(bs<<(B[i]-A[i]))|(bs<<(C[i]-A[i]));
		cout<<bs.count()<<endl;
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
