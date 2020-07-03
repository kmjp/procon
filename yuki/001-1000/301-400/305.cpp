#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int dodo(string s) {
	int a;
	string t;
	cout<<s<<endl;
	cin>>a>>s;
	return a;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	string S="XXXXXXXXXX";
	string R="0000000000";
	
	FOR(i,10) {
		int hoge[10]={};
		FOR(x,10) {
			S[i]='0'+x;
			hoge[x]=dodo(S);
			if(hoge[x]==1) R[i]='0'+x;
		}
		S[i]='X';
	}
	cout<<R<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	solve(); return 0;
}
