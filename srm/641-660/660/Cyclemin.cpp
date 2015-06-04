#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class Cyclemin {
	public:
	string bestmod(string s, int k) {
		string r=s;
		int i,j,k2;
		FOR(i,s.size()) {
			string t=s.substr(i)+s.substr(0,i);
			k2=k;
			FOR(j,t.size()) if(t[j]!='a' && k2) k2--, t[j]='a';
			r=min(r,t);
		}
		return r;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aba"; int Arg1 = 1; string Arg2 = "aaa"; verify_case(0, Arg2, bestmod(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "aba"; int Arg1 = 0; string Arg2 = "aab"; verify_case(1, Arg2, bestmod(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "bbb"; int Arg1 = 2; string Arg2 = "aab"; verify_case(2, Arg2, bestmod(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "sgsgaw"; int Arg1 = 1; string Arg2 = "aasgsg"; verify_case(3, Arg2, bestmod(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "abacaba"; int Arg1 = 1; string Arg2 = "aaaabac"; verify_case(4, Arg2, bestmod(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "isgbiao"; int Arg1 = 2; string Arg2 = "aaaisgb"; verify_case(5, Arg2, bestmod(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Cyclemin ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
