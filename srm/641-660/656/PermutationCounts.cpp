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

ll mo=1000000007;
ll dp[3000];

const int NUM_=1000001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

class PermutationCounts {
	public:
	int countPermutations(int N, vector <int> pos) {
		int i,j;
		
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
		
		pos.push_back(0);
		pos.push_back(N);
		sort(pos.begin(),pos.end());
		
		ZERO(dp);
		dp[0]=1;
		for(i=0;i<pos.size();i++) {
			FOR(j,i) {
				ll pat=dp[j]*factr[pos[i]-pos[j]]%mo;
				if((i-j)%2==0) dp[i] += mo-pat;
				else dp[i] += pat;
			}
			dp[i] %= mo;
		}
		
		return dp[pos.size()-1]*fact[N]%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; verify_case(0, Arg2, countPermutations(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 13; int Arr1[] = {12,11,10,9,8,7,6,5,4,3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, countPermutations(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 13; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, countPermutations(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 9; int Arr1[] = {2,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1421; verify_case(3, Arg2, countPermutations(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 80; int Arr1[] = {31,41,59,26,53,58,9,79,32,3,8,46}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 82650786; verify_case(4, Arg2, countPermutations(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 875; int Arr1[] = {295,311,98,345,420,547,646,734,380,325,608,783,141,65,305,437,769,252,44,
872,123,6,50,507,450,426,343,740,69,695,101,607,597,535,342,307,329,837,803,
237,459,444,498,15,712,134,473,14,715,223,787,192,710,750,193,293,242,652,
212,580,545,488,506,533,774,460,285,534,350,210,559,805,686,67,159,541,706,
514,657,801,373,754,310,800,589,736,863,675,254,283,604,27,628,103,81,235,
677,461,609,30,581,75,756,688,262,563,679,21,217,515,836,868,13,728,717,
309,267,767,259,414,332,744,129,859,4,179,632,415,278,812,79,77,784,573,433,
865,407,121,477,567,790,127,593,57,674,114,239,599,552,738}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 169176190; verify_case(5, Arg2, countPermutations(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PermutationCounts ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
