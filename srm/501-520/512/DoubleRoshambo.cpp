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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef signed long long ll;
typedef unsigned long long ull;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(x) x.begin(),x.end()
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int sc[51][51];
class MinCostFlow {
public:
	struct edge { int to, capacity; ll cost, reve;};
	static const int MV = 5000;
	vector<edge> E[MV];
	ll dist[MV], prev_v[MV], prev_e[MV], NV;
	
	void init(int NV) { this->NV=NV; for(int i=0;i<MV;i++) E[i].clear();}
	void add_edge(int x,int y, int cap, int cost) {
		E[x].push_back((edge){y,cap,cost,E[y].size()});
		E[y].push_back((edge){x,0, -cost,E[x].size()-1}); /* rev edge */
	}
	
	int mincost(int from, int to, int flow) {
		int res=0,i,v;
		ZERO(prev_v); ZERO(prev_e);
		while(flow>0) {
			fill(dist, dist+NV, 1LL<<50);
			dist[from]=0;
			bool up=true;
			while(up) {
				up=false;
				FOR(v,NV) {
					if(dist[v]==1LL<<50) continue;
					FOR(i,E[v].size()) {
						edge &e=E[v][i];
						if(e.capacity>0 && dist[e.to]>dist[v]+e.cost) {
							dist[e.to]=dist[v]+e.cost;
							prev_v[e.to]=v;
							prev_e[e.to]=i;
							up=true;
						}
					}
				}
			}
			
			if(dist[to]==1LL<<50) return -1;
			int lc=flow;
			for(v=to;v!=from;v=prev_v[v]) lc = min(lc, E[prev_v[v]][prev_e[v]].capacity);
			flow -= lc;
			res += lc*dist[to];
			for(v=to;v!=from;v=prev_v[v]) {
				edge &e=E[prev_v[v]][prev_e[v]];
				e.capacity -= lc;
				E[v][e.reve].capacity += lc;
			}
		}
		return res;
	}
};

class DoubleRoshambo {
	public:
	int N;
	int maxScore(vector <string> A, vector <string> E) {
		N=A.size();
		int x,y;
		MinCostFlow mcf;
		mcf.init(1000);
		FOR(x,N) mcf.add_edge(200,x,1,0);
		FOR(x,N) mcf.add_edge(100+x,300,1,0);
		
		ZERO(sc);
		FOR(x,N) FOR(y,N) {
			int c=2;
			if((A[x][1]=='R' && E[y][1]=='S') || 
			   (A[x][1]=='S' && E[y][1]=='P') || 
			   (A[x][1]=='P' && E[y][1]=='R')) {
				c--;
				if((A[x][0]=='R' && E[y][0]=='S') ||
		             (A[x][0]=='S' && E[y][0]=='P') ||
				             (A[x][0]=='P' && E[y][0]=='R'))
				             c--;
				else if(A[x][0]!=E[y][0]) c=2;
			}
			mcf.add_edge(x,100+y,1,c);
		}
		return 2*N-mcf.mincost(200,300,N);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"RR"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"SS"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, maxScore(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"SR", "PP"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"PR", "RS"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, maxScore(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"PP", "PP", "PP", "PP"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"RR", "PR", "SS", "SP"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, maxScore(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"PS", "RS", "PP", "SP", "RR", "SS", "SP"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"RP", "SP", "RR", "SR", "RS", "SP", "SS"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(3, Arg2, maxScore(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DoubleRoshambo ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

