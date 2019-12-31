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

string S;

string replace(string S,string from,string to) {
	auto pos=S.find(from);
	while(pos!=string::npos) {
		S.replace(pos,from.size(),to);
		pos = S.find(from,pos+to.size());
	}
	return S;
}

void dfs(string S) {
	if(S=="ABC") {
		cout<<"Yes"<<endl;
		exit(0);
	}
	string T[3]={"A","B","C"};
	string U=replace(S,"ABC","X");
	if(S==U) return;
	
	int i;
	FOR(i,3) if(count(ALL(U),T[i][0])==0) dfs(replace(U,"X",T[i]));
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	dfs(S);
	cout<<"No"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
