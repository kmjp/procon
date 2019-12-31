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

vector<string> S[21];

void dpdp(int N) {
	int i;
	
	FOR(i,S[N-3].size()) S[N].push_back("iw"+S[N-3][i]);
	FOR(i,S[N-2].size()) S[N].push_back("ii"+S[N-2][i]);
	FOR(i,S[N-2].size()) S[N].push_back("w"+S[N-2][S[N-2].size()-1-i]);
}

void solve() {
	int f,i,j,k,l,x,y;
	int N,mask;
	
	cin>>N;
	S[1].push_back("i");
	S[2].push_back("ii");
	S[2].push_back("w");
	S[3].push_back("iw");
	S[3].push_back("iii");
	S[3].push_back("wi");
	for(i=4;i<=N;i++) dpdp(i);
	
	ITR(it,S[N]) cout<<*it<<endl;
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


