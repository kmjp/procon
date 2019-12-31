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
int P[1001],L[1001],R[1001];
char C[1001];
map<int,int> UN;

class TopologicalSort {
public:
	static const int MV = 10000;
	int NV,NIE[MV];
	vector<int> OutEdge[MV];
	
	TopologicalSort(int nv){init(nv);}
	void init(int nv) { NV=nv; for(int i=0;i<NV;i++) OutEdge[i].clear(), NIE[i]=0;}
	void add_edge(int x,int y) { OutEdge[x].push_back(y); NIE[y]++;}
	
	vector<int> sort() {
		int i,nv=0;
		vector<int> NI,R;
		NI.reserve(NV);
		R.reserve(NV);
		queue<int> S;
		FOR(i,NV) {
			NI.push_back(NIE[i]);
			nv+=OutEdge[i].size();
			if(NIE[i]==0) S.push(i);
		}
		
		while(!S.empty()) {
			int cur=S.front();
			S.pop();
			R.push_back(cur);
			ITR(it,OutEdge[cur]){
				nv--;
				if(--NI[*it]==0) S.push(*it);
			}
		}
		if(nv) return vector<int>();
		return R;
	}
};

int check(int pi) {
	int i,j;
	TopologicalSort ts(N);
	FOR(i,pi) {
		for(j=UN[L[i]];j<=UN[R[i]];j++) {
			if(C[i]=='w') ts.add_edge(j,UN[P[i]]);
			else ts.add_edge(UN[P[i]],j);
		}
	}
	
	return !ts.sort().empty();
}

void solve() {
	int f,i,j,k,l,x,y;
	string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>P[i]>>C[i]>>L[i]>>R[i];
		UN[P[i]]=UN[L[i]]=UN[R[i]]=0;
	}
	N=0;
	ITR(it,UN) it->second=N++;
	
	int lo=1,hi=M;
	FOR(k,12) {
		int pi=(lo+hi)/2;
		if(check(pi)) lo=pi;
		else hi=pi;
	}
	
	hi=max(hi-2,0);
	while(1) {
		if(check(hi)==1) {
			if(hi==M) return _P("0\n");
			hi++;
		}
		else return _P("%d\n",hi);
	}
}


int main(int argc,char** argv){
	if(argc>1) freopen(argv[1], "r", stdin);
	solve();
	return 0;
}


