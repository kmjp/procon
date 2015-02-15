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


int N,M;
int ti=0;
int C[100010],num[100010];
int L[100010],R[100010],C2[100010];
vector<int> E[100010];
int Q[100010],LQ[100010],RQ[100010],K[100010],ID[100010];
int cs[100010],csc[100010],res[100010];

void dfs(int cur,int pre) {
	int i;
	int pi=-1;
	
	L[cur]=ti++;
	C2[L[cur]]=C[cur];
	num[cur]=1;
	FOR(i,E[cur].size()) {
		int tar=E[cur][i];
		if(pre!=tar) dfs(tar,cur), num[cur]+=num[tar];
	}
	R[cur]=ti-1;
}

int cmp(int a,int b) {
	if(LQ[a]==LQ[b]) return RQ[a]<RQ[b];
	return LQ[a]<LQ[b];
}

void solve() {
	int f,i,j,k,l,x,y;
	
	cin>>N>>M;
	FOR(i,N) cin>>C[i];
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,-1);
	FOR(i,M) {
		cin>>x>>K[i];
		Q[i]=x-1;
		ID[i]=i;
		LQ[i]=L[Q[i]]/333;
		RQ[i]=R[Q[i]];
	}
	sort(ID,ID+M,cmp);
	int cl=0,cr=0;
	cs[C2[0]]=1;
	csc[1]=1;
	FOR(i,M) {
		j=Q[ID[i]];
		while(cl<L[j]) csc[cs[C2[cl++]]--]--;
		while(cr<R[j]) csc[++cs[C2[++cr]]]++;
		while(cl>L[j]) csc[++cs[C2[--cl]]]++;
		while(cr>R[j]) csc[cs[C2[cr--]]--]--;
		res[ID[i]]=csc[K[ID[i]]];
	}
	FOR(i,M) _P("%d\n",res[i]);
	
}


int main(int argc,char** argv){
	string s;
	ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


