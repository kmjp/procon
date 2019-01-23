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

class FindStringEasy {
	public:
	string withPalindromicSubstrings(int n) {
		for(int a1=0;a1<=100;a1++) {
			for(int b1=0;a1+b1<=100;b1++) {
				int v=a1*(a1+1)/2+b1*(b1+1)/2;
				string S=string(a1,'a')+string(b1,'b');
				if(v==n) return S;
				if(a1==0 || b1==0) continue;
				for(int a2=1;a1+a2+b1<=100;a2++) {
					for(int b2=0;a1+a2+b1+b2<=100;b2++) {
						int v=(a1*(a1+1)+b1*(b1+1)+a2*(a2+1)+b2*(b2+1))/2+min(a1,a2)+min(b1,b2);
						if(v==n) {
							return S+string(a2,'a')+string(b2,'b');
						}
						
					}
				}
				
				
			}
		}
		return "";
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; string Arg1 = "aa"; verify_case(0, Arg1, withPalindromicSubstrings(Arg0)); }
	void test_case_1() { int Arg0 = 9; string Arg1 = "aaaba"; verify_case(1, Arg1, withPalindromicSubstrings(Arg0)); }
	void test_case_2() { int Arg0 = 12; string Arg1 = "aabbaba"; verify_case(2, Arg1, withPalindromicSubstrings(Arg0)); }
	void test_case_3() { int Arg0 = 20; string Arg1 = "bbbaabbaba"; verify_case(3, Arg1, withPalindromicSubstrings(Arg0)); }
	void test_case_4() { int Arg0 = 140; string Arg1 = "bbaababaabaabbbabbbabbbaabaaaabbbaabbabbabababbbaaa"; verify_case(4, Arg1, withPalindromicSubstrings(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FindStringEasy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

