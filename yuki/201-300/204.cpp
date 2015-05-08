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

int D;
string S,T;
int A[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>D>>S>>T;
	S+=T;
	int ma=0;
	S="xxxxxxxxxxxxxxxxxx"+S+"xxxxxxxxxxxxxxxxxxxxx";
	FOR(x,S.size()) {
		T=S;
		for(y=x;y<x+D;y++) {
			if(T[y]=='o') break;
			T[y]='o';
		}
		ZERO(A);
		FOR(i,S.size()) if(T[i]=='o') ma=max(ma,A[i+1]=A[i]+1);
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
