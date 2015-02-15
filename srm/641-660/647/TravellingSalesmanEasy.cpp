#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class TravellingSalesmanEasy {
	public:
	int getMaxProfit(int M, vector <int> profit, vector <int> city, vector <int> visit) {
		int i,x,y;
		vector<int> P[101];
		vector<int> PP;
		FOR(i,profit.size()) P[city[i]-1].push_back(profit[i]);
		FOR(i,100) sort(P[i].begin(),P[i].end());
		int mp=0;
		FOR(i,visit.size()) {
			if(P[visit[i]-1].size()) {
				mp+=P[visit[i]-1].back();
				P[visit[i]-1].pop_back();
			}
		}
		return mp;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {3,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 10; verify_case(0, Arg4, getMaxProfit(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1; int Arr1[] = {3,5,2,6,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1,1,1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 15; verify_case(1, Arg4, getMaxProfit(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 6; int Arr1[] = {77,33,10,68,71,50,89}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,1,5,6,2,2,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6,5,5,6,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 155; verify_case(2, Arg4, getMaxProfit(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 7; int Arr1[] = {22,91,53,7,80,100,36,65,92,93,19,92,95,3,60,50,39,36,2,30,63,84,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,3,4,3,6,5,6,6,5,2,7,6,3,2,6,1,7,4,6,3,7,2,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5,7,1,3,6,2,5,7,3,6,3,2,7,3,1,3,1,7,2,3,1,1,3,1,6,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1003; verify_case(3, Arg4, getMaxProfit(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 85; int Arr1[] = {94,21,99,27,91,1,64,96,32,39,84,71,97,53,73,20,7,13,33,45,5,85,7,87,
94,37,48,30,5,85,47,62,91,18,71,37,7,25,75,17,40,19,89,85,86,87,45,
12,61,71,32,73,63,89,25,51,60,76,32,2,69,78,28,32,74,44,47,11,82,5,
2,28,54,35,67,44,35,6,70,66,77,7,60,67,33,66,21,91,76,75,16,79,20,24,
91,31,2,50,11,19,93,49,4,7,55,9,95,39,54,12,48,38,73,100,57,97,44,2,
2,51,40,4,51,3,95,93,56,88,60,98,67,7,99,46,71,75,24,82,87,29,92,92,
81,87,34,83,58,46,79,53,38,32,97,41,65,10,54,81,42,37,76,28,11,50,
13,29,15,99,73,72,2,81,39,75,1,54}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {72,69,19,25,3,65,10,42,37,76,29,34,41,14,46,46,37,55,30,32,84,57,74,
16,10,48,67,31,44,84,11,59,67,63,5,31,28,71,3,21,42,21,61,50,5,79,79,
27,69,33,47,70,76,70,17,73,28,64,77,84,9,6,63,71,17,71,40,9,8,16,76,
76,6,53,47,10,45,31,78,55,13,35,50,43,32,78,78,44,20,56,24,43,80,62,
72,16,5,72,67,29,11,51,64,27,7,44,59,1,40,71,64,63,67,81,72,22,73,59,
21,44,3,18,9,75,72,43,13,44,79,42,58,49,81,44,42,41,35,81,63,74,42,79,
42,39,45,49,18,73,53,36,80,34,75,57,10,79,79,33,48,18,81,3,69,36,37,
49,54,29,17,81,83,13,8,69,5,84}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {39,29,15,5,3,65,29,64,60,21,13,10,73,75,44,84,15,61,26,49,31,27,83,24,
16,55,60,74,71,53,68,15,75,15,36,4,47,9,77,45,63,32,77,84,8,68,11,5,18,
80,36,52,42,59,79,83,81,29,43,70,29,19,68,5,83,60,71,66,62,81,85,39,42,
40,69,60,34,12,2,4,31,36,81,33,71,32,68,5,30,59,61,10,71,49,63,30,62,
83,35,56,82,2,14,59,68,74,32,31,3,28,38,54,38}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4369; verify_case(4, Arg4, getMaxProfit(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TravellingSalesmanEasy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
