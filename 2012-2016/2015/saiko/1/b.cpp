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

set<string> R[17];
string S,T;

bool inc(string sub,string full) {
	int cur=0;
	FORR(r,full) if(cur<sub.size() && sub[cur]==r) cur++;
	return cur==sub.size();
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T;
	for(int mask=0;mask<1<<S.size();mask++) {
		s="";
		FOR(i,S.size()) if(mask&(1<<i)) s+=S[i];
		if(inc(s,T)) R[s.size()].insert(s);
	}
	for(i=16;i>=0;i--) {
		if(R[i].size()) {
			cout<<R[i].size()<<endl;
			FORR(r,R[i]) cout<<r<<endl;
			break;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
