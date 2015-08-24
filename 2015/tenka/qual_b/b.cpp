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

string S;
int cur;

int dfs() {
	
	if(S[cur]!='{') {
		while(S[cur]>='0' && S[cur]<='9') cur++;
		return 2;
	}
	cur++;
	if(S[cur]=='}') return cur++,0; //dict
	
	dfs();
	if(S[cur]==':') { //dict
		cur++;
		dfs();
		while(S[cur]!='}') cur++, dfs(), cur++, dfs();
		cur++;
		return 0;
	}
	else { //set
		while(S[cur]!='}') cur++, dfs();
		cur++;
		return 1;
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>S;
	
	if(dfs()==0) cout<<"dict"<<endl;
	else cout<<"set"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
