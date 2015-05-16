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

int K;
string S;

set<pair<int,int> > XS[404000],YS[404000];

int moveto(set<pair<int,int> >& SS, int v,int dir) {
	auto it=SS.lower_bound(make_pair(v,v));
	if(dir) it--;
	auto r=*it;
	SS.erase(it);
	
	if(dir) v=r.second--;
	else v=r.first++;
	
	if(r.first<=r.second) SS.insert(r);
	return v;
}

void insertto(set<pair<int,int> >& SS, int v) {
	auto it=SS.lower_bound(make_pair(v,v));
	if(it==SS.end() || it->first>v) it--;
	
	auto r=*it,r2=*it;
	SS.erase(r);
	
	r.second=v-1;
	r2.first=v+1;
	
	if(r.first<=r.second) SS.insert(r);
	if(r2.first<=r2.second) SS.insert(r2);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>S;
	FOR(i,404000) XS[i].insert(make_pair(0,404000));
	FOR(i,404000) YS[i].insert(make_pair(0,404000));
	
	x=202000,y=202000;
	insertto(XS[y],x);
	insertto(YS[x],y);
	
	FORR(c,S) {
		if(c=='U' || c=='D') {
			y=moveto(YS[x],y,c=='D');
			insertto(XS[y],x);
		}
		if(c=='L' || c=='R') {
			x=moveto(XS[y],x,c=='L');
			insertto(YS[x],y);
		}
	}
	_P("%d %d\n",x-202000,y-202000);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
