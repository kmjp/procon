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

class OrthogonalProjections {
	public:
	vector <int> generate(int n) {
		
		if(n==1) return {0,0};
		if(n==2) return {0,0,0,1};
		if(n==6) return {0,0,0,1,1,2};
		if(n%2 || n==4) return {};
		int i,v=1;
		n=n/2-1;
		while(v*v<n) v++;
		vector<int> R;
		FOR(i,v) R.push_back(0),R.push_back(i);
		n-=2*v-1;
		R.push_back(1);
		R.push_back(0);
		int pre=0;
		FOR(i,v-1) {
			int x=min(n,v-1);
			pre+=x+1;
			n-=x;
			R.push_back(1);
			R.push_back(pre);
		}
		return R;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 6; int Arr1[] = {0, 0, 0, 1, 1, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, generate(Arg0)); }
	void test_case_1() { int Arg0 = 47; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, generate(Arg0)); }
	void test_case_2() { int Arg0 = 8; int Arr1[] = {0, 0, 0, 2, 7, 1, 14, 0, 14, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, generate(Arg0)); }
	void test_case_3() { int Arg0 = 100; int Arr1[] = {70, 30, 16, 85, 51, 41, 29, 72, 47, 6, 15, 45, 71, 30, 45, 18, 22, 58, 79, 45, 58, 17 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, generate(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  OrthogonalProjections ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

