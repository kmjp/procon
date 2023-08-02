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
ll A[202020],B[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	vector<ll> C={0};
	FOR(i,N) {
		cin>>A[i];
		C.push_back(A[i]);
		C.push_back(A[i]-1);
		C.push_back(A[i]+1);
	}
	FOR(i,M) {
		cin>>B[i];
		C.push_back(B[i]);
		C.push_back(B[i]-1);
		C.push_back(B[i]+1);
	}
	sort(A,A+N);
	sort(B,B+M);
	sort(ALL(C));
	FORR(X,C) if(X>=0) {
		int a=lower_bound(A,A+N,X+1)-A;
		int b=B+M-lower_bound(B,B+M,X);
		if(a>=b) {
			cout<<X<<endl;
			return;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
