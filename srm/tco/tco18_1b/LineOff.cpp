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

class LineOff {
	public:
	int movesToDo(string points) {
		vector<char> V;
		int ret=0;
		FORR(c,points) {
			if(V.size() && V.back()==c) {
				ret++;
				V.pop_back();
			}
			else {
				V.push_back(c);
			}
			
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "abba"; int Arg1 = 2; verify_case(0, Arg1, movesToDo(Arg0)); }
	void test_case_1() { string Arg0 = "zwwwzffw"; int Arg1 = 2; verify_case(1, Arg1, movesToDo(Arg0)); }
	void test_case_2() { string Arg0 = "rrrrrrr"; int Arg1 = 3; verify_case(2, Arg1, movesToDo(Arg0)); }
	void test_case_3() { string Arg0 = "dfghj"; int Arg1 = 0; verify_case(3, Arg1, movesToDo(Arg0)); }
	void test_case_4() { string Arg0 = "wasitacarooracatisaw"; int Arg1 = 10; verify_case(4, Arg1, movesToDo(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LineOff ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

