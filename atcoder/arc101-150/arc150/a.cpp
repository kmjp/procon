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

int T,N,K;
string S;

int C[303030][3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K>>S;
		
		FOR(i,N) {
			FOR(j,3) C[i+1][j]=C[i][j];
			if(S[i]=='0') C[i+1][0]++;
			if(S[i]=='1') C[i+1][1]++;
			if(S[i]=='?') C[i+1][2]++;
		}
		
		int num=0;
		int n1=C[N][1];
		for(i=0;i+K<=N;i++) {
			int a=C[i+K][0]-C[i][0];
			int b=C[i+K][1]-C[i][1];
			int c=C[i+K][2]-C[i][2];
			if(a) continue;
			if(n1>b) continue;
			num++;
		}
		if(num==1) {
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
