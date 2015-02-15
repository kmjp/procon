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

typedef signed long long s64;
typedef unsigned long long u64;

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


class TheBrickTowerMediumDivTwo {
	public:
	vector<int> opt;
	vector<int> rest;
	vector <int> h;
	vector<int> index;
	int N;
	int l[100];
	
	int len() {
		
		int i;
		FOR(i,N) l[i]=0;
		
		int d;
		for(d=1;d<N;d++) {
			for(i=0;i<d;i++) {
				int dist = max(h[index[i]],h[index[d]]);
				if(l[d]-l[i] < dist) l[d] = l[i]+dist;
			}
		}
		return l[N-1];
		
	}
	
	vector <int> find(vector <int> heights) {
		int i,minc;
		h = heights;
		
		N=heights.size();
		index.clear();
		FOR(i,N) index.push_back(i);
		opt = index;
		minc=10000000;
		
		do {
			int c;
			
			c = len();
			if(c<minc) {
				minc = c;
				opt = index;
			}
			else if(c==minc) {
				int le=1;
				FOR(i,N) {
					if(index[i] < opt[i]){ le=1; break;}
					if(index[i] > opt[i]){ le=0; break;}
				}
				if(le) {
					opt = index;
				}
			}
			
		} while(next_permutation(index.begin(),index.end()));
		
		
		
		
		return opt;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {4, 7, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 2, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { int Arr0[] = {4, 4, 4, 4, 4, 4, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 3, 4, 5, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 3, 3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 3, 1, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { int Arr0[] = {13, 32, 38, 25, 43, 47, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 6, 3, 1, 2, 4, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  TheBrickTowerMediumDivTwo ___test;
  ___test.run_test(-1);
}
// END CUT HERE
