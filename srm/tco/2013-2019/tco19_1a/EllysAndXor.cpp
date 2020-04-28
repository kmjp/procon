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

class EllysAndXor {
	public:
	int getMax(vector <int> numbers) {
		int ma=0;
		int N=numbers.size();
		int mask;
		int i;
		FOR(mask,1<<(N-1)) {
			int cur=numbers[0];
			FOR(i,N-1) {
				if(mask&(1<<i)) {
					cur^=numbers[i+1];
				}
				else {
					cur&=numbers[i+1];
				}
			}
			ma=max(ma,cur);
		}
		return ma;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {42, 27, 38}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 44; verify_case(0, Arg1, getMax(Arg0)); }
	void test_case_1() { int Arr0[] = {666, 133, 438, 123, 893, 674, 462, 209}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 976; verify_case(1, Arg1, getMax(Arg0)); }
	void test_case_2() { int Arr0[] = {42}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 42; verify_case(2, Arg1, getMax(Arg0)); }
	void test_case_3() { int Arr0[] = {123, 456, 789, 987, 654, 321}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 975; verify_case(3, Arg1, getMax(Arg0)); }
	void test_case_4() { int Arr0[] = {42, 13, 17, 666, 811, 314, 1, 5, 2, 1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1007; verify_case(4, Arg1, getMax(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysAndXor ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

