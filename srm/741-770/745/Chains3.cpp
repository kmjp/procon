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

class Chains3 {
	public:
	string validate(vector <int> c) {
		int N=c.size();
		int L=1<<30,R=-1;
		int invalid_index = -1;
		int i;
		
		FOR(i,c.size()) {
			int a=c[i];
			
			if(invalid_index==-1 && a>=N) {
				invalid_index=i+1;
			}
			
			if(i) {
				if(L<=a && a<=R) return "invalid " + to_string(i+1);
				
				if(a!=L-1 && a!=R+1 && invalid_index ==-1) invalid_index=i+1;
			}
			
			L=min(L,a);
			R=max(R,a);
		}
		
		if(invalid_index==-1) {
			return "maximal "+to_string(N);
		}
		else {
			return "valid "+to_string(invalid_index);
		}
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "maximal 2"; verify_case(0, Arg1, validate(Arg0)); }
	void test_case_1() { int Arr0[] = {4, 5, 6, 2, 1, 9, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "valid 4"; verify_case(1, Arg1, validate(Arg0)); }
	void test_case_2() { int Arr0[] = {4, 5, 6, 2, 1, 3, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "invalid 6"; verify_case(2, Arg1, validate(Arg0)); }
	void test_case_3() { int Arr0[] = {4, 5, 4, 2, 1, 3, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "invalid 3"; verify_case(3, Arg1, validate(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Chains3 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

