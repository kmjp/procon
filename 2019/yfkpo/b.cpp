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

int K,Y,X;

char S[505][505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>Y>>X;
	
	i=0;
	FOR(y,500) {
		if(y%2==0) FOR(x,K) S[y][x]="yfkpo"[i++%5];
		else FOR(x,K) S[y][K-1-x]="yfkpo"[i++%5];
	}
	cout<<S[Y-1][X-1]<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
