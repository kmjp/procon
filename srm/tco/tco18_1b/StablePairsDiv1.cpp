#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class StablePairsDiv1 {
	public:
	vector <int> findMaxStablePairs(int n, int c, int k) {
		vector<int> R,NG;
		
		R.push_back(n);
		R.push_back(n-1);
		
		int i;
		FOR(i,k-1) {
			if(c%2==0) {
				R.push_back(R[R.size()-2]-c/2);
				R.push_back(R[R.size()-2]-c/2);
			}
			else {
				if(i%2==0) {
					R.push_back(R[R.size()-2]-c/2);
					R.push_back(R[R.size()-2]-c/2-1);
				}
				else {
					R.push_back(R[R.size()-2]-c/2-1);
					R.push_back(R[R.size()-2]-c/2);
				}
			}
		}
		reverse(ALL(R));
		set<int> S;
		FORR(c,R) {
			if(c<1 || c>n) return NG;
			if(S.count(c)) return NG;
			S.insert(c);
		}
		
		return R;
		
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 4; int Arg2 = 2; int Arr3[] = {2, 3, 4, 5 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, findMaxStablePairs(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 2; int Arr3[] = {1, 2, 3, 4 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, findMaxStablePairs(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 100; int Arg2 = 1; int Arr3[] = { }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, findMaxStablePairs(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 100; int Arg2 = 1; int Arr3[] = {2, 3 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, findMaxStablePairs(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 6; int Arg2 = 3; int Arr3[] = {2, 5, 6, 7, 9, 10 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, findMaxStablePairs(Arg0, Arg1, Arg2)); }
//	void test_case_5() { int Arg0 = 12; int Arg1 = 7; int Arg2 = 3; int Arr3[] = {4, 5, 6, 10, 11, 12 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(5, Arg3, findMaxStablePairs(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 73; int Arg1 = 5; int Arg2 = 15; int Arr3[] = {4, 5, 6, 10, 11, 12 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(5, Arg3, findMaxStablePairs(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  StablePairsDiv1 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

