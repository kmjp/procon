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

int T,N;
string S;

int hoge(string T) {
	int i;
	int C=0;
	FORR(c,T) if(c=='0') C++;
	if(C==0) return 1;
	FOR(i,T.size()-1) if(T[i]=='0'&&T[i+1]=='0') return 1;
	if(T[0]=='0'||T.back()=='0') return 1;
	return C%2==0;
	
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		int ok=1;
		string T;
		FORR(c,S) {
			if(T.size()&&T.back()=='1'&&c=='1') {
				ok=ok&hoge(T);
				T="";
			}
			T+=c;
		}
		ok=ok&hoge(T);
		if(ok) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
