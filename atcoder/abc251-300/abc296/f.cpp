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
int A[202020],B[202020];
int C[202020],D[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		C[A[i]]++;
		D[A[i]]++;
	}
	FOR(i,N) {
		cin>>B[i];
		C[B[i]]--;
	}
	FOR(i,N+1) if(C[i]) {
		cout<<"No"<<endl;
		return;
	}
	FOR(i,N+1) if(D[i]>=2) {
		cout<<"Yes"<<endl;
		return;
	}
	ll a=0;
	FOR(i,N) {
		a+=bt[0](A[i]);
		bt[0].add(A[i],1);
	}
	FOR(i,N) {
		a+=bt[1](B[i]);
		bt[1].add(B[i],1);
	}
	if(a%2) {
		cout<<"No"<<endl;
	}
	else {
		cout<<"Yes"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
