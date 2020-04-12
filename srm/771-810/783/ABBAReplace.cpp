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

class ABBAReplace {
	public:
	int countSteps(string S, int N, int seed, int threshold) {
		ll state=seed;
		while(S.size()<N) {
			state = (state * 1103515245 + 12345) % (1LL<<31);
			if(state<threshold) S+='A';
			else S+='B';
		}
		vector<int> num;
		num.push_back(0);
		FORR(c,S) {
			if(c=='A') num.back()++;
			else num.push_back(0);
		}
		num.pop_back();
		int i;
		for(i=num.size()-1;i>=1;i--) {
			if(num[i]>1) {
				num[i-1]+=num[i]-1;
				num[i]=1;
			}
		}
		reverse(ALL(num));
		while(num.size()&&num.back()==0) num.pop_back();
		if(num.empty()) return 0;
		return num.size()+num.back()-1;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AABABB"; int Arg1 = 6; int Arg2 = 0; int Arg3 = 0; int Arg4 = 4; verify_case(0, Arg4, countSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arg0 = ""; int Arg1 = 0; int Arg2 = 4; int Arg3 = 7; int Arg4 = 0; verify_case(1, Arg4, countSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arg0 = "ABBABAABABBBABBBB"; int Arg1 = 17; int Arg2 = 0; int Arg3 = 0; int Arg4 = 11; verify_case(2, Arg4, countSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arg0 = "AABAA"; int Arg1 = 17; int Arg2 = 47474747; int Arg3 = 1000000000; int Arg4 = 10; verify_case(3, Arg4, countSteps(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ABBAReplace ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

