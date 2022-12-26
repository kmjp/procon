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


ll p10[10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	int N;
	cin>>N;
	
	ll ma=N;
	p10[0]=1;
	
	FOR(i,9) p10[i+1]=p10[i]*10;
	
	for(x=0;x<=9;x++) for(y=x+1;y<=9;y++) {
		if(p10[y]>N) continue;
		ma=max(ma,N-(N/p10[x]%10)*p10[x]-(N/p10[y]%10)*p10[y]+(N/p10[x]%10)*p10[y]+(N/p10[y]%10)*p10[x]);
		
	}
	cout << ma << endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
