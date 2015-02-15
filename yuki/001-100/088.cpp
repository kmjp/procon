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

string P,S[10];
int num;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>P;
	j=0;
	FOR(y,8) {
		cin>>S[y];
		FOR(x,8) j+=S[y][x]!='.';
	}
	if(j%2==0 ^ P=="oda" ^ 1) cout<<"oda"<<endl;
	else cout<<"yukiko"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
