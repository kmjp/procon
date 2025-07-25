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
string S;

int C[202020][26];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>S;
		N=S.size();
		FOR(i,N) if(S[i]!=S[N-1-i]) break;
		if(i==N) {
			cout<<0<<endl;
			continue;
		}
		S=S.substr(i,N-2*i);
		N=N-2*i;
		int ret=N;
		FOR(k,2) {
			reverse(ALL(S));
			FOR(j,26) {
				FOR(i,N) {
					C[i+1][j]=C[i][j]+(S[i]=='a'+j);
				}
			}
			for(i=1;i<N;i++) {
				if(i-1>N-1-(i-1)) {
					if(S[i-1]!=S[N-1-(i-1)]&&i-1>N-1-(i-1)) break;
					FOR(j,26) if(C[i][j]!=C[N][j]-C[N-i][j]) break;
					if(j==26) ret=min(ret,N-i);
				}
				else {
					FOR(j,26) if(C[i][j]>C[N][j]-C[i][j]) break;
					if(j==26) ret=min(ret,N-i);
				}
			}
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
