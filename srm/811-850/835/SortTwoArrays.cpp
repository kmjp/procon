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


class SortTwoArrays {
	public:
	vector<int> R;
	vector<int> A,B;
	void go(int x,int y) {
		R.push_back(x);
		R.push_back(y);
		swap(A[x],B[y]);
	}
	vector <int> twoSorts(int N, vector <int> a, vector <int> b) {
		R.clear();
		A=a;
		B=b;
		int i,j;
		FOR(i,N) {
			vector<pair<int,int>> V;
			int x=min_element(A.begin()+i,A.begin()+N)-A.begin();
			int y=min_element(B.begin()+i,B.begin()+N)-B.begin();
			
			if(x==i&&y==i) {
				go(i,i);
			}
			else if(x>i&&y==i) {
				go(i,y);
				go(x,i);
			}
			else if(x==i&&y>i) {
				go(x,i);
				go(i,y);
			}
			else {
				go(x,i);
				go(i,y);
				go(x,y);
			}
		}
		return R;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {10, 20, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10, 20, 30}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 0 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, twoSorts(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {10, 11, 12, 22, 14}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {20, 21, 13, 23, 24}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 2 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, twoSorts(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 5; int Arr1[] = {10, 50, 60, 30, 80}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {20, 70, 99, 90, 40}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 2, 3, 1, 1, 4 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, twoSorts(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arr1[] = {1, 2, 90, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {60, 70, 80, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2, 3 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, twoSorts(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SortTwoArrays ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

