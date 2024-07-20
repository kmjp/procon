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
int A[1<<20];
int B[3<<20];
int C[1<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
	}
	
	FOR(i,N) if(A[i]) break;
	if(i==N) {
		cout<<0<<endl;
		return;
	}
	
	
	int step=0;
	for(i=N;i>=2;i/=2) {
		FOR(k,2) {
			FOR(j,N*2) {
				B[j+1]=B[j]^A[j%N];
			}
			FOR(j,N) C[j]=B[j+i]^B[j];
			FOR(j,N) if(C[j]) break;
			if(j!=N) {
				step+=i-1;
				FOR(j,N) A[j]=C[j];
			}
		}
	}
	
	cout<<step+1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
