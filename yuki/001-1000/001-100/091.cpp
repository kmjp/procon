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

ll V[3];

bool ok(ll v) {
	ll left=0;
	ll hu=0;
	if(V[0]>=v) left+=(V[0]-v)/2;
	if(V[1]>=v) left+=(V[1]-v)/2;
	if(V[2]>=v) left+=(V[2]-v)/2;
	if(V[0]<v) hu+=v-V[0];
	if(V[1]<v) hu+=v-V[1];
	if(V[2]<v) hu+=v-V[2];
	return left>=hu;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>V[0]>>V[1]>>V[2];
	
	ll ret=0;
	for(i=40;i>=0;i--) if(ok(ret+(1LL<<i))) ret+=1LL<<i;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
