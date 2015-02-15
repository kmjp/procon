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

class CircuitsConstruction {
	public:
	/*
char* p;
int e(){char c=*p++;return c=='X'?1:(c=='A'?e()+e():max(e(),e()));}
int maximizeResistance(string c, vector<int>v){int l=v.size();p=&c[0];sort(&v[0],&v[l]);return accumulate(&v[l-1-e()],&v[l],0);}
	*/
	int dfs() {
		char c=CC[cur++];
		
		if(c=='X') return 1;
		else if(c=='A') return dfs()+dfs();
		else return max(dfs(),dfs());
	}
	
	int maximizeResistance(string circuit, vector <int> conductors) {
		CC=circuit;
		cur=0;
		
		sort(conductors.begin(),conductors.end());
		return accumulate(conductors.rbegin(),conductors.rbegin()+dfs(),0);
	}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BXBXX"; int Arr1[] = {8, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(0, Arg2, maximizeResistance(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "AAXXAXAXX"; int Arr1[] = {1, 1, 2, 8, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 22; verify_case(1, Arg2, maximizeResistance(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "AXBXX"; int Arr1[] = {8, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 11; verify_case(2, Arg2, maximizeResistance(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "BAAXBXXBXAXXBBAXXBXXAAXXX"; int Arr1[] = {17, 7, 21, 102, 56, 72, 88, 15, 9, 192, 16, 8, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 454; verify_case(3, Arg2, maximizeResistance(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE 
int main(int argc,char** argv) {
  CircuitsConstruction ___test;
  if(argc==1)  ___test.run_test(-1);
  else  ___test.run_test(atoi(argv[1]));
}
