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

int X[4],Y[4];

pair<int,int> dodo(int x1,int y1,int x2,int y2,int x3,int y3) {
	pair<int,int> r;
	
	r.first=-9999;
	int x4=x2+x3-x1;
	int y4=y2+y3-y1;
	
	int d12=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	int d13=(x1-x3)*(x1-x3)+(y1-y3)*(y1-y3);
	int d14=(x1-x4)*(x1-x4)+(y1-y4)*(y1-y4);
	int d23=(x2-x3)*(x2-x3)+(y2-y3)*(y2-y3);
	int d24=(x2-x4)*(x2-x4)+(y2-y4)*(y2-y4);
	int d34=(x3-x4)*(x3-x4)+(y3-y4)*(y3-y4);
	if(d12!=d13) return r;
	if(d12!=d24) return r;
	if(d12!=d34) return r;
	if(d14!=d23) return r;
	if(d14!=d12*2) return r;
	return make_pair(x4,y4);
}

void solve() {
	int i,j,k,l,x,y; string s;
	
	FOR(i,3) cin>>X[i]>>Y[i];
	pair<int,int> r;
	r=dodo(X[0],Y[0],X[1],Y[1],X[2],Y[2]);
	if(r.first>=-1000) return _P("%d %d\n",r.first,r.second);
	r=dodo(X[1],Y[1],X[0],Y[0],X[2],Y[2]);
	if(r.first>=-1000) return _P("%d %d\n",r.first,r.second);
	r=dodo(X[2],Y[2],X[0],Y[0],X[1],Y[1]);
	if(r.first>=-1000) return _P("%d %d\n",r.first,r.second);
	_P("-1\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
