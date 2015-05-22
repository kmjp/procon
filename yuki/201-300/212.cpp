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

int P,C;
int A[6]={2,3,5,7,11,13};
int B[6]={4,6,8,9,10,12};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int ave[2]={};
	FOR(i,6) ave[0]+=A[i];
	FOR(i,6) ave[1]+=B[i];
	
	cin>>P>>C;
	double hoge=1;
	FOR(i,P) hoge *= ave[0]/6.0;
	FOR(i,C) hoge *= ave[1]/6.0;
	
	_P("%.12lf\n",hoge);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
