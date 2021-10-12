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

class SunShroom {
	public:
	long long produceSun(vector<long long> plantingTime, long long queryTime) {
		ll ret=0;
		FORR(a,plantingTime) if(a<=queryTime) {
			a=(queryTime-a)/24;
			if(a<5) ret+=a*15;
			else ret+=a*25-40;
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long Arr0[] = {10}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 33LL; long long Arg2 = 0LL; verify_case(0, Arg2, produceSun(Arg0, Arg1)); }
	void test_case_1() { long Arr0[] = {10}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 34LL; long long Arg2 = 15LL; verify_case(1, Arg2, produceSun(Arg0, Arg1)); }
	void test_case_2() { long Arr0[] = {47}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 200LL; long long Arg2 = 110LL; verify_case(2, Arg2, produceSun(Arg0, Arg1)); }
	void test_case_3() { long Arr0[] = {47, 47, 47, 47, 47, 47}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 200LL; long long Arg2 = 660LL; verify_case(3, Arg2, produceSun(Arg0, Arg1)); }
	void test_case_4() { long Arr0[] = {10, 100, 20, 200, 30, 300, 40, 400}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 123456LL; long long Arg2 = 1027230LL; verify_case(4, Arg2, produceSun(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SunShroom ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

