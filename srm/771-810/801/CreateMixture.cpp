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
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

class CreateMixture {
	public:
	vector <int> mix(int concentration) {
		int a=concentration/100;
		int b=a+1;
		int i;
		vector<int> R;
		FOR(i,10) R.push_back(i<a);
		FOR(i,10) R.push_back(i<b);
		concentration%=100;
		a=concentration/10;
		b=a+1;
		FOR(i,10) R.push_back(2+(i<a));
		FOR(i,10) R.push_back(2+(i<b));
		concentration%=10;
		a=concentration;
		b=a+1;
		FOR(i,10) R.push_back(4+(i<a));
		FOR(i,10) R.push_back(4+(i<b));
		return R;
		
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 500; int Arr1[] = {0, 1, -1, 1, -1, 0, -1, -1, -1, -1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, mix(Arg0)); }
	void test_case_1() { int Arg0 = 250; int Arr1[] = {0, 1, -1, 1, -1, 0, -1, -1, -1, -1, 2, 0, -1, -1, -1, -1, -1, -1, -1, -1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, mix(Arg0)); }
	void test_case_2() { int Arg0 = 0; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, mix(Arg0)); }
	void test_case_3() { int Arg0 = 400; int Arr1[] = {0, 1, -1, 1, -1, 0, -1, -1, -1, -1, 0, 0, 1, 2, 2, -1, -1, -1, -1, -1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, mix(Arg0)); }
	void test_case_4() { int Arg0 = 2; int Arr1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 3, -1, -1, -1, -1, -1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, mix(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CreateMixture ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

