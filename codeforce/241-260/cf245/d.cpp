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

int N;
ll A[100001];
ll S[100001];

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		S[i]=((i>0)?S[i-1]:0)+A[i];
	}
	ll ma=1LL<<50;
	FOR(x,100000) for(j=1;j<=1001 && x+j<N;j++) {
		if(j*(ll)j>=ma) break;
		ma=min(ma,j*(ll)j+(S[x+j]-S[x])*(S[x+j]-S[x]));
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


