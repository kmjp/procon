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

class FoxPlusMinus {
	public:
	vector <int> maximize(vector <int> first, int N) {
		int K=first.size();
		int i,j,k,x;
		
		sort(first.begin(),first.end());
		if(N<K) {
			rotate(first.begin()+N,first.begin()+(K-1),first.end());
		}
		else if(K%2==0) {
			vector<int> V;
			V.resize(K);
			
			if(N>=K*2) {
				
				FOR(i,K/2) V[i*2] = first[K/2+i];
				FOR(i,K/2) V[i*2+1] = first[K/2-1-i];
				if(N%2) FOR(i,K/2) swap(V[i*2],V[i*2+1]);
			}
			else {
				vector<pair<int,int> > PP;
				FOR(i,K) {
					vector<int> T;
					FOR(j,K) T.push_back(j==i);
					FOR(j,K+5) {
						x=0;
						FOR(k,K) x += T[T.size()-(1+k)]*((k%2)?1:-1);
						T.push_back(x);
					}
					PP.push_back(make_pair(T[N],i));
				}
				sort(PP.begin(),PP.end());
				FOR(i,K) V[PP[i].second] = first[i];
			}
			return V;
		}
		else {
			N%=K+1;
			if(N==K) {
				vector<int> V;
				V.resize(K);
				FOR(i,K/2+1) V[i*2] = first[K/2+i];
				FOR(i,K/2) V[i*2+1] = first[i];
				return V;
			}
			else {
				rotate(first.begin()+N+1,first.end(),first.begin()+(K-1));
			}
		}
		
		return first;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arr2[] = {2, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, maximize(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arr2[] = {2, 1, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, maximize(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-3, 1, -4, 1, -5, 9, -2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arr2[] = {-5, -4, 9, -3, -2, 1, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, maximize(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2, 7, -1, 8, -2, -8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arr2[] = {2, -1, 7, -2, 8, -8 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, maximize(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {-10, -20, -30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arr2[] = {-30, -10, -20 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, maximize(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1, 2, 4, 9, 7, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; int Arr2[] = {3, 4, 2, 7, 1, 9 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, maximize(Arg0, Arg1)); }
	void test_case_62() { int Arr0[] = {-4112039, 51143992, 941422315, -153492958, 499218832, 543599293, 132059490, -434243951,
 -95819234, 1552938, -857192847, 481950390, 401099286, 71482395, -711450593, 8101919}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 884142312; int Arr2[] = {51143992, 8101919, 71482395, 1552938, 132059490, -4112039, 401099286, -95819234, 481950390, -153492958, 499218832, -434243951, 543599293, -711450593, 941422315, -857192847 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(6, Arg2, maximize(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {-85011351, -449199160, 71067748, -336872845, -514031506, -285563651, 744468269, 143528621, -305704679, -356547484, -632580247, -421532563, 970218247, -705971124, -941316368, -410495811, -403076070, 495859705, -561693491, 313372025, 121910835, 419391647, -141300061, 219241998, 800502275, 655172486, 65066915, -760182575, -799044917, -113523537, 909440605, -795745856, -997088698, 424864834, -829422038, 923878585, -446495489, 422897699, -484452221, 456076113, -232389510, 943539384, -280277473, 861873476, 158284490, -897769811}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 54; int Arr2[] = {-141300061, -232389510, -113523537, -280277473, -85011351, -285563651, 65066915, -305704679, 71067748, -997088698, 121910835, -941316368, 143528621, -897769811, 158284490, -829422038, 219241998, -799044917, 313372025, -795745856, 419391647, -760182575, 422897699, -705971124, 424864834, -632580247, 456076113, -561693491, 495859705, -514031506, 655172486, -484452221, 744468269, -449199160, 800502275, -446495489, 861873476, -421532563, 909440605, -410495811, 923878585, -403076070, 943539384, -356547484, 970218247, -336872845}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(6, Arg2, maximize(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FoxPlusMinus ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

