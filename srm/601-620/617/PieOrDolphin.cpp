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

class PieOrDolphin {
	public:
	int N;
	vector<int> V;
	int edge[51];
	queue<int> E[51];
	vector<int> C1,C2;
	
	void dfs(int cur) {
		int i;
		while(!E[cur].empty()) {
			int e=E[cur].front();
			E[cur].pop();
			
			if(V[abs(e)-1]) continue;
			
			edge[cur]--;
			if(e<0) {
				V[-e-1]=1;
				edge[C1[-e-1]]--;
				dfs(C1[-e-1]);
			}
			else {
				V[e-1]=2;
				edge[C2[e-1]]--;
				dfs(C2[e-1]);
			}
			return;
		}
	}
	
	vector <int> Distribute(vector <int> choice1, vector <int> choice2) {
		C1=choice1;
		C2=choice2;
		
		N=choice1.size();
		int i,x,y,j;
		
		ZERO(edge);
		FOR(x,50) E[x]=queue<int>();
		
		V=vector<int>(N,0);
		
		FOR(i,N) {
			E[C1[i]].push(i+1);
			E[C2[i]].push(-(i+1));
			edge[C1[i]]++;
			edge[C2[i]]++;
		}
		
		FOR(i,50) if(edge[i]%2) dfs(i);
		FOR(i,50) if(edge[i]) dfs(i);
		
		return V;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {10, 20, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20, 30, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 2, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, Distribute(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, Distribute(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 1, 2, 3, 5, 6, 7, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8, 7, 6, 5, 3, 2, 1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 2, 2, 2, 2, 2, 2, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, Distribute(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {49, 0, 48, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 4, 5, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 2, 2, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, Distribute(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {21,4,14,0,31,46,1,34,2,3,27,19,47,46,17,11,41,12,31,0,34,18,8,14,23,40,0,18,48,35,42,24,25,32,25,44,17,6,44,34,12,39,43,39,26,
34,10,6,13,2,40,15,16,32,32,29,1,23,8,10,49,22,10,15,40,20,0,30,1,43,33,42,28,39,28,4,38,11,5,1,47,12,0,22,20,33,33,34,18,8,23,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {25,5,39,20,44,47,11,49,42,17,25,15,23,11,32,17,24,4,11,47,27,41,40,0,49,27,5,28,6,11,18,0,17,1,0,32,45,28,17,5,13,40,40,25,33,
7,8,32,12,0,39,30,8,39,23,9,8,34,34,37,5,1,24,23,0,29,11,42,29,40,24,18,37,1,21,0,31,47,23,33,45,48,31,11,40,45,24,22,19,26,37,39}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 1, 2, 1, 2, 1, 1, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 1, 1, 2, 2, 1, 2, 1, 2, 1, 1, 2, 2, 1, 1, 2, 1, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 1, 1, 2, 2, 1, 1, 1, 2, 2, 1, 2, 1, 2, 2, 2, 1, 2, 2, 1, 2, 1, 2, 2, 1, 2, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, Distribute(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PieOrDolphin ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

