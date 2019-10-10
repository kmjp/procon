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

class MeanMedian {
	public:
	int minEffort(int needMean, int needMedian, vector <int> d) {
		int N=d.size();
		sort(ALL(d));
		int ret=0;
		needMean*=N;
		vector<int> V;
		int i,j;
		FOR(i,N) {
			if(i<N/2+1) {
				ret+=needMedian*d[i];
				needMean-=needMedian;
				FOR(j,10-needMedian) V.push_back(d[i]);
			}
			else {
				FOR(j,10) V.push_back(d[i]);
			}
		}
		
		sort(ALL(V));
		FOR(i,needMean) ret+=V[i];
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 4; int Arr2[] = {30, 25, 20}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 180; verify_case(0, Arg3, minEffort(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 4; int Arr2[] = {30, 25, 20}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 260; verify_case(1, Arg3, minEffort(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 3; int Arr2[] = {1, 4, 3, 2, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 110; verify_case(2, Arg3, minEffort(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 0; int Arr2[] = {1000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(3, Arg3, minEffort(Arg0, Arg1, Arg2)); }
//	void test_case_4() { int Arg0 = 8; int Arg1 = 3; int Arr2[] = {4, 8, 12, 16, 18, 20, 22, 23, 24}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1046; verify_case(4, Arg3, minEffort(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 0; int Arg1 = 10; int Arr2[] = {1,1,1,10,10,10,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1046; verify_case(4, Arg3, minEffort(Arg0, Arg1, Arg2)); }
// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MeanMedian ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

