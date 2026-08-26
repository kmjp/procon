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

ll N,A[404040];

int hoge(vector<ll> v) {
	int n=v.size();
	return v[n/2]+v[(n-1)/2];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<ll> A,B,C;
	FOR(i,N) {
		cin>>x;
		A.push_back(x);
	}
	sort(ALL(A));
	FOR(i,N/2) B.push_back(A[i]);
	FOR(i,N/2) C.push_back(A[(N-N/2)+i]);
	
	ll Q1=hoge(B);
	ll Q2=hoge(A);
	ll Q3=hoge(C);
	ll IQR=Q3-Q1;
	int ret=0;
	FOR(i,N) {
		if(4*A[i]<2*Q1-3*IQR||4*A[i]>2*Q3+3*IQR) ret++;
	}
	_P("%f %f %f %d\n",Q1/2.0,Q2/2.0,Q3/2.0,ret);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
