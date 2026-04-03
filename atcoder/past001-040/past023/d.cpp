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

int H,W;
string A,B;
string S[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>A>>B;
	FOR(y,H) cin>>S[y];
	FOR(y,H) FOR(x,W) {
		if(y&&S[y-1][x]==A[0]&&S[y][x]==B[0]) {
			cout<<"Yes"<<endl;
			return;
		}
		if(y&&S[y-1][x]==B[0]&&S[y][x]==A[0]) {
			cout<<"Yes"<<endl;
			return;
		}
		if(x&&S[y][x-1]==B[0]&&S[y][x]==A[0]) {
			cout<<"Yes"<<endl;
			return;
		}
		if(x&&S[y][x-1]==A[0]&&S[y][x]==B[0]) {
			cout<<"Yes"<<endl;
			return;
		}
	}
	cout<<"No"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
