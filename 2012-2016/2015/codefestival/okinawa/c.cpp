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

int gr[8];
int N;
string S[3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	gr[3]=gr[6]=1;
	gr[7]=2;
	
	int ret=0,turn=0;
	cin>>N;
	FOR(i,N) {
		cin>>S[0]>>S[1]>>S[2];
		x = ((S[0][0]=='#')<<2) + ((S[1][1]=='#')<<1) + ((S[2][2]=='#')<<0);
		turn += __builtin_popcount(7^x);
		ret ^= gr[x];
	}
	if((turn%2==0)^(ret>0)) _P("Sothe\n");
	else _P("Snuke\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
