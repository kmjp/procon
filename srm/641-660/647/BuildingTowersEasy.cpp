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

class BuildingTowersEasy {
	public:
	int maxHeight(int N, vector <int> x, vector <int> t) {
		vector <int> X,T;
		int i,j,k;
		N--;
		X.push_back(0);
		T.push_back(0);
		FOR(i,x.size()) if(x[i]!=1) X.push_back(x[i]-1),T.push_back(t[i]);
		if(X.back()!=N) X.push_back(N),T.push_back(300000);
		
		int M=X.size();
		FOR(i,M) {
			FOR(j,M-1) {
				T[j]=min(T[j+1]+(X[j+1]-X[j]),T[j]);
				T[j+1]=min(T[j]+(X[j+1]-X[j]),T[j+1]);
			}
		}
		
		int ma=0;
		FOR(i,M) ma=max(ma,T[i]);
		FOR(i,M-1) if(X[i+1]-X[i]>T[i+1]-T[i]) {
			int d=X[i+1]-X[i];
			int m=max(T[i+1],T[i]);
			d-=abs(T[i+1]-T[i]);
			ma=max(ma,m+d/2);
		}
		return ma;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arr1[] = {3,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(0, Arg3, maxHeight(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 100000; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 99999; verify_case(1, Arg3, maxHeight(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2718; int Arr1[] = {1,30,400,1300,2500}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100000,100000,100000,100000,100000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2717; verify_case(2, Arg3, maxHeight(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 20; int Arr1[] = {4,7,13,15,18}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,8,1,17,16}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; verify_case(3, Arg3, maxHeight(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 447; int Arr1[] = {32,35,55,60,61,88,91,97,128,151,181,186,192,196,198,237,259,268,291,314,341,367,389,390,391,428,435}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {81,221,172,641,25,953,330,141,123,440,692,394,200,649,78,726,50,810,501,4,216,407,2,172,0,29,14}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 120; verify_case(4, Arg3, maxHeight(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 97638; int Arr1[] = {8,1749,4550,5388,6752,7089,9737,14891,16671,16821,17691,19753,24589,
25348,30114,32213,34376,36467,37699,41490,44784,44893,57316,58275,58567,
61122,61489,63195,64776,65905,68788,69908,72853,78152,78784,82779,84488,
86277,88611,92793,93214,97583}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {16610,6,497,14,42892,31,79,1203,518,31147,597,7846,1396,8309,12,14,1148,
433,23693,13,1939,244,19,46,27,611,412,10,27023,19141,34,15667,588,10,229,
83,390,14,38441,16021,4,39386}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6343; verify_case(5, Arg3, maxHeight(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BuildingTowersEasy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
