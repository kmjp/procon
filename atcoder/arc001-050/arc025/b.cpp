#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int H,W,C[105][105];
ll sum[105][105];

void solve() {
	int f,i,j,k,l,x,y,y2,x2;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>C[y][x];
	FOR(y,H) FOR(x,W) if((x+y)%2) C[y][x]=-C[y][x];
	FOR(y,H) FOR(x,W) {
		FOR(y2,y+1) FOR(x2,x+1) sum[y+1][x+1]+=C[y2][x2];
	}
	int ma=0;
	int h,w;
	FOR(y,H) FOR(x,W) {
		for(h=1;y+h<=H;h++) for(w=1;x+w<=W;w++) if(h*w>ma) {
			if(sum[y+h][x+w]-sum[y+h][x]-sum[y][x+w]+sum[y][x]==0) ma=h*w;
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


