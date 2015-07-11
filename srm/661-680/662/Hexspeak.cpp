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

class Hexspeak {
	public:
	string decode(long long ciphertext) {
		string S;
		while(ciphertext) {
			int i=ciphertext%16;
			ciphertext/=16;
			if(i==0) S='O'+S;
			else if(i==1) S='I'+S;
			else if(i==10) S='A'+S;
			else if(i==11) S='B'+S;
			else if(i==12) S='C'+S;
			else if(i==13) S='D'+S;
			else if(i==14) S='E'+S;
			else if(i==15) S='F'+S;
			else return "Error!";
		}
		return S;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 257LL; string Arg1 = "IOI"; verify_case(0, Arg1, decode(Arg0)); }
	void test_case_1() { long long Arg0 = 258LL; string Arg1 = "Error!"; verify_case(1, Arg1, decode(Arg0)); }
	void test_case_2() { long long Arg0 = 3405691582LL; string Arg1 = "CAFEBABE"; verify_case(2, Arg1, decode(Arg0)); }
	void test_case_3() { long long Arg0 = 2882400001LL; string Arg1 = "ABCDEFOI"; verify_case(3, Arg1, decode(Arg0)); }
	void test_case_4() { long long Arg0 = 999994830345994239LL; string Arg1 = "DEOBIFFFFFFFFFF"; verify_case(4, Arg1, decode(Arg0)); }
	void test_case_5() { long long Arg0 = 1000000000000000000LL; string Arg1 = "Error!"; verify_case(5, Arg1, decode(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Hexspeak ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
