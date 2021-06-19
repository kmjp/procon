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

string S;
int N;
deque<char> A;
int side=0;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	
	FORR(c,S) {
		if(c=='R') side^=1;
		else if(A.size()==0) {
			A.push_back(c);
		}
		else if(side==0) {
			if(A.back()==c) A.pop_back();
			else A.push_back(c);
		}
		else {
			if(A[0]==c) A.pop_front();
			else A.push_front(c);
		}
	}
	
	string ret;
	FOR(i,A.size()) {
		if(side==0) ret+=A[i];
		else ret+=A[A.size()-1-i];
	}
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
