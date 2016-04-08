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

ll A[200],S[200];

class AlmostFibonacciKnapsack {
	public:
	vector<int> ret,fin;
	
	void dfs(int cur,ll x) {
		if(fin.size()) return;
		if(x==0) {
			fin=ret;
			return;
		}
		if(cur<=0) return;
		if(x>S[cur]) return;
		if(x>=A[cur]) {
			ret.push_back(cur);
			dfs(cur-1,x-A[cur]);
			ret.pop_back();
		}
		if(fin.empty()) dfs(cur-1,x);
	}
	
	vector <int> getIndices(long long x) {
		int i;
		A[1]=2;
		A[2]=3;
		for(i=3;i<=86;i++) A[i]=A[i-1]+A[i-2]-1;
		for(i=1;i<=86;i++) S[i]=S[i-1]+A[i];
		
		fin.clear();
		ret.clear();
		dfs(86,x);
		if(fin.empty()) fin.push_back(-1);
		
		return fin;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { long long Arg0 = 148LL; int Arr1[] = {6, 10, 8, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getIndices(Arg0)); }
	void test_case_1() { long long Arg0 = 2LL; int Arr1[] = {1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getIndices(Arg0)); }
	void test_case_2() { long long Arg0 = 13LL; int Arr1[] = {2, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getIndices(Arg0)); }
	void test_case_3() { long long Arg0 = 3LL; int Arr1[] = {2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getIndices(Arg0)); }
	void test_case_4() { long long Arg0 = 86267769395LL; int Arr1[] = {3, 14, 15, 9, 26, 53, 5, 8 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getIndices(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  AlmostFibonacciKnapsack ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
