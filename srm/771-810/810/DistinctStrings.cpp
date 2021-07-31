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

class DistinctStrings {
	public:
	vector <string> generate(int L, string letters, int N) {
		vector<string> V;
		int i;
		FOR(i,N) {
			string A;
			A+=letters[i/100];
			A+=letters[i/10%10];
			A+=letters[i%10];
			while(A.size()<L) A.push_back(letters[0]);
			V.push_back(A);
		}
		return V;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 5; string Arg1 = "qwertyuiopasdfghjklzxcvbnm"; int Arg2 = 10; string Arr3[] = {"hello", "abcde", "wwwww", "coins", "coder", "digit", "clash", "qwert", "puppy", "kitty" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, generate(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; string Arg1 = "ABCDE02468"; int Arg2 = 17; string Arr3[] = {"ABC", "D2E", "DDD", "AAA", "EEE", "024", "042", "204", "240", "402", "420", "4AB", "4EE", "E4E", "ED4", "868", "844" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, generate(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 8; string Arg1 = "cdeopPrRtT"; int Arg2 = 4; string Arr3[] = {"topcoder", "Topcoder", "docopTer", "receptor" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, generate(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DistinctStrings ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

