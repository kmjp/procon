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

class Sherlock {
	public:
	string isItHim(string firstName, string lastName) {
		string OK="It is him";
		string NG="It is someone else";
		
		if(firstName.size()<7 || lastName.size()<7) return NG;
		if(firstName[0]!='B' || lastName[0]!='C') return NG;
		int num=0;
		FORR(c,firstName) {
			FORR(d,"BENEDICT") {
				if(c==d) {
					num++;
					break;
				}
			}
		}
		if(num<3) return NG;
		num=0;
		FORR(c,lastName) {
			FORR(d,"CUMBERBATCH") {
				if(c==d) {
					num++;
					break;
				}
			}
		}
		if(num<5) return NG;
		return OK;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BENEDICT"; string Arg1 = "CUMBERBATCH"; string Arg2 = "It is him"; verify_case(0, Arg2, isItHim(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "BENADRYL"; string Arg1 = "CUCUMBERPATCH"; string Arg2 = "It is him"; verify_case(1, Arg2, isItHim(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "HARSHIT"; string Arg1 = "MEHTA"; string Arg2 = "It is someone else"; verify_case(2, Arg2, isItHim(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "BATAXXAT"; string Arg1 = "CURMUDGEON"; string Arg2 = "It is him"; verify_case(3, Arg2, isItHim(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "BENEDI"; string Arg1 = "CUMBER"; string Arg2 = "It is someone else"; verify_case(4, Arg2, isItHim(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "BAXAXAXY"; string Arg1 = "CENTRIFUGAL"; string Arg2 = "It is someone else"; verify_case(5, Arg2, isItHim(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "BUMBLESHACK"; string Arg1 = "CRUMPLEHORN"; string Arg2 = "It is him"; verify_case(6, Arg2, isItHim(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Sherlock ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

