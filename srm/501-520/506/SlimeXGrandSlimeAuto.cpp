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

class MinCostFlow {
public:
	struct edge { int to, capacity; ll cost, reve;};
	static const int MV = 5000;
	vector<edge> E[MV];
	ll dist[MV], prev_v[MV], prev_e[MV], NV;
	
	MinCostFlow() { init(MV); }
	void init(int NV=MV) { this->NV=NV; for(int i=0;i<MV;i++) E[i].clear();}
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

class SlimeXGrandSlimeAuto {
	public:
	int mat[51][51];
	int travel(vector <int> cars, vector <int> districts, vector <string> roads, int inverseWalkSpeed, int inverseDriveSpeed) {
		
		int x,y,z;
		districts.insert(districts.begin(),0);
		
		int C=cars.size(),N=roads.size(),D=districts.size();
		FOR(x,N) FOR(y,N) {
			if(roads[x][y]=='.') mat[x][y]=1000000;
			if(roads[x][y]>='0' && roads[x][y]<='9') mat[x][y]=1+roads[x][y]-'0';
			if(roads[x][y]>='a' && roads[x][y]<='z') mat[x][y]=11+roads[x][y]-'a';
			if(roads[x][y]>='A' && roads[x][y]<='Z') mat[x][y]=37+roads[x][y]-'A';
			if(x==y) mat[x][y]=0;
		}
		FOR(z,N) FOR(x,N) FOR(y,N) mat[x][y]=min(mat[x][y],mat[x][z]+mat[z][y]);
		
		MinCostFlow mcf;
		FOR(y,C) {
			mcf.add_edge(200+y,1,1,0);
		}
		FOR(x,D-1) {
			mcf.add_edge(0,100+x,1,0);
			mcf.add_edge(100+x,1,1,mat[districts[x]][districts[x+1]]*inverseWalkSpeed);
			FOR(y,C) {
				mcf.add_edge(100+x,200+y,1,mat[districts[x]][cars[y]]*inverseWalkSpeed+mat[cars[y]][districts[x+1]]*inverseDriveSpeed);
			}
		}
		
		
		return mcf.mincost(0,1,D-1);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {
"..0.",
"...1",
"0..2",
".12."}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; int Arg4 = 1; int Arg5 = 36; verify_case(0, Arg5, travel(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {
".A.",
"A.B",
".B."}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arg4 = 1; int Arg5 = 262; verify_case(1, Arg5, travel(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arr0[] = {2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {
".a4",
"a..",
"4.."}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 1; int Arg5 = 95; verify_case(2, Arg5, travel(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {
".B.",
"B.A",
".A."}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arg4 = 1; int Arg5 = 262; verify_case(3, Arg5, travel(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arr0[] = {2,5,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,5,1,2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {
".12.4.",
"1....7",
"2..3..",
"..3..5",
"4.....",
".7.5.."}
; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 53; int Arg4 = 37; int Arg5 = 1259; verify_case(4, Arg5, travel(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SlimeXGrandSlimeAuto ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

