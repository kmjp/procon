#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
set<string> T;
string S;

void dfs(int cur) {
	if(S.size()==N) {
		cout<<S<<endl;
		return;
	}
	
	for(int i=0;i<=cur;i++) {
		S+='a'+i;
		dfs((i==cur)?(cur+1):cur);
		S.pop_back();
	}
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	dfs(0);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
