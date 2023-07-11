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

int T,N,M;
ll A[2020202];
ll B[2020202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N) {
			cin>>A[i];
		}
		
		if(N>M+5) {
			int L=N-M-2;
			
			FOR(i,N-L+1) {
				B[i]=0;
				FOR(j,L) {
					if(((L-1)&j)==j) B[i]^=A[i+j];
				}
				A[i]=B[i]%2;
			}
			N=N-L+1;
		}
		
		while(N>1) {
			FOR(i,N-1) {
				A[i]=(A[i]+A[i+1])*(A[i]+A[i+1])%(1<<M);
			}
			N--;
		}
		cout<<A[0]<<endl;
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
