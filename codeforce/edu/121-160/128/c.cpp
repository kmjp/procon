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
int C[2][202020];

int can(int v) {
	if(v<0) return 0;
	for(int L=0,R=0;L<N;L++) {
		while(R<N&&C[0][R+1]-C[0][L]<=v) R++;
		if(C[1][L]+(C[1][N]-C[1][R])<=v) return 1;
	}
	return 0;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>S;
		N=S.size();
		FOR(i,N) {
			C[1][i+1]=C[1][i]+(S[i]=='1');
			C[0][i+1]=C[0][i]+(S[i]=='0');
		}
		int ret=N;
		for(i=20;i>=0;i--) if(can(ret-(1<<i))) ret-=1<<i;
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
