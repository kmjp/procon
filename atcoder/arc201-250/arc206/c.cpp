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
const ll mo=998244353;

ll from[2];
ll to[2];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	A[0]=1;
	A[N+1]=N;
	FOR(i,N) cin>>A[i+1];
	N+=2;
	
	from[1]=1;
	for(i=1;i<N;i++) {
		ZERO(to);
		if(A[i]==-1) {
			(to[0]=from[0]+from[1]*(N-3))%=mo;
			to[1]=from[1];
		}
		else if(A[i]==i-1) {
			(to[0]=from[0]+from[1])%=mo;
		}
		else if(A[i]==i+1) {
			to[1]=from[1];
		}
		else {
			to[0]=from[1];
		}
		swap(from,to);
	}
	
	cout<<(from[0]+from[1])%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
