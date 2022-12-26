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

int N,Q;
int A[303030];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	set<int> S;
	FOR(i,N) {
		cin>>x;
		S.insert(x);
	}
	N=S.size();
	x=0;
	FORR(c,S) {
		A[x++]=c;
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>x;
		y=lower_bound(A,A+N,x)-A;
		int mi=1<<30;
		for(j=y-2;j<=y+2;j++) if(j>=0&&j<N) mi=min(mi,abs(A[j]-x));
		cout<<mi<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
