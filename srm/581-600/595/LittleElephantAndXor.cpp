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

class LittleElephantAndXor {
	public:
	
	long long getNumber(int A, int B, int C) {
		ll ret=0;
		int la,lb,lc,i;
		
		for(i=29;i>=0;i--) {
			if(A<B) swap(A,B);
			la=A&(1<<i),lb=B&(1<<i),lc=C&(1<<i);
			A-=la; B-=lb; C-=lc;
			
			if(lc) {
				if(lb) {
					ret += (1LL<<(2*i)); // la==0 && lb==0
					ret += (B+1)*(ll)(C+1); // la==0 && lb==1 
					ret += (A+1)*(ll)(C+1); // la==1 && lb==0 
					ret += (A+1)*(ll)(B+1); // la==1 && lb==1 
					return ret;
				}
				else if(la) {
					ret += (1LL<<i)*(ll)(B+1); // la==0 && lb==0
					// la==1 && lb==0
				}
				else {
					ret += (A+1)*(ll)(B+1); // la==0 && lb==0
					return ret;
				}
			}
			else {
				if(lb) {
					ret += (1LL<<i)*(C+1); //la==0 && lb==0
					//la==1 && lb==1
				}
				else if(la) {
					ret += (B+1)*(ll)(C+1); //la==0 && lb==0
					return ret;
				}
			}
		}
		return ret + 1;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; long long Arg3 = 5LL; verify_case(0, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 7; int Arg2 = 3; long long Arg3 = 20LL; verify_case(1, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 5; long long Arg3 = 57LL; verify_case(2, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 774; int Arg1 = 477; int Arg2 = 447; long long Arg3 = 214144LL; verify_case(3, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	//void test_case_4() { int Arg0 = 1000000000; int Arg1 = 1000000000; int Arg2 = 500000000; long long Arg3 = 468566946385621507LL; verify_case(4, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 344606619; int Arg1 = 496378830; int Arg2 = 135984077; long long Arg3 = 46861013493396360LL; verify_case(4, Arg3, getNumber(Arg0, Arg1, Arg2)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LittleElephantAndXor ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

