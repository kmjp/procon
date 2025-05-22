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

ll A,B;

int memo[101][101];

int win(int A,int B) {
	if(B==0) return 0;
	if(memo[A][B]>=0) return memo[A][B];
	int ret=0;
	if(win(B,A-1)==0) ret=1;
	if(B<=A&&win(B,A%B)==0) ret=1;
	return memo[A][B]=ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	MINUS(memo);
	
	cin>>A>>B;
	/*
	for(x=1;x<=20;x++) {
		for(y=1;y<=20;y++) cout<<win(x,y);
		cout<<endl;
	}
	
	
	if(win(A,B)) {
		cout<<"Alice"<<endl;
	}
	else {
		cout<<"Bob"<<endl;
	}
	*/
	
	if(A==1||B==1||A==B||B<=A-2) {
		cout<<"Alice"<<endl;
	}
	else {
		cout<<"Bob"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
