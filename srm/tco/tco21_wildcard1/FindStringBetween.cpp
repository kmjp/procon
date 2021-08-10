#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

class FindStringBetween {
	public:
	string generate(int L, string A, string B) {
		if(B<=A) {
			return "ERROR";
		}
		if(A.size()<L) {
			A+="a";
		}
		else {
			int i;
			for(i=A.size()-1;i>=0;i--) {
				if(A[i]=='z') {
					A.pop_back();
				}
				else {
					A[i]++;
					break;
				}
			}
		}
		if(B<=A) {
			return "ERROR";
		}
		return A;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; string Arg1 = "cat"; string Arg2 = "elephant"; string Arg3 = "dog"; verify_case(0, Arg3, generate(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; string Arg1 = "buzz"; string Arg2 = "byte"; string Arg3 = "bye"; verify_case(1, Arg3, generate(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 7; string Arg1 = "buzz"; string Arg2 = "byte"; string Arg3 = "buzzard"; verify_case(2, Arg3, generate(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; string Arg1 = "pier"; string Arg2 = "pies"; string Arg3 = "ERROR"; verify_case(3, Arg3, generate(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 9; string Arg1 = "later"; string Arg2 = "earlier"; string Arg3 = "ERROR"; verify_case(4, Arg3, generate(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FindStringBetween ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

