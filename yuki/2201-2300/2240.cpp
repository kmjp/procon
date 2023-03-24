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
string S;
set<int> W,A,C;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S;
	
	FOR(i,S.size()) {
		if(S[i]=='W') W.insert(i);
		if(S[i]=='A') A.insert(i);
		if(S[i]=='C') C.insert(i);
	}
	while(W.size()) {
		x=*W.rbegin();
		W.erase(x);
		y=*A.rbegin();
		A.erase(y);
		if(x>y) {
			cout<<"No"<<endl;
			return;
		}
	}
	while(A.size()) {
		x=*A.begin();
		A.erase(x);
		y=*C.begin();
		C.erase(y);
		if(x>y) {
			cout<<"No"<<endl;
			return;
		}
	}
	cout<<"Yes"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
