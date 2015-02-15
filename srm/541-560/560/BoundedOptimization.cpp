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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG
#ifdef DEBUG
#define DBG(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define DV(...) cerr << __VA_ARGS__ << endl
#else
#define DBG(...)
#define DV(...)
#endif

typedef signed long long ll;
typedef unsigned long long ull;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------


class BoundedOptimization {
	public:
	int mat[20][20];
	string concatvec(vector <string> expr) {
		int i;
		string st="";
		FOR(i,expr.size()) st += expr[i];
		return st;
	}
	double maxValue(vector <string> expr, vector <int> lowerBound, vector <int> upperBound, int maxSum) {
		int i,l,af;
		string st=concatvec(expr);
		l=st.size();
		
		ZERO(mat);
		for(i=0;i<l;i+=3) mat[st.c_str()[i]-'a'][st.c_str()[i+1]-'a']++;
		af = maxSum;
		FOR(i,lowerBound.size()) af -= lowerBound[i];
		
		return 0;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ba+cb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; double Arg4 = 2.25; verify_case(0, Arg4, maxValue(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"ab"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {20, 20, 20}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 12; double Arg4 = 1.0; verify_case(1, Arg4, maxValue(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"ca+fc+fa+d","b+da+","dc+c","b","+ed+eb+ea"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,11,12,13,14,15}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {15,16,17,18,19,20}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 85; double Arg4 = 2029.25; verify_case(2, Arg4, maxValue(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"db+ea+ik+kh+je+","fj+lk+i","d+jb+h","a+gk+mb+ml+lc+mh+cf+fd+","gc+ka+gf+bh+mj+eg+bf+hf+l","b+al+ja+da+i",
"f+g","h+ia+le+ce+gi+d","h+mc+fe+dm+im+kb+bc+","ib+ma+eb+mf+jk+kc+mg+mk+","gb+dl+ek+hj+dg+hi","+ch+ga+ca+fl+ij+fa+jl+dc+dj+fk","+li+jg"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {57,29,50,21,49,29,88,33,84,76,95,55,11}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {58,80,68,73,52,84,100,79,93,98,95,69,97}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 845; double Arg4 = 294978.3333333333; verify_case(3, Arg4, maxValue(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  BoundedOptimization ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
