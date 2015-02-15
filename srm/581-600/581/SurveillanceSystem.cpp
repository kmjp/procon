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


class SurveillanceSystem {
	int MM[101];
	set<ll> OK;
	int R,C;
	int N[50],NT[50];
	public:
	
	string getContainerInfo(string containers, vector <int> reports, int L) {
		int i,x,y,j;
		
		R=reports.size();
		C=containers.size();
		ZERO(MM);
		MM[100]=R;
		FOR(i,R) MM[reports[i]]++;
		
		ZERO(N);
		ll orm=0,andm=0;
		FOR(i,C-L+1) {
			FOR(j,L) if(containers[i+j]=='X') N[i]++;
			if(MM[N[i]]) orm |= ((1LL<<L)-1)<<i;
		}
		
		FOR(i,L+1) {
			if(MM[i]==0) continue;
			int num[51];
			int t=0;
			ZERO(num);
			FOR(x,C-L+1) if(N[x]==i) {
				FOR(y,L) num[x+y]++;
				t++;
			}
			
			FOR(x,C) if(num[x]>t-MM[i]) andm|=1LL<<x;
		}
		
		string res;
		FOR(i,C) {
			if(andm & (1LL<<i)) res+="+";
			else if(orm & (1LL<<i)) res+="?";
			else res+="-";
		}
		
		
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "-X--XX"; int Arr1[] = {1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "??++++"; verify_case(0, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "-XXXXX-"; int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "???-???"; verify_case(1, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "------X-XX-"; int Arr1[] = {3, 0, 2, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; string Arg3 = "++++++++++?"; verify_case(2, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "-XXXXX---X--"; int Arr1[] = {2, 1, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "???-??++++??"; verify_case(3, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "X--X-XX--X--XX-X-X---X--XX--XX-X-XX--X--X-XX--X-X"; int Arr1[] = {5, 4, 4, 5, 3, 4, 4, 4, 5, 5, 3, 4, 4, 5, 4, 4, 5, 4, 5, 4, 5, 4, 4, 4, 4, 3, 4, 4, 5, 4, 3, 4, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; string Arg3 = "??????+++++++++++++++++++++++++++++++++++++??????"; verify_case(4, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_42() { string Arg0 = "-XX--X-XX-X-X--X---XX-X---XXXX-----X"; int Arr1[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; string Arg3 = "???++++?++++++++++++++++++++??????--"; verify_case(4, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  SurveillanceSystem ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
