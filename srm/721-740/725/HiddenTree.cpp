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

int mo=1000000007;
ll sum[1<<14];
int dp[1<<14];


class HiddenTree {
	public:
	int N;
	int count(vector <int> b) {
		N=b.size();
		if(N==1) return 1;
		
		sort(ALL(b));
		int i;
		for(int mask=0;mask<1<<N;mask++) {
			sum[mask]=0;
			FOR(i,N) if(mask&(1<<i)) sum[mask]+=b[i];
		}
		
		dp[0]=dp[1]=1;
		ll ret=0;
		for(int mask=2;mask<1<<N;mask++) {
			int high=0;
			dp[mask]=0;
			FOR(i,N) if(mask&(1<<i)) high=i;
			int bef=(mask ^ (1<<high)) | (1<<(high-1));
			for(int bmask=bef; bmask<(1<<high); bmask=(bmask+1)|bef) {
				int del=bmask^mask^(1<<high);
				
				if(sum[del]<b[high]) {
					dp[mask] += dp[bmask];
					if(dp[mask]>=mo) dp[mask]-=mo;
				}
			}
			
			if(high==N-1) {
				ret+=dp[mask];
			}
		}
		
		return ret%mo;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arr0[] = {3,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arr0[] = {3,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { int Arr0[] = {1000000000,1,2,3,4,5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2870; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { int Arr0[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 178290591; verify_case(4, Arg1, count(Arg0)); }
	void test_case_5() { int Arr0[] = {474747474}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(5, Arg1, count(Arg0)); }
	void test_case_6() { int Arr0[] = {536870912,536870912,536870912,536870912,536870912,
536870912,536870912,536870912,536870912}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(6, Arg1, count(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  HiddenTree ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

