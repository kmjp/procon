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

int T,N,A[202020];
int D[802020];
vector<int> C;
int M[804040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	C.push_back(0);
	for(i=1;i<=400000;i++) {
		for(j=i;j<=400000;j+=i) D[j]++;
		if(D[i]%2==1) C.push_back(i);
	}
	
	
	
	cin>>T;
	while(T--) {
		cin>>N;
		x=0;
		M[x]=1;
		ll ret=1LL*N*(N+1)/2;
		FOR(i,N) {
			cin>>A[i];
			x^=A[i];
			FORR(c,C) ret-=M[x^c];
			M[x]++;
		}
		x=0;
		M[x]--;
		FOR(i,N) {
			x^=A[i];
			M[x]--;
		}
		
		
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
