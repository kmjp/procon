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
int A[2][6];
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	while(N--) {
		FOR(i,2) {
			FOR(j,6) cin>>A[i][j];
		}
		cin>>S;
		x=0;
		if(S=="WA") x=1;
		if(S=="TLE") x=2;
		if(S=="MLE") x=3;
		if(S=="OLE") x=4;
		if(S=="RE") x=5;
		int ok=1;
		FOR(j,6) {
			if(j!=x) {
				if(A[0][j]<A[1][j]) ok=0;
				if(j&&A[1][j]) ok=0;
			}
			else {
				if(A[0][j]) ok=0;
			}
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
