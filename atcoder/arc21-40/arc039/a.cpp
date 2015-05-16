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


int ok(int x,int y) {
	int d=0;
	if(x/100%10!=y/100%10) d++;
	if(x/10%10!=y/10%10) d++;
	if(x%10!=y%10) d++;
	return d<=1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int A,B;
	cin>>A>>B;
	
	int ma=A-B;
	for(int x=100;x<=999;x++) if(ok(A,x)) ma=max(ma,x-B);
	for(int x=100;x<=999;x++) if(ok(B,x)) ma=max(ma,A-x);
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
