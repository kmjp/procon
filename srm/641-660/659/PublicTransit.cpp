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

class PublicTransit {
	public:
	int minimumLongestDistance(int R, int C) {
		int mi=100;
		int x1,y1,x2,y2;
		int x3,y3,x4,y4;
		FOR(x1,R) FOR(y1,C) {
			FOR(x2,R) FOR(y2,C) {
				int ma=0;
				FOR(x3,R) FOR(y3,C) {
					FOR(x4,R) FOR(y4,C) {
						int d=abs(x3-x4)+abs(y3-y4);
						int d1=abs(x3-x1)+abs(y3-y1) + abs(x4-x2)+abs(y4-y2);
						int d2=abs(x3-x2)+abs(y3-y2) + abs(x4-x1)+abs(y4-y1);
						ma=max(ma,min(d,min(d1,d2)));
					}
					if(ma>=mi) break;
				}
				mi=min(mi,ma);
			}
		}
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, minimumLongestDistance(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; verify_case(1, Arg2, minimumLongestDistance(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 4; verify_case(2, Arg2, minimumLongestDistance(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 8; int Arg1 = 2; int Arg2 = 4; verify_case(3, Arg2, minimumLongestDistance(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PublicTransit ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
