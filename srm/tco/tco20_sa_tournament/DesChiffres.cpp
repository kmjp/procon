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

class DesChiffres {
	public:
	int solve(vector <int> tiles, int target) {
		set<ll> S[1<<6];
		int i;
		FOR(i,6) S[1<<i].insert(tiles[i]);
		
		int mask,sm1,sm2;
		ll ret=-1LL<<60;
		FOR(mask,1<<6) {
			FOR(sm1,mask) if((sm1&mask)==sm1) {
				sm2=mask^sm1;
				
				FORR(a,S[sm1]) {
					FORR(b,S[sm2]) {
						S[mask].insert(a+b);
						S[mask].insert(a-b);
						S[mask].insert(a*b);
						if(b&&a%b==0) S[mask].insert(a/b);
					}
				}
			}
			FORR(v,S[mask]) {
				if(abs(v-target)<abs(ret-target) || (abs(v-target)==abs(ret-target)&&v<ret)) ret=v;
			}
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4,5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 722; int Arg2 = 722; verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {100, 9, 9, 4, 5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 734; int Arg2 = 733; verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {100, 50, 75, 25, 4, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 100; verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {100, 50, 4, 4, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 128; int Arg2 = 128; verify_case(3, Arg2, solve(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {5,2,3,1,9,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 999; int Arg2 = 1000; verify_case(4, Arg2, solve(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {100,25,2,10,5,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 359; int Arg2 = 720; verify_case(5, Arg2, solve(Arg0, Arg1)); }
	void test_case_5_() { int Arr0[] = {1,10,4,3,1,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 900; int Arg2 = 720; verify_case(5, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DesChiffres ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

