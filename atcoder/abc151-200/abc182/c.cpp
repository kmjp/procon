#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

string N;
int C[3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FORR(c,N) C[(c-'0')%3]++;
	
	int ret=0;
	FOR(x,C[0]+1) FOR(y,C[1]+1) FOR(r,C[2]+1) {
		if((y+r*2)%3==0) ret=max(ret,x+y+r);
	}
	
	if(ret==0) cout<<-1<<endl;
	else cout<<(int)N.size()-ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
