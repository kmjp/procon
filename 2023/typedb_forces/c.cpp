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

int T,N,S;
int A[202020];
ll X[202020][2],Y[202020][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		FOR(i,N) {
			cin>>A[i];
			if(A[i]>=2*S) {
				X[i][0]=S;
			}
			else {
				X[i][0]=min(S,A[i]);
			}
			Y[i][0]=A[i]-X[i][0];
			X[i][1]=Y[i][0];
			Y[i][1]=X[i][0];
			
			if(i==0||i==N-1) {
				X[i][0]=Y[i][0]=X[i][1]=Y[i][1]=A[i];
			}
		}
		
		ll from[2]={0,0};
		for(i=1;i<N;i++) {
			ll to[2]={1LL<<60,1LL<<60};
			
			to[0]=min(to[0],from[0]+Y[i-1][0]*X[i][0]);
			to[0]=min(to[0],from[1]+Y[i-1][1]*X[i][0]);
			to[1]=min(to[1],from[0]+Y[i-1][0]*X[i][1]);
			to[1]=min(to[1],from[1]+Y[i-1][1]*X[i][1]);
			swap(from,to);
		}
		cout<<min(from[0],from[1])<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
