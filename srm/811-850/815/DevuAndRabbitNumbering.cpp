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

class DevuAndRabbitNumbering {
	public:
	string canRenumber(vector <int> rabbitIds) {
		sort(ALL(rabbitIds));
		int pre=-100;
		FORR(a,rabbitIds) {
			if(pre<a-1) a=a-1;
			else if(pre<a) a=a;
			else if(pre<a+1) a=a+1;
			else return "cannot";
			pre=a;
		}
		return "can";
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "can"; verify_case(0, Arg1, canRenumber(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "can"; verify_case(1, Arg1, canRenumber(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 4, 2, 2, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "cannot"; verify_case(2, Arg1, canRenumber(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 2, 4, 2, 6, 6, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "can"; verify_case(3, Arg1, canRenumber(Arg0)); }
	void test_case_4() { int Arr0[] = {960,578,296,414,352,610,872,556,113,818,194,804,141,859,761,887,3,952,234,667,196,693,783}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "can"; verify_case(4, Arg1, canRenumber(Arg0)); }
	void test_case_5() { int Arr0[] = {97, 64, 22, 17, 75, 97, 85, 68, 35, 82, 64, 10, 71, 11,
 64, 64, 94, 52, 28, 40, 48, 46,  5, 82, 39, 65,  2, 93,
 43, 50, 44, 90, 69, 72, 94,  6, 62, 17, 12, 12, 84, 33, 38}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "cannot"; verify_case(5, Arg1, canRenumber(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DevuAndRabbitNumbering ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

