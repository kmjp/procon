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

int A,B,S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>A>>B>>S;
	
	if(abs(A-S)<=abs(B-S) || S==1) {
		x=abs(A-S)+S;
	}
	else {
		x=abs(B-S);
		if(A>S) {
			x+=min(A-S+A,(S-1)+A);
		}
		else if(A==0) {
			x+=(S-1)+2;
		}
		else x+=S;
	}
	cout<<x<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
