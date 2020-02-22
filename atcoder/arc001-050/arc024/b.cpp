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
int C[100001];

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>N;
	FOR(i,N) cin>>C[i];
	if(count(C,C+N,0)==N) return _P("-1\n");
	if(count(C,C+N,1)==N) return _P("-1\n");
	FOR(i,N) if(C[i]!=C[(i+N-1)%N]) break;
	vector<int> V;
	V.push_back(1);
	for(j=1;j<N;j++) {
		if(C[(i+j)%N]==C[(i+j-1)%N]) V.back()++;
		else V.push_back(1);
	}
	y=1;
	sort(V.begin(),V.end());
	
	cout << 1+(V.back()-1)/2 << endl;
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


