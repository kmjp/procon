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


void solve() {
	int i,j,k,l,r,x,y; string s;
	int N;
	ll A1=0,A2=0,B1,B2;
	
	cin>>N;
	FOR(i,N) {
		cin>>s;
		
		int minus=1;
		if(s[0]=='-') minus=-1, s=s.substr(1);
		
		FOR(j,s.size()) if(s[j]=='.') break;
		if(j==s.size()) s+=".";
		while(s.size()-j<11) s+="0";
		
		sscanf(s.c_str(),"%lld.%lld",&B1,&B2);
		A1 += B1*minus;
		A2 += B2*minus;
	}
	
	while(A2>=10000000000LL) A2-=10000000000LL,A1++;
	while(A2<0) A2+=10000000000LL,A1--;
	
	if(A1==-1 && A2>0) A1++,A2=10000000000LL-A2, _P("-");
	if(A1<0 && A2>0) A1++,A2=10000000000LL-A2;
	_P("%lld.%010lld\n",A1,A2);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
