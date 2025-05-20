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

int N,K;
string S;
string T;

void dfs(int& cur) {
	if(cur==N) return;
	int num=0;
	assert(S[cur]=='(');
	cur++;
	T+="(";
	while(S[cur]!=')') {
		if(num) T+="+";
		num++;
		dfs(cur);
	}
	if(num==0) {
		T+="1+1";
		K-=2;
	}
	else if(num==1) {
		T+="+1";
		K-=1;
	}
	
	cur++;
	T+=")";
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	x=0;
	FORR(c,S) {
		if(c=='(') x++;
		else x--;
		if(x<0) break;
	}
	if(x) {
		cout<<"No"<<endl;
		return;
	}
	S="("+S+")";
	N+=2;
	int cur=0;
	dfs(cur);
	
	if(K<0) {
		cout<<"No"<<endl;
		return;
	}
	T=T.substr(1,T.size()-2);
	while(K--) T+="+1";
	cout<<"Yes"<<endl;
	cout<<T<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
