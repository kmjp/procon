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

int ok[101010];
string S;
int L;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ok[0]=1;
	cin>>S;
	L=S.size();
	FOR(i,L) if(ok[i]) {
		if(i+5<=L && S.substr(i,5)=="dream") ok[i+5]=1;
		if(i+7<=L && S.substr(i,7)=="dreamer") ok[i+7]=1;
		if(i+5<=L && S.substr(i,5)=="erase") ok[i+5]=1;
		if(i+6<=L && S.substr(i,6)=="eraser") ok[i+6]=1;
	}
	
	if(ok[L]) _P("YES\n");
	else _P("NO\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
