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

string N;

map<string,int> M;

int dp(string s) {
	if(s.size()<3) return 0;
	if(M.count(s)) return M[s];
	
	int ma=0;
	
	int x,y,z;
	FOR(z,s.size()) FOR(y,z) if(s[y]==s[z]) FOR(x,y) if(s[x]!='0' && s[x]!=s[y]) {
		ma=max(ma, (s[x]-'0')*100+(s[y]-'0')*11+dp(s.substr(0,x)+s.substr(x+1,y-x-1)+s.substr(y+1,z-y-1)+s.substr(z+1)));
	}
	
	
	return M[s]=ma;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	cout<<dp(N)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
