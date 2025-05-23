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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		
		int C[2]={};
		FORR(c,S) C[c-'0']++;
		
		int ok=0;
		int y,x;
		for(i=1;i<=N;i++) if(N%i==0&&i*i==N) {
			if(C[0]!=max(0,i-2)*max(0,N/i-2)) continue;
			int can=1;
			FOR(y,i) FOR(x,N/i) {
				int one=0;
				if(y==0||y==i-1||x==0||x==(N/i)-1) one=1;
				if(S[y*(N/i)+x]=='0'&&one) can=0;
				if(S[y*(N/i)+x]=='1'&&one==0) can=0;
			}
			if(can) ok=1;
		}
		if(ok) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
