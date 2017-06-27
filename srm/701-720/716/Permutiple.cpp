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

class Permutiple {
	public:
	string val(int v) {
		string S;
		while(v) {
			S+='0'+v%10;
			v/=10;
		}
		sort(ALL(S));
		return S;
	}
	string isPossible(int x) {
		string S=val(x);
		
		for(int a=2*x;a<=1000000;a+=x) {
			if(val(a)==S) return "Possible";
		}
		return "Impossible";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 142857; string Arg1 = "Possible"; verify_case(0, Arg1, isPossible(Arg0)); }
	void test_case_1() { int Arg0 = 14; string Arg1 = "Impossible"; verify_case(1, Arg1, isPossible(Arg0)); }
	void test_case_2() { int Arg0 = 1035; string Arg1 = "Possible"; verify_case(2, Arg1, isPossible(Arg0)); }
	void test_case_3() { int Arg0 = 1000000; string Arg1 = "Impossible"; verify_case(3, Arg1, isPossible(Arg0)); }
	void test_case_4() { int Arg0 = 100035; string Arg1 = "Possible"; verify_case(4, Arg1, isPossible(Arg0)); }
	void test_case_5() { int Arg0 = 4; string Arg1 = "Impossible"; verify_case(5, Arg1, isPossible(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Permutiple ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

