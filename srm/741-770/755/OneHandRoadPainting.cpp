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

class OneHandRoadPainting {
	public:
	long long fastest(vector <int> S, vector <int> E, int P_) {
		ll P=P_;
		ll ret=0;
		while(S.size()) {
			if(S.back()==E.back()) {
				S.pop_back();
				E.pop_back();
				continue;
			}
			if(E.back()-S.back()>=P) {
				ll num=(E.back()-S.back())/P;
				ll e=E.back();
				ll f=e-(num-1)*P;
				ret+=(e+f)*num/2;
				E.back()-=P*num;
			}
			else {
				ret+=E.back();
				ll lef=P;
				while(lef&&S.size()) {
					ll m=min(E.back()-S.back(),(int)lef);
					lef-=m;
					E.back()-=m;
					if(E.back()==S.back()) {
						E.pop_back();
						S.pop_back();
					}
				}
			}
		}
		return 2*ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; long long Arg3 = 42LL; verify_case(0, Arg3, fastest(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {3, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; long long Arg3 = 18LL; verify_case(1, Arg3, fastest(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1, 10, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 13, 22}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; long long Arg3 = 98LL; verify_case(2, Arg3, fastest(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  OneHandRoadPainting ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

