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

int N;
int D[101][101];
int S[101][101];

int Q;
int P[10001];
int DE[2501];

void solve() {
	int f,i,j,k,l,x,y;
	cin>>N;
	FOR(y,N) FOR(x,N) cin>>D[y][x];
	
	FOR(y,N) {
		FOR(x,N) S[y][x+1]=S[y][x]+D[y][x];
	}
	
	int h,w;
	for(h=1;h<=N;h++) for(w=1;w<=N;w++) {
		for(y=0;y<=N-h;y++) for(x=0;x<=N-w;x++) {
			j=0;
			FOR(i,h) j+=S[y+i][x+w]-S[y+i][x];
			DE[h*w]=max(DE[h*w],j);
		}
	}
	
	cin>>Q;
	FOR(y,Q) {
		cin>>x;
		int ma=0;
		FOR(i,x+1) ma=max(ma,DE[i]);
		cout<<ma<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


