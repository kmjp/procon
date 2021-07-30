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

int A,B;
int memo[100][100];

int win(int A,int B) {
	if(A==0&&B) return 1;
	if(A&&B==0) return 1;
	if(memo[A][B]>=0) return memo[A][B];
	
	int ret=0;
	int x;
	for(x=1;x<=A;x++) {
		if(A-x==B) ret|=win(A-x,B);
		else ret|=(win(A-x,B)==0);
	}
	for(x=1;x<=B;x++) {
		if(B-x==A) ret|=win(A,B-x);
		else ret|=(win(A,B-x)==0);
	}
	return memo[A][B]=ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	/*
	MINUS(memo);
	for(x=1;x<=99;x++) {
		for(y=1;y<=99;y++) {
			if(win(x,y)==0) cout<<x<<" "<<y<<" "<<win(x,y)<<endl;
		}
	}
	*/
	
	cin>>A>>B;
	if(A==B&&A%2==1) {
		cout<<"Q"<<endl;
	}
	else if(B-A==1&&B%2==0 || A-B==1&&A%2==0) {
		cout<<"Q"<<endl;
	}
	else {
		cout<<"P"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
