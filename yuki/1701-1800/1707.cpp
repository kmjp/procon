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


int T,N;
int A[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		map<int,int> M;
		FOR(i,2*N) {
			cin>>A[i];
			A[i]--;
			M[A[i]]++;
		}
		int ng=0;
		FORR2(a,b,M) if(b!=2) ng=1;
		if(ng) {
			cout<<"No"<<endl;
			continue;
		}
		
		if(A[0]!=0||A[2*N-1]!=N-1) {
			cout<<"No"<<endl;
			continue;
		}
		for(i=1;i<2*N-1;i++) if(A[i]!=i%N) {
			x=A[i-1];
			for(j=i;j<2*N;j++) if(A[j]==x) break;
			reverse(A+i,A+j);
			if(j==2*N) break;
		}
		
		FOR(i,2*N) if(A[i]!=i%N) break;
		if(i==2*N) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
