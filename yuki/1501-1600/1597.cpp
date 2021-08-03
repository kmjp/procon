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
ll K;
int P;
int A[101010];
int B[201010];

ll num(int v) {
	if(v<0) return 0;
	ll ret=0;
	int i;
	FOR(i,N) {
		int s=(P-A[i])%P;
		ret+=lower_bound(B,B+2*N,s+v+1)-lower_bound(B,B+2*N,s);
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>P;
	FOR(i,N) cin>>A[i];
	FOR(i,N) {
		cin>>B[i];
		B[N+i]=B[i]+P;
	}
	sort(B,B+2*N);
	
	int ma=P-1;
	for(i=30;i>=0;i--) if(num(ma-(1<<i))>=K) ma-=1<<i;
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
