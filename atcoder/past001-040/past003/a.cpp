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

string S,T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T;
	if(S==T) {
		cout<<"same"<<endl;
	}
	else {
		int ok=1;
		FOR(i,S.size()) {
			int ng=1;
			if(S[i]==T[i]) ng=0;
			if(S[i]+'A'-'a'==T[i]) ng=0;
			if(T[i]+'A'-'a'==S[i]) ng=0;
			if(ng) ok=0;
		}
		if(ok) cout<<"case-insensitive"<<endl;
		else cout<<"different"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
