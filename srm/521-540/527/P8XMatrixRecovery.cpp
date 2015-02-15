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

class MaxFlow {
public:
	struct edge { int to, capacity, reve;};
	static const int MV = 10000;
	vector<edge> E[MV];
	int vis[MV];
	
	void init() { for(int i=0;i<MV;i++) E[i].clear();}
	MaxFlow() {init();}
	void add_edge(int x,int y, int cap) {
		E[x].push_back((edge){y,cap,E[y].size()});
		E[y].push_back((edge){x,0, E[x].size()-1}); /* rev edge */
	}
	
	int dfs(int from,int to,int cf) {
		int i,tf;
		if(from==to) return cf;
		vis[from]=1;
		FOR(i,E[from].size()) {
			edge& e=E[from][i];
			if(vis[e.to]==0 && e.capacity>0 && (tf = dfs(e.to,to,min(cf,e.capacity)))>0) {
				e.capacity -= tf;
				E[e.to][e.reve].capacity += tf;
				return tf;
			}
		}
		return 0;
	}
	
	int maxflow(int from, int to) {
		int fl=0,tf;
		while(1) {
			ZERO(vis);
			if((tf = dfs(from,to,1<<29))==0) return fl;
			fl+=tf;
		}
	}
};


class P8XMatrixRecovery {
	public:
	
	vector <string> solve(vector <string> rows, vector <string> columns) {
		int R=rows.size(),C=columns.size();
		int i,x,y,z,x1,y1;
		MaxFlow mf;
		
		FOR(y1,R) FOR(x1,C) if(rows[y1][x1]=='?') {
			rows[y1][x1]='0';
			
			MaxFlow mf;
			FOR(i,C) mf.add_edge(0,100+i,1);
			FOR(i,C) mf.add_edge(200+i,300,1);
			FOR(x,C) {
				FOR(y,C) {
					i=1;
					FOR(z,R) if(rows[z][y]!='?' && columns[x][z]!='?' && rows[z][y]!=columns[x][z]) i=0;
					if(i) mf.add_edge(100+x,200+y,1);
				}
			}
			
			if(mf.maxflow(0,300)!=C) rows[y1][x1]='1';
		}
		
		return rows;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"10?"
,"?11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"01"
,"10"
,"1?"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"101", "011" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"0"
,"?"
,"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0?1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0", "0", "1" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"10"
,"01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"10"
,"01"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"10", "01" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"??0"
,"11?"
,"?01"
,"1?1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1???"
,"?111"
,"0?1?"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"010", "110", "101", "101" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  P8XMatrixRecovery ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
