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
int C[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		x=0;
		FORR(c,S) {
			if(c=='(') x++;
			else x--;
		}
		if(x) {
			cout<<-1<<endl;
			continue;
		}
		FOR(i,N) C[i]=2;
		x=y=0;
		int t=1;
		FOR(i,N) {
			if(S[i]=='(') {
				if(y) y--, t=2;
				else x++,C[i]=1;
			}
			else {
				if(x) x--,C[i]=1;
				else y++, t=2;
			}
		}
		FOR(i,N) if(C[i]==1) break;
		if(i==N) {
			t=1;
			FOR(i,N) C[i]=1;
		}
		cout<<t<<endl;
		FOR(i,N) cout<<C[i]<<" ";
		cout<<endl;
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
