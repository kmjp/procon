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

int N;
set<string> S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>s, S.insert(s);
	
	string a,b;
	a="iaaeuu";
	b="nbmgr";
	sort(ALL(a));
	sort(ALL(b));
	do {
		do {
			string c="          ";
			FOR(i,5) c[i*2]=b[i],c[i*2+1]=a[i];
			FOR(i,11) {
				s=c.substr(0,i)+a[5]+c.substr(i);
				if(S.count(s)==0) return _P("%s\n",s.c_str());
			}
		} while(next_permutation(ALL(b)));
	} while(next_permutation(ALL(a)));
	return _P("NO\n");
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
