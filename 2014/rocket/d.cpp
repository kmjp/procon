#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

int N,M;
struct hoge {int x,y,l;};
hoge V[50001],H[50001];

bool cmp(const hoge& l,const hoge& r) {
	return l.x<r.x;
}

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>N>>M;
	FOR(i,N) cin>>V[i].x>>V[i].y>>V[i].l;
	FOR(i,M) cin>>H[i].x>>H[i].y>>H[i].l;
	sort(V,V+N,cmp);
	sort(H,H+M,cmp);
	int ma=0;
	FOR(i,M) {
		FOR(j,N) {
			if(V[j].x-H[i].x<=ma) continue;
			if(H[i].x+H[i].l-V[j].x<=ma) continue;
			int miw = min(V[j].x-H[i].x,H[i].x+H[i].l-V[j].x);
			int mih = min(H[i].y-V[j].y,V[j].y+V[j].l-H[i].y);
			ma=max(ma,min(miw,mih));
		}
	}
	
	cout << ma << endl;
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


