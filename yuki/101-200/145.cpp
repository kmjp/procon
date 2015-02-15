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

int N;
string S;
int abcdefgh,i,j,k,lmnopqrst,u,vwx,y,z;
int ret;

void solve() {
	int x; string s;
	
	cin>>N>>S;
	FOR(x,N) {
		if(S[x]=='z') z++;
		else if(S[x]=='y') y++;
		else if(S[x]>'u')  vwx++;
		else if(S[x]=='u') u++;
		else if(S[x]>'k')  lmnopqrst++;
		else if(S[x]=='k') k++;
		else if(S[x]>'i')  j++;
		else if(S[x]=='i') i++;
		else abcdefgh++;
	}
	
	while(y && u && k && i && abcdefgh) ret++, y--, u--, k--, i--, abcdefgh--;
	while(y && u && k && i>=2)          ret++, y--, u--, k--, i-=2;
	while(y && u && k && j)             ret++, y--, u--, k--, j--;
	while(y && u && k>=2)               ret++, y--, u--, k-=2;
	while(y && u && lmnopqrst)          ret++, y--, u--, lmnopqrst--;
	while(y && u>=2)                    ret++, y--, u-=2;
	while(y && vwx)                     ret++, y--, vwx--;
	while(y>=2)                         ret++, y-=2;
	while(z)                            ret++, z--;
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
