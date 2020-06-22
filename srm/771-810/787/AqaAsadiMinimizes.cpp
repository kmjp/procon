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

class AqaAsadiMinimizes {
	public:
	
	
	double getMin(vector <int> P, int B0, int X, int Y, int N) {
		vector<ll> A;
		vector<pair<ll,int>> V;
		int i;
		
		FOR(i,N) {
			if(i<P.size()) {
				A.push_back(P[i]);
			}
			else if(i==P.size()) {
				A.push_back(B0);
			}
			else {
				A.push_back((A.back()*X+Y)%1000000007);
			}
			V.push_back({A.back(),i});
		}
		sort(ALL(V));
		
		double ret=1e10;
		FOR(i,N-1) {
			ret=min(ret,1.0*(V[i+1].first-V[i].first)/abs(V[i].second-V[i+1].second));
		}
		
		return ret;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {11, 0, 30, 20, 1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 5; double Arg5 = 3.0; verify_case(0, Arg5, getMin(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arr0[] = {47, 1, 10, 3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 5; double Arg5 = 0.3333333333333333; verify_case(1, Arg5, getMin(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arr0[] = {123456}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 234567890; int Arg2 = 345678; int Arg3 = 456789; int Arg4 = 10; double Arg5 = 8333191.571428572; verify_case(2, Arg5, getMin(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  AqaAsadiMinimizes ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

