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

class PlaneGame {
	public:
	
	int how(vector<int> x,vector<int> y,ll dx,ll dy) {
		int ma=0,a,b;
		FOR(a,x.size()) {
			int cnt=0;
			FOR(b,x.size()) {
				if((x[b]-x[a])*dy-(y[b]-y[a])*dx==0) cnt++;
			}
			ma=max(ma,cnt);
		}
		return ma;
	}
	
	int bestShot(vector <int> x, vector <int> y) {
		int N=x.size();
		int a,b,c;
		
		if(N<=2) return N;
		
		int ma=2;
		FOR(b,N) FOR(a,b) {
			vector<int> x2,y2;
			FOR(c,N) {
				ll cr = 1LL*(x[c]-x[a])*(y[b]-y[a])-1LL*(y[c]-y[a])*(x[b]-x[a]);
				if(cr) x2.push_back(x[c]), y2.push_back(y[c]);
			}
			ma=max(ma,(N-(int)x2.size()) + how(x2,y2,-(y[b]-y[a]),(x[b]-x[a])));
		}
		
		return ma;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, bestShot(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, -1, 1, 1, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, -1, -1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(1, Arg2, bestShot(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 0, 0, 1, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, -1, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(2, Arg2, bestShot(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, -3, 3, 3, -3, 0, 0, 3, -3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, -3, -3, 3, 3, 3, -3, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(3, Arg2, bestShot(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(4, Arg2, bestShot(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {-1000000, -1, 999998, 1, -1001, 1000000, -999999, 999999, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000000, 1, 1000000, -1, -999, 1000000, 0, 0, -999999, 999999}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(5, Arg2, bestShot(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PlaneGame ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
