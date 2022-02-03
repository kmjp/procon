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

class OxToTiger {
	public:
	string rewrite(string message) {
		string s=" "+message+" ";
		while(1) {
			int x=s.find(" ox ");
			if(x==string::npos) break;
			s=s.substr(0,x)+" tiger "+s.substr(x+4);
		}
		return s.substr(1,s.size()-2);
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ox"; string Arg1 = "tiger"; verify_case(0, Arg1, rewrite(Arg0)); }
	void test_case_1() { string Arg0 = "fox"; string Arg1 = "fox"; verify_case(1, Arg1, rewrite(Arg0)); }
	void test_case_2() { string Arg0 = " ox  "; string Arg1 = " tiger  "; verify_case(2, Arg1, rewrite(Arg0)); }
	void test_case_3() { string Arg0 = "the ox the ox the ox and the fox in the box"; string Arg1 = "the tiger the tiger the tiger and the fox in the box"; verify_case(3, Arg1, rewrite(Arg0)); }
	void test_case_4() { string Arg0 = "the plural of ox is oxen"; string Arg1 = "the plural of tiger is oxen"; verify_case(4, Arg1, rewrite(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  OxToTiger ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

