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
int grundy[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	grundy[1]=0;
	for(i=2;i<=100;i++) {
		set<int> s;
		s.insert(grundy[i/2]^grundy[(i+1)/2]);
		if(i>=3) s.insert(grundy[i/3]^grundy[(i+1)/3]^grundy[(i+2)/3]);
		while(s.count(grundy[i])) grundy[i]++;
	}
	
	if(grundy[N]!=0) cout<<"A"<<endl;
	else cout<<"B"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
