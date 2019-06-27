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

class SortArray {
	public:
	vector <int> verify(int N, vector <int> C) {
		int i,x,y;
		int mask;
		FOR(mask,1<<N) {
			vector<int> V(N,0);
			FOR(y,N) if((mask&(1<<y))==0) V[y]=1;
			
			FORR(c,C) {
				int n[2]={};
				FOR(y,N) if(c&(1<<y)) n[V[y]]++;
				FOR(y,N) if(c&(1<<y)) {
					if(n[0]) n[0]--, V[y]=0;
					else V[y]=1;
				}
			}
			FOR(y,__builtin_popcount(mask)) if(V[y]==1) {
				int a=0,b=__builtin_popcount(mask);
				FOR(y,N) {
					if((mask&(1<<y))) V[y]=a++;
					else V[y]=b++;
				}
				
				return V;
			}
		}
		return {};
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 7; int Arr1[] = {127}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, verify(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 8; int Arr1[] = {85, 170}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2, 3, 4, 5, 7, 6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, verify(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {3, 5, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, verify(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arr1[] = {255, 1020}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 4, 5, 6, 7, 8, 9, 0, 1, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, verify(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 10; int Arr1[] = {255, 1020, 255, 1020, 255, 1020, 255, 1020, 255, 1020}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, verify(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SortArray ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

