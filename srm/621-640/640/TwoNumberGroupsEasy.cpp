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

class TwoNumberGroupsEasy {
	public:
	vector <int> A,numA,B,numB;
	int dist2(int M) {
		map<int,ll> m1,m2;
		int i,j;
		int ret=0;
		FOR(i,A.size()) m1[A[i]%M] += numA[i], ret+=numA[i];
		FOR(i,B.size()) m2[B[i]%M] += numB[i], ret+=numB[i];
		ITR(it,m1) ret-=2*min(it->second,m2[it->first]);
		return ret;
	}
	
	int dist(int M) {
		if(M<=1) return 1<<30;
		int i;
		int ret=dist2(M);
		for(i=2;i*i<=M;i++) if(M%i==0) {
			ret=min(ret,dist2(i));
			ret=min(ret,dist2(M/i));
		}
		return ret;
	}
	
	int solve(vector <int> A_, vector <int> numA_, vector <int> B_, vector <int> numB_) {
		A=A_; B=B_; numA=numA_; numB=numB_;
		int ret=dist(1<<30),x,y;
		FOR(x,A.size()) if(A[x]>1) ret=min(ret,dist(A[x]));
		FOR(x,B.size()) if(B[x]>1) ret=min(ret,dist(B[x]));
		FOR(x,A.size()) FOR(y,A.size()) ret=min(ret,dist(abs(A[x]-A[y])));
		FOR(x,A.size()) FOR(y,B.size()) ret=min(ret,dist(abs(A[x]-B[y])));
		FOR(x,A.size()) FOR(y,A.size()) ret=min(ret,dist(abs(B[x]-B[y])));
		
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,6,7,8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(0, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {5,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {12,14}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(1, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(2, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(3, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(4, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {733815053,566264976,984867861,989991438,407773802,701974785,599158121,713333928,530987873,702824160}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8941,4607,1967,2401,495,7654,7078,4213,5485,1026}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {878175560,125398919,556001255,570171347,643069772,787443662,166157535,480000834,754757229,101000799}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {242,6538,7921,2658,1595,3049,655,6945,7350,6915}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 7; verify_case(5, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TwoNumberGroupsEasy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
