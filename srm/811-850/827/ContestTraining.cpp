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

class ContestTraining {
	public:
	vector<long long> practice(long long heavyDays, long long lightDays, long long heavyProblems, long long lightProblems, vector<long long> queries) {
		vector<ll> ret;
		__int128 H=(__int128)heavyDays*heavyProblems;
		__int128 L=(__int128)lightDays*lightProblems;
		
		FORR(q,queries) {
			__int128 a=q/(H+L)*(heavyDays+lightDays);
			q%=(H+L);
			if(q<H) {
				a+=(q+heavyProblems-1)/heavyProblems;
			}
			else {
				q-=H;
				a+=heavyDays;
				a+=(q+lightProblems-1)/lightProblems;
			}
			
			
			ret.push_back((ll)a);
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { long long Arg0 = 5LL; long long Arg1 = 2LL; long long Arg2 = 5LL; long long Arg3 = 1LL; long Arr4[] = {5, 21, 25, 26, 27, 28, 32, 43, 50}; vector<long long> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); long Arr5[] = {1, 5, 5, 6, 7, 8, 8, 11, 12 }; vector<long long> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(0, Arg5, practice(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { long long Arg0 = 1LL; long long Arg1 = 1234567890LL; long long Arg2 = 10LL; long long Arg3 = 1LL; long Arr4[] = {7, 17, 18, 19, 20, 987654321, 987654322, 2345678901, 345678901234}; vector<long long> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); long Arr5[] = {1, 8, 9, 10, 11, 987654312, 987654313, 2345678883, 345678898714 }; vector<long long> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(1, Arg5, practice(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { long long Arg0 = 1LL; long long Arg1 = 1234567890LL; long long Arg2 = 10LL; long long Arg3 = 1LL; long Arr4[] = {19, 345678901234, 987654322, 18, 17, 2345678901, 987654321, 20, 20, 20, 7}; vector<long long> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); long Arr5[] = {10, 345678898714, 987654313, 9, 8, 2345678883, 987654312, 11, 11, 11, 1 }; vector<long long> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(2, Arg5, practice(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ContestTraining ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

