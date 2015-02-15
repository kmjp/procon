#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

//-------------------------------------------------------

class MinCostFlow {
public:
	struct edge { int to, capacity; ll cost, reve;};
	static const int MV = 100;
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


class GoodCompanyDivOne {
	public:
	int N,K;
	int dpdp[50][50];
	vector<int> C[51];
	vector<int> T;
	
	void dfs(int cur) {
		int i,j,x,y;
		
		if(C[cur].empty()) {
			FOR(i,K) dpdp[cur][i]=T[i];
			return;
		}
		
		FOR(i,C[cur].size()) dfs(C[cur][i]);
		
		FOR(i,K) {
			MinCostFlow mf;
			
			mf.add_edge(0,10+cur,1,0);
			mf.add_edge(10+cur,50+i,1,T[i]);
			FOR(j,C[cur].size()) {
				int tar=C[cur][j];
				mf.add_edge(0,10+tar,1,0);
				FOR(x,K) {
					int mi=1<<20;
					FOR(y,K) {
						if(x==y) {
							if(x==0) mi=min(mi,dpdp[tar][x]+T[1]);
							else mi=min(mi,dpdp[tar][x]+T[0]);
						}
						else {
							mi=min(mi,dpdp[tar][y]+T[x]);
						}
					}
					mf.add_edge(10+tar,50+x,1,mi);
				}
			}
			
			FOR(j,K) mf.add_edge(50+j,1,1,0);
			dpdp[cur][i]=mf.mincost(0,1,1+C[cur].size());
			if(dpdp[cur][i]==-1) dpdp[cur][i]=1<<20;
		}
	}
	
	
	int minimumCost(vector <int> superior, vector <int> training) {
		int i,x,y;
		
		T=training;
		N=superior.size();
		K=T.size();
		
		sort(T.begin(),T.end());
		if(N==1) return T[0]+T[1];
		
		ZERO(C);
		for(i=1;i<N;i++) C[superior[i]].push_back(i);
		
		FOR(x,N) FOR(y,K) dpdp[x][y]=1<<20;
		
		
		dfs(0);
		int ret=1<<20;
		FOR(i,K) {
			if(i==0) ret=min(ret,dpdp[0][i]+T[1]);
			else ret=min(ret,dpdp[0][i]+T[0]);
		}
		if(ret>=1<<20) return -1;
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(0, Arg2, minimumCost(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-1, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(1, Arg2, minimumCost(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-1, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, minimumCost(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-1, 0, 0, 2, 2, 2, 1, 1, 6, 0, 5, 4, 11, 10, 3, 6, 11, 7, 0, 2, 13, 14, 2, 10, 9, 11, 22, 10, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 2, 6, 6, 8, 3, 3, 1, 1, 5, 8, 6, 8, 2, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 71; verify_case(3, Arg2, minimumCost(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  GoodCompanyDivOne ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
