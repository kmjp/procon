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

class AverageVarianceSubset {
	public:
	double average(vector <int> s, int R) {
		int N=s.size();
		sort(ALL(s));
		int S,E;
		
		__int128 tnum=0;
		long double tot=0;
		int i,j;
		
		FOR(S,N) {
			E=S+1;
			while(E<N && s[E]<=s[S]+R) E++;
			
			__int128 num[52]={};
			__int128 sum[52]={};
			__int128 sum2[52]={};
			__int128 sum3[52]={};
			
			num[1]=1;
			sum[1]=s[S];
			sum2[1]=sum3[1]=1LL*s[S]*s[S];
			
			for(i=S+1;i<E;i++) {
				for(j=51;j>=1;j--) {
					sum2[j]+=sum2[j-1]+2*sum[j-1]*s[i]+num[j-1]*s[i]*s[i];
					sum[j] +=num[j-1]*s[i]+sum[j-1];
					sum3[j]+=num[j-1]*s[i]*s[i]+sum3[j-1];
					num[j] +=num[j-1];
				}
			}
			
			for(j=1;j<=50;j++) {
				tnum+=num[j];
				tot += (long double)sum3[j]/j;
				tot -= (long double)sum2[j]/j/j;
			}
			
		}
		
		return (long double)tot/tnum;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 0.1; verify_case(0, Arg2, average(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; double Arg2 = 0.3095238095238096; verify_case(1, Arg2, average(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {5,1,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000000; double Arg2 = 1.2476851851851847; verify_case(2, Arg2, average(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,11,111,1111,11111,111111,1111111,11111111,111111111}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 123456; double Arg2 = 1.1349430459217174E9; verify_case(3, Arg2, average(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,11,111,1111,11111,111111,1111111,11111111,111111111}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 999999999; double Arg2 = 9.989198236452121E14; verify_case(4, Arg2, average(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1,1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000000; double Arg2 = 8.3333333166666672E16; verify_case(5, Arg2, average(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {1,1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 0.0; verify_case(6, Arg2, average(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  AverageVarianceSubset ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

