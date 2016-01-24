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

int H,W,N;
int X[20],Y[20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	set<pair<int,int>> P;
	cin>>H>>W>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	if(N%2==1) return _P("-1\n");
	
	for(x=1;x<=W;x++) for(y=1;y<=H;y++) if(x==W || y==H) {
		int tot=0;
		FOR(i,N) {
			int v=x*Y[i]-y*X[i];
			if(v==0) tot-=100;
			if(v<0) tot++;
			if(v>0) tot--;
		}
		if(tot==0) P.insert({x,y});
	}
	
	if(P.size()==0) _P("-1\n");
	else {
		FORR(r,P) _P("(%d,%d)\n",r.first,r.second);
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
