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

class ReverseMancala {
	public:
	int N;
	
	vector <int> findMoves(vector <int> S, vector <int> T) {
		int N=S.size();
		vector<int> R,R2;
		int tot=accumulate(ALL(S),0);
		int i;
		
		while(S[0]!=tot) {
			for(i=1;i<N;i++) if(S[i]) {
				R.push_back(i);
				int v=S[i];
				S[i]=0;
				int j=(i+1)%N;
				while(v) S[j]++, v--, j=(j+1)%N;
			}
		}
		
		while(T[0]!=tot) {
			for(i=1;i<N;i++) if(T[i]) {
				R2.push_back((i+T[i])%N+N);
				int v=T[i];
				T[i]=0;
				int j=(i+1)%N;
				while(v) T[j]++, v--, j=(j+1)%N;
			}
		}
		while(R2.size()) R.push_back(R2.back()),R2.pop_back();
		return R;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {6, 3, 4, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 5, 6, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, findMoves(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 5, 6, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 3, 4, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, findMoves(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {10, 0, 1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 0, 0, 2, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 4, 8 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, findMoves(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2, 0, 1, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 2, 1, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 0, 1, 7 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, findMoves(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {3, 2, 4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 6, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7, 1, 0, 7, 1, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, findMoves(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {2, 1, 6, 4, 5, 2, 4, 5, 3, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 4, 8, 0, 2, 6, 0, 1, 3, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10, 8, 2, 16, 19, 2, 4, 11, 7, 6, 12, 19, 14, 14, 15, 3, 4, 17, 11, 3, 9, 16, 4, 8, 13, 12, 11, 9, 17, 12, 19, 4, 9, 8, 10, 2, 0, 17, 10, 3, 4, 8, 16, 0, 19, 15, 7, 6, 17, 6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, findMoves(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {3, 4, 6, 7, 2, 2, 3, 9, 4, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 0, 5, 10, 10, 3, 1, 2, 8, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {8, 14, 1, 12, 11, 4, 9, 10, 15, 16, 2, 19, 2, 16, 17, 11, 16, 0, 12, 7, 4, 5, 17, 14, 0, 5, 13, 3, 7, 10, 12, 1, 16, 14, 1, 9, 1, 8, 7, 5, 5, 11, 19, 16, 18, 1, 15, 10, 16, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(6, Arg2, findMoves(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ReverseMancala ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

