#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

//-------------------------------------------------------

int dp[2][51][2501];
class KingdomAndDice {
	public:
	int space[55];
	
	double newFairness(vector <int> firstDie, vector <int> secondDie, int X) {
		int N=firstDie.size(),i,j,x,y,k,left=0,tot=0;
		
		sort(firstDie.begin(),firstDie.end());
		secondDie.push_back(0);
		secondDie.push_back(X+1);
		sort(secondDie.begin(),secondDie.end());
		
		FOR(i,N+1) space[i]=min(50,secondDie[i+1]-secondDie[i]-1);
		FOR(i,N) {
			if(firstDie[i]==0) left++;
			else {
				FOR(j,N+1) {
					if(secondDie[j] < firstDie[i] && firstDie[i] < secondDie[j+1]) space[j]--, tot+=j;
				}
			}
		}
		
		space[0]=50;
		ZERO(dp);
		dp[0][left][tot]=1;
		FOR(i,N+1) {
			int cur=i%2,tar=cur^1;
			ZERO(dp[tar]);
			FOR(x,left+1) FOR(y,2501) if(dp[cur][x][y]) {
				j=min(space[i],x);
				FOR(k,j+1) dp[tar][x-k][y+k*i]=1;
			}
		}
		
		int best=2600;
		FOR(x,2501) if(dp[(N+1)%2][0][x] && abs(x-N*N/2.0)<abs(best-N*N/2.0)) best=x;
		return best/(double)(N*N);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 2, 7, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 3, 8, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; double Arg3 = 0.4375; verify_case(0, Arg3, newFairness(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0, 2, 7, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 3, 8, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; double Arg3 = 0.375; verify_case(1, Arg3, newFairness(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 47; double Arg3 = 0.5; verify_case(2, Arg3, newFairness(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {19, 50, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {26, 100, 37}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; double Arg3 = 0.2222222222222222; verify_case(3, Arg3, newFairness(Arg0, Arg1, Arg2)); }
	//void test_case_4() { int Arr0[] = {6371, 0, 6256, 1852, 0, 0, 6317, 3004, 5218, 9012}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1557, 6318, 1560, 4519, 2012, 6316, 6315, 1559, 8215, 1561}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10000; double Arg3 = 0.49; verify_case(4, Arg3, newFairness(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {6,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; double Arg3 = 0; verify_case(4, Arg3, newFairness(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  KingdomAndDice ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
