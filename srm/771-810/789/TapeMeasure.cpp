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

class TapeMeasure {
	public:
	vector <string> draw(int leftMark, int rightMark) {
		
		string S[5];
		int i,j;
		FOR(i,2010) S[0]+="#";
		FOR(i,1010) S[1]+="# ";
		FOR(i,1010) S[2]+="#         ";
		FOR(i,1010) S[3]+="#                   ";
		FOR(i,1010) S[4]+="                    ";
		for(i=0;i<=990;i+=10) {
			string T=to_string(i);
			FOR(j,T.size()) S[4][i*2+j]=T[j];
		}
		
		vector<string> R;
		FOR(i,5) R.push_back(S[i].substr(leftMark*2,(rightMark-leftMark)*2+1));
		return R;
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 25; string Arr2[] = {"###################################################", "# # # # # # # # # # # # # # # # # # # # # # # # # #", "#         #         #         #         #         #", "#                   #                   #          ", "0                   10                  20         " }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, draw(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 981; int Arg1 = 990; string Arr2[] = {"###################", "# # # # # # # # # #", "        #         #", "                  #", "0                 9" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, draw(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 20; int Arg1 = 20; string Arr2[] = {"#", "#", "#", "#", "2" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, draw(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 31; int Arg1 = 38; string Arr2[] = {"###############", "# # # # # # # #", "        #      ", "               ", "               " }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, draw(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TapeMeasure ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

