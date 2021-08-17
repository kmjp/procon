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
ll A[402020];
ll B[402020];
ll C[402020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	
	ll sum=0;
	ll cs=0;
	FOR(i,2*N) {
		sum+=A[i];
		if(i>=N) {
			sum-=A[i-N];
			cs-=N*A[i-N];
		}
		cs+=sum;
		C[i]+=cs;
	}
	sum=cs=0;
	
	FOR(i,2*N) {
		sum+=B[i];
		if(i>=N) {
			sum-=B[i-N];
			cs-=N*B[i-N];
		}
		cs+=sum;
		C[i]+=cs;
	}
	
	cout<<0;
	FOR(i,2*N-1) cout<<" "<<C[i];
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
