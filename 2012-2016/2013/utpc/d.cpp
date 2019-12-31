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
ll A[3000];
ll B[3000];

void solve() {
	int f,i,j,k,l,x,y;
	cin>>N;
	FOR(i,N) cin>>A[i];
	set<int> S;
	FOR(i,N) S.insert(A[i]);
	FOR(i,680) {
		set<int> S2=S;
		int ng=0;
		FOR(x,N) B[i+x]=A[x];
		
		for(x=i+N-1;x>=0;x--) {
			if(x>=i) {
				if(2*x+1<N+i && B[x]>B[2*x+1]) ng=1;
				if(2*x+2<N+i && B[x]>B[2*x+2]) ng=1;
			}
			else {
				if(2*x+1 >= N+i) {
					B[x]=1000000000+10000;
				}
				else {
					B[x]=B[2*x+1]-1;
					if(2*x+2 < N+i) B[x]=min(B[x],B[2*x+2]-1);
					while(S2.find(B[x])!=S2.end()) B[x]--;
					
					if(B[x]<0) ng++;
					S2.insert(B[x]);
				}
			}
		}
		
		if(ng==0) return _P("%d\n",i+N);
	}
	_P("-1\n");
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


