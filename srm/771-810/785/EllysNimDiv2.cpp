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


int from[2050];
int to[2050];

class EllysNimDiv2 {
	public:
	int getMin(vector <int> A) {
		int i;
		FOR(i,2050) from[i]=1<<30;
		from[0]=0;
		FORR(a,A) {
			FOR(i,2050) to[i]=1<<30;
			FOR(i,2048) {
				for(int x=0;x+a<2048;x++) to[i^(x+a)]=min(to[i^(x+a)],from[i]+x);
			}
			
			swap(from,to);
		}
		return from[0];
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {42, 13, 123, 55, 666, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 480; verify_case(0, Arg1, getMin(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, getMin(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, getMin(Arg0)); }
	void test_case_3() { int Arr0[] = {371, 740, 211, 798, 82, 385, 979, 389, 31, 667, 541, 561, 471}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 42; verify_case(3, Arg1, getMin(Arg0)); }
	void test_case_4() { int Arr0[] = {769, 727, 657, 924, 879, 674, 652, 995, 947, 896, 869, 553, 954, 974, 681, 768, 913}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 666; verify_case(4, Arg1, getMin(Arg0)); }
	void test_case_5() { int Arr0[] = {543, 230, 421, 415, 271, 962, 677, 373, 951, 114, 379, 15, 211, 955,
 66,  573, 982, 296, 730, 591, 750, 877, 224, 186, 398, 84, 542, 770,
 288, 78,  373, 417, 476, 968, 564, 565, 740, 377, 633, 287, 111, 823}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 44; verify_case(5, Arg1, getMin(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysNimDiv2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

