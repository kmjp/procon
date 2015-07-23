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

class ABBA {
	public:
	string canObtain(string initial, string target) {
		set<string> S[1010];
		
		S[target.size()].insert(target);
		for(int i=target.size();i>initial.size();i--) {
			FORR(r,S[i]) {
				if(r[i-1]=='A') S[i-1].insert(r.substr(0,i-1));
				if(r[i-1]=='B') {
					string a=r.substr(0,i-1);
					reverse(a.begin(),a.end());
					S[i-1].insert(a);
				}
			}
		}
		if(S[initial.size()].count(initial)) return "Possible";
		return "Impossible";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "B"; string Arg1 = "ABBA"; string Arg2 = "Possible"; verify_case(0, Arg2, canObtain(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "AB"; string Arg1 = "ABB"; string Arg2 = "Impossible"; verify_case(1, Arg2, canObtain(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "BBAB"; string Arg1 = "ABABABABB"; string Arg2 = "Impossible"; verify_case(2, Arg2, canObtain(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "BBBBABABBBBBBA"; string Arg1 = "BBBBABABBABBBBBBABABBBBBBBBABAABBBAA"; string Arg2 = "Possible"; verify_case(3, Arg2, canObtain(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "A"; string Arg1 = "BB"; string Arg2 = "Impossible"; verify_case(4, Arg2, canObtain(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ABBA ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
