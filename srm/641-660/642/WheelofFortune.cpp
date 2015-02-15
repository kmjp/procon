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


class WheelofFortune {
	public:
	double maxExpectedValue(int N, vector <int> s) {
		int i,x,y;
		int L=s.size();
		double dp[303]={},op[2][303][303];
		
		ZERO(op);
		dp[0]=1;
		
		FOR(i,L) {
			int cur=i%2,tar=cur^1;
			ZERO(op[tar]);
			double p=s[i]*1.0/N;
			
			for(y=1;y<=N/2;y++) {
				double dp2[303]={};
				for(x=i+1;x>=0;x--) if(dp[x]) {
					if(s[i]==N) {
						dp2[x+1]+=dp[x];
						op[tar][y][x+1]+=dp[x]*(op[cur][y][x]+1);
					}
					else {
						dp2[x+1]+=dp[x]*p;
						dp2[x]+=dp[x]*(1-p);
						op[tar][y][x+1]+=dp[x]*    p*(op[cur][y][x]+(max(0,s[i]-y)+max(0,s[i]-(N-y)))*1.0/s[i]);
						op[tar][y][x]  +=dp[x]*(1-p)*(op[cur][y][x]+(1+min(y,N-s[i])-max(1,y-(s[i]-1)))*1.0/(N-s[i]));
					}
				}
				for(x=i+1;x>=0;x--) if(dp2[x]) op[tar][y][x] /= dp2[x];
			}
			for(x=i+1;x>=0;x--) {
				dp[x+1] += dp[x]*p;
				dp[x]   *= 1-p;
			}
		}
		
		double ret=0;
		FOR(i,L+1) {
			double ma=0;
			for(x=1;x<=N/2;x++) ma=max(ma,op[L%2][x][i]);
			ret+=dp[i]*(i+ma);
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.25; verify_case(0, Arg2, maxExpectedValue(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 6; int Arr1[] = {1,1,1,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.0000000000000004; verify_case(1, Arg2, maxExpectedValue(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 20; int Arr1[] = {1,20,1,20,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 4.299999999999999; verify_case(2, Arg2, maxExpectedValue(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arr1[] = {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4,3,3,8,3,2,7,9,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 31.973469385798197; verify_case(3, Arg2, maxExpectedValue(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 15; int Arr1[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 16.691531334568044; verify_case(4, Arg2, maxExpectedValue(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  WheelofFortune ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
