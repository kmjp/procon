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

int N,M;
string S,T;

int can(int x) {
	if(x<0||x+M>N) return 0;
	int i;
	FOR(i,M) if(S[x+i]!='#'&&S[x+i]!=T[i]) return 0;
	int up=0;
	FOR(i,M) {
		if(S[x+i]!='#') up++;
		S[x+i]='#';
	}
	return up;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S>>T;
	queue<int> Q;
	FOR(i,N-M+1) {
		if(can(i)) Q.push(i);
	}
	
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		for(i=cur-M;i<=cur+M;i++) if(can(i)) Q.push(i);
	}
	
	if(count(ALL(S),'#')==N) {
		cout<<"Yes"<<endl;
	}
	else {
		cout<<"No"<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
