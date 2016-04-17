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

int L,D;
int gr[501];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L>>D;
	for(i=1;i<=L;i++) {
		set<int> me;
		for(x=1;x<=i-1;x++) {
			for(y=x+1;i-(x+y)>y;y++) {
				r=i-x-y;
				if(r-x<=D) me.insert(gr[x]^gr[y]^gr[r]);
			}
		}
		while(me.count(gr[i])) gr[i]++;
	}
	
	if(gr[L]==0) _P("matsu\n");
	else _P("kado\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
