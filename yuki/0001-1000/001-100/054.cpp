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

int N,V[10002],T[10002];
int ok[20001];
pair<int,int> P[10001];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N;
	FOR(i,N) cin>>V[i]>>T[i];
	FOR(i,N) P[i]=make_pair(V[i]+T[i],i);
	sort(P,P+N);
	
	ok[0]=1;
	FOR(i,N) for(x=T[P[i].second]-1;x>=0;x--) if(ok[x]) ok[x+V[P[i].second]]=1;
	
	
	for(i=20000;i>=0;i--) if(ok[i]) break;
	_P("%d\n",i);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
