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

ll comb(int P_,int Q_) {
	static const int N_=1020;
	static ll C_[N_][N_];
	
	if(C_[0][0]==0) {
		int i,j;
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j])%mo;
	}
	if(P_<0 || P_>N_ || Q_<0 || Q_>P_) return 0;
	return C_[P_][Q_];
}

class OkonomiyakiParty {
	public:
	int N;
	int count(vector <int> osize, int M, int K) {
		N=osize.size();
		sort(osize.begin(),osize.end());
		ll ret=0;
		int x,y;
		FOR(x,N) {
			y=x;
			while(y<N && osize[y]<=osize[x]+K) y++;
			ret+=comb(y-x-1,M-1);
		}
		return ret%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,4,6,7,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; int Arg3 = 6; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,6,2,7,4,2,6,1,5,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 3; int Arg3 = 60; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1,4,5,7,10,11,13,16,18}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 5; int Arg3 = 0; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {55,2,7,232,52,5,5332,623,52,6,532,5147}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 10000; int Arg3 = 924; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {5781,8708,1754,4750,9888,3675,4810,1020,922,9834,5695,1101,1236,2496,8431,6727,
1376,3373,4423,1839,7438,9407,1851,6966,8715,2905,542,535,8980,2602,2603,3117,3452,
5682,7775,4356,5140,8923,9801,3729}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; int Arg2 = 4003; int Arg3 = 114514; verify_case(4, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  OkonomiyakiParty ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
