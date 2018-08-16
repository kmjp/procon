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

class Reroll {
	public:
	int minimumDice(int target, vector <int> dice) {
		int sum=0,i;
		sort(ALL(dice));
		FORR(c,dice) sum+=c;
		if(sum==target) return 0;
		if(sum>target) {
			int ret=0;
			for(i=dice.size()-1;i>=0;i--) {
				if(sum>target) {
					ret++;
					sum-=dice[i]-1;
				}
			}
			return ret;
		}
		else {
			int ret=0;
			FOR(i,dice.size()) {
				if(sum<target) {
					ret++;
					sum+=6-dice[i];
				}
			}
			return ret;
		}
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arr1[] = {2,6,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, minimumDice(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arr1[] = {4,2,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, minimumDice(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 42; int Arr1[] = {6,6,6,6,6,6,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, minimumDice(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 42; int Arr1[] = {1,3,5,3,6,4,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(3, Arg2, minimumDice(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Reroll ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

