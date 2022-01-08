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
int A[202020];
ll B[202020];
ll C[202020];
void solve() {
	int i,j,k,l,r,x,y;;
	
	cin>>N;
	
	ll s=0;
	FOR(i,N) {
		cin>>A[i];
		s+=A[i];
	}
	if(s) {
		cout<<-1<<endl;
		return;
	}
	s=0;
	for(i=1;i<N;i++) {
		B[i]=B[i-1]+A[i];
		s+=B[i];
	}
	if(s%N) {
		cout<<-1<<endl;
		return;
	}
	ll mi=0;
	for(i=1;i<N;i++) {
		B[i]-=s/N;
		C[i]=C[i-1]+B[i];
		mi=min(mi,C[i]);
	}
	ll ret=0;
	FOR(i,N) {
		C[i]-=mi;
		ret+=C[i];
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
