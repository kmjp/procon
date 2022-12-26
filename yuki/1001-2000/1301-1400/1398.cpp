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

int H,W,X;
string S[606];

int V[3][3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W>>H>>X;
	
	
	int okR=3,okC=3;
	if(H%3==0) okR^=1;
	if(H%3==1) okR^=2;
	if(W%3==0) okC^=1;
	if(W%3==1) okC^=2;
	FOR(y,3) FOR(x,3) {
		if(okR&(1<<y)) if(okC&(1<<x)) {
			i=min(X,9);
			V[y][x]=i;
			X-=i;
		}
	}
	if(X) return _P("-1\n");
	FOR(y,H) {
		FOR(x,W) cout<<V[y%3][x%3];
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
