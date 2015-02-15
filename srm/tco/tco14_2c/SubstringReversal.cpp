#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

typedef signed long long ll;

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)

class SubstringReversal {
	public:
	int L;
	
	int test(string S) {
		int L=S.size();
		int ret=0,i,j;
		string T=S;
		
		for(i=1;i<L;i++) {
			string T2=S;
			FOR(j,i+1) T2[j]=S[i-j];
			if(T2<T) ret=i,T=T2;
			
		}
		return ret;
	}
	
	vector <int> solve(string S) {
		L=S.size();
		int x,y,r;
		FOR(x,L) {
			for(y=x+1;y<L;y++) {
				if(S[x]>S[y]) {
					vector<int> V;
					r = test(S.substr(x));
					V.push_back(x);
					V.push_back(x+r);
					return V;
				}
			}
		}
		vector<int> V;
		V.push_back(0);
		V.push_back(0);
		return V;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "abdc"; int Arr1[] = {2, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { string Arg0 = "aabbcc"; int Arr1[] = {0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { string Arg0 = "misof"; int Arr1[] = {0, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { string Arg0 = "ivan"; int Arr1[] = {0, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, solve(Arg0)); }
	void test_case_4() { string Arg0 = "thisseemstobeaneasyproblem"; int Arr1[] = {0, 13 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, solve(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE 
int main(int argc,char** argv) {
  SubstringReversal ___test;
  if(argc==1)  ___test.run_test(-1);
  else  ___test.run_test(atoi(argv[1]));
}
