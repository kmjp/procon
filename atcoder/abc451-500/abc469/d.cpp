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
int A[202020],B[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>A[i]>>B[i];
		A[i]--,B[i]--;
	}
	set<pair<int,int>> V;
	map<int,int> C;
	int num=0;
	FOR(i,N) C[i]=0;
	for(i=1;i<M;i++) {
		if(A[i]==A[0]||B[i]==A[0]) continue;
		num++;
		C[A[i]]++;
		C[B[i]]++;
	}
	
	
	FORR2(a,b,C) {
		if(b==num&&a!=A[0]) V.insert({min(a,A[0]),max(a,A[0])});
	}
	C.clear();
	FOR(i,N) C[i]=0;
	num=0;
	for(i=1;i<M;i++) {
		if(A[i]==B[0]||B[i]==B[0]) continue;
		num++;
		C[A[i]]++;
		C[B[i]]++;
	}
	FORR2(a,b,C) {
		if(a!=B[0]&&b==num) V.insert({min(a,B[0]),max(a,B[0])});
	}
	
	cout<<V.size()<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
