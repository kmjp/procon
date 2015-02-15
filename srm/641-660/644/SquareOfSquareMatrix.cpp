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
int R[501],C[501];

const int CN=601;
ll CC[CN][CN];
ll dp[CN][CN];

class SquareOfSquareMatrix {
	public:
	int count(int n, vector <int> r, vector <int> c) {
		int i,j,y,x;
		
		vector<ll> p2;
		p2.push_back(1);
		FOR(i,502*502) p2.push_back(p2.back()*2%mo);
		FOR(i,CN) for(j=0;j<=i;j++) CC[i][j]=(j==0||j==i)?1:(CC[i-1][j-1]+CC[i-1][j])%mo;
		
		ZERO(R);
		ZERO(C);
		FOR(i,r.size()) r[i]--,c[i]--, C[r[i]]=R[c[i]]=1;
		
		int ro=0,co=0;
		FOR(x,n) {
			if(R[x]&&C[x]) return 0;
			if(R[x]) ro++;
			if(C[x]) co++;
		}
		int left=n-ro-co,rn,cn;
		FOR(i,501) FOR(j,501-i) dp[i][j]=p2[(i+ro)*(j+co)-r.size()];
		for(i=0;i<=501;i++) for(j=0;j<=501-i;j++) for(x=0;x<j;x++) (dp[i][j]-=dp[i][x]*CC[j][x]%mo)%=mo;
		for(i=0;i<=501;i++) for(j=0;j<=501-i;j++) for(x=0;x<j;x++) (dp[j][i]-=dp[x][i]*CC[j][x]%mo)%=mo;
		FOR(i,501) FOR(j,501-i) ((dp[i][j]%=mo)+=mo)%=mo;
		
		ll ret=0;
		FOR(rn,left+1) FOR(cn,left+1-rn) (ret+=dp[rn][cn] * CC[left][rn] % mo * CC[left-rn][cn] % mo)%=mo;
		return (int)ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 400; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 630758192; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 10; int Arr1[] = {1,1,2,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,5,4,6,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 9800720; verify_case(4, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SquareOfSquareMatrix ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
