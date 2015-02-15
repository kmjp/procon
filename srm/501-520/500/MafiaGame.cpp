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

class MafiaGame {
	public:
	int N;
	double dpdp(vector<int> V) {
		int tot=N,i;
		int fm=0,lm=0;
		vector<int> V2=V,V3;
		
		if(V.size()==1) return 1;
		
		fm=count(V.begin(),V.end(),V[V.size()-1]);
		
		ITR(it,V) tot-=*it;
		
		FOR(i,tot) {
			sort(V2.begin(),V2.end());
			V2[0]++;
		}
		
		sort(V2.begin(),V2.end());
		lm=count(V2.begin(),V2.end(),V2[V2.size()-1]);
		
		if(lm==V.size()) return 0;
		FOR(i,lm) V3.push_back(V[V.size()-1-i]);
		
		if(fm>lm) return dpdp(V3)*lm/fm;
		else return dpdp(V3);
	}
	
	double probabilityToLose(int N, vector <int> decisions) {
		map<int,int> M;
		vector<int> V(N,0);
		ITR(it,decisions) V[*it]++;
		
		sort(V.begin(),V.end());
		
		this->N=N;
		return 1*dpdp(V);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(0, Arg2, probabilityToLose(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(1, Arg2, probabilityToLose(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 20; int Arr1[] = {1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 18, 19, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(2, Arg2, probabilityToLose(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 23; int Arr1[] = {17, 10, 3, 14, 22, 5, 11, 10, 22, 3, 14, 5, 11, 17}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.14285714285714285; verify_case(3, Arg2, probabilityToLose(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MafiaGame ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

