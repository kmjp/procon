#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int KR,KB;
string S;
int ms[31];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>KR>>KB>>S;
	j=0;
	
	FOR(i,30) {
		if(S[i]=='W') ms[i]=21;
		else ms[i]=j++;
	}
	
	int ma=0;
	FOR(i,1<<20) {
		string T;
		int ok=1;
		FOR(j,30) if((i&(1<<ms[j]))==0) {
			T+=S[j];
			if(S[j]=='R' && T.size()>KR && T[T.size()-KR-1]=='R') ok=0;
			if(S[j]=='B' && T.size()>KB && T[T.size()-KB-1]=='B') ok=0;
		}
		if(ok) ma=max(ma,(int)T.size());
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
