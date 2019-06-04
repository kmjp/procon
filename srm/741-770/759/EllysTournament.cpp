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

double win[505][505];
double memo[505][505][2];
double prob[505][505];

double Win(int L,int R);
double Top(int L,int R,int side) {
	if(L==R) return 1;
	if(memo[L][R][side]>=0) return memo[L][R][side];
	double ret=0;
	int x;
	if(side==0) {
		for(x=L+1;x<=R;x++) ret+=Win(L,x)*prob[L][x]*Top(x,R,0);
	}
	else {
		for(x=L;x<=R-1;x++) ret+=Win(x,R)*prob[R][x]*Top(L,x,1);
	}
	ret/=(R-L);
	return memo[L][R][side]=ret;
}
double Win(int L,int R) {
	if(win[L][R]>=0) return win[L][R];
	double ret=0;
	int x;
	for(x=L;x<R;x++) ret+=Top(L,x,0)*Top(x+1,R,1);
	return win[L][R]=ret;
	
}

class EllysTournament {
	public:
	double getChance(int N, int K, vector <int> R) {
		int x,y;
		FOR(x,N) FOR(y,N) {
			win[x][y]=memo[x][y][0]=memo[x][y][1]=-1;
			prob[x][y]=1.0*R[x]/(R[x]+R[y]);
		}
		K--;
		return Top(0,K,1)*Top(K,N-1,0);
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 2; int Arr2[] = {2103, 2019, 1911, 2331}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 0.17753927527829697; verify_case(0, Arg3, getChance(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 12; int Arg1 = 6; int Arr2[] = {42, 88, 13, 11, 71, 55, 32, 13, 72, 53, 37, 50}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 0.06697114679670368; verify_case(1, Arg3, getChance(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 20; int Arg1 = 13; int Arr2[] = {1543, 1230, 421, 1415, 1271, 1962, 2677, 2373, 2951, 114, 1379, 2015, 2211, 955, 2066, 2573, 2982, 296, 1730, 1591}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 0.05017297846158086; verify_case(2, Arg3, getChance(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 42; int Arr2[] = {2750, 2877, 2224, 186, 1398, 1084, 1542, 2770, 2288, 1078, 373, 2417, 476, 2968, 564, 1565, 1740, 1377, 2633, 287,
 111, 823, 578, 520, 1708, 174, 144, 1295, 694, 678, 227, 2588, 371, 2740, 211, 1798, 82, 2385, 2979, 389,
 2031, 1667, 2541, 2561, 1471, 2562, 974, 577, 286, 2836, 120, 2290, 185, 554, 2549, 1410, 1814, 1508, 2559, 1806,
 2215, 1606, 2637, 1394, 1583, 1491, 2908, 529, 2556, 1034, 2770, 750, 2866, 2590, 1156, 2646, 2536, 958, 2862, 2565,
 1027, 2744, 1160, 276, 2080, 322, 92, 790, 2452, 1859, 602, 2935, 2392, 1076, 2991, 1158, 2721, 868, 112, 29}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 0.003026484586204139; verify_case(3, Arg3, getChance(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysTournament ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

