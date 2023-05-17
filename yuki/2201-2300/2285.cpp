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

int T;
ll A,B;

int G[222];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=2;i<=200;i++) {
		set<int> S;
		for(x=2;x<=i-x;x++) S.insert(G[x]^G[i-x]);
		while(S.count(G[i])) G[i]++;
	}
	
	
	cin>>T;
	while(T--) {
		cin>>A>>B;
		
		if(A>55) A-=(A-55)/34*34;
		if(B>55) B-=(B-55)/34*34;
		x=G[A]^G[B];
		if(x) {
			cout<<"First"<<endl;
		}
		else {
			cout<<"Second"<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
