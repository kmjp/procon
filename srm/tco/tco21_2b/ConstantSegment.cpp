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

vector<int> A[1010101];

class ConstantSegment {
	public:
	int sendSomeHome(int N, int K, int M, vector <int> Pprefix, int seed) {
		vector<ll> P;
		FORR(a,Pprefix) P.push_back(a);
		long long state = seed;
		for (int i=Pprefix.size(); i<N; ++i) {
		    state = (state * 1103515245 + 12345) % (1LL << 31);
		    P.push_back((state / 16) % M);
		}
		
		int i;
		FOR(i,M+1) A[i].clear();
		int ret=1<<30;
		FOR(i,N) {
			A[P[i]].push_back(i);
			int s=A[P[i]].size();
			if(s>=K) {
				int dif=A[P[i]][s-1]-A[P[i]][s-K]-(K-1);
				ret=min(ret,dif);
			}
			
		}
		if(ret==1<<30) ret=-1;
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 3; int Arg2 = 10; int Arr3[] = {1, 4, 3, 3, 3, 3, 2, 0, 3, 9}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; int Arg5 = 0; verify_case(0, Arg5, sendSomeHome(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 5; int Arg2 = 10; int Arr3[] = {1, 4, 3, 3, 3, 3, 2, 0, 3, 9}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; int Arg5 = 2; verify_case(1, Arg5, sendSomeHome(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 6; int Arg2 = 10; int Arr3[] = {1, 4, 3, 3, 3, 3, 2, 0, 3, 9}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; int Arg5 = -1; verify_case(2, Arg5, sendSomeHome(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 2; int Arg2 = 47; int Arr3[] = {1, 4, 5, 2, 1, 2, 3, 7, 8, 3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4747; int Arg5 = 1; verify_case(3, Arg5, sendSomeHome(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4_() { int Arg0 = 20; int Arg1 = 3; int Arg2 = 10; int Arr3[] = {0, 1, 2, 3, 4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 123456789; int Arg5 = 9; verify_case(4, Arg5, sendSomeHome(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 200000; int Arg1 = 1000; int Arg2 = 2; int Arr3[] = {0, 1, 0, 1, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 123456789; int Arg5 = 9; verify_case(4, Arg5, sendSomeHome(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ConstantSegment ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

