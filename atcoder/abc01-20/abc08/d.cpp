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

int W,H;
int N;
int X[35],Y[35];
map<pair<pair<int,int>,pair<int,int> >, ll> M;

ll dfs(int l,int r,int t,int b) {
	if(l>r || t>b) return 0;
	pair<pair<int,int>,pair<int,int> > k=make_pair(make_pair(l,r),make_pair(t,b));
	if(M.find(k)!=M.end()) return M[k];
	int i;
	M[k]=0;
	FOR(i,N) if(X[i]>=l && X[i]<=r && Y[i]>=t && Y[i]<=b) {
		M[k]=max(M[k],r-l+b-t+1+dfs(l,X[i]-1,t,Y[i]-1)+dfs(X[i]+1,r,t,Y[i]-1)+dfs(l,X[i]-1,Y[i]+1,b)+dfs(X[i]+1,r,Y[i]+1,b));
	}
	return M[k];
	
}


void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>W>>H>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	cout << dfs(1,W,1,H) <<endl;
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


