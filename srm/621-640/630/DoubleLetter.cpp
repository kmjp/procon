#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define ZERO(a) memset(a,0,sizeof(a))

//-------------------------------------------------------

class DoubleLetter {
	public:
	string ableToSolve(string S) {
		while(S.size()) {
			int i;
			FOR(i,S.size()-1) if(S[i]==S[i+1]) break;
			if(i==S.size()-1) return "Impossible";
			S=S.substr(0,i)+S.substr(i+2);
		}
		return "Possible";
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aabccb"; string Arg1 = "Possible"; verify_case(0, Arg1, ableToSolve(Arg0)); }
	void test_case_1() { string Arg0 = "aabccbb"; string Arg1 = "Impossible"; verify_case(1, Arg1, ableToSolve(Arg0)); }
	void test_case_2() { string Arg0 = "abcddcba"; string Arg1 = "Possible"; verify_case(2, Arg1, ableToSolve(Arg0)); }
	void test_case_3() { string Arg0 = "abab"; string Arg1 = "Impossible"; verify_case(3, Arg1, ableToSolve(Arg0)); }
	void test_case_4() { string Arg0 = "aaaaaaaaaa"; string Arg1 = "Possible"; verify_case(4, Arg1, ableToSolve(Arg0)); }
	void test_case_5() { string Arg0 = "aababbabbaba"; string Arg1 = "Impossible"; verify_case(5, Arg1, ableToSolve(Arg0)); }
	void test_case_6() { string Arg0 = "zzxzxxzxxzzx"; string Arg1 = "Possible"; verify_case(6, Arg1, ableToSolve(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DoubleLetter ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

