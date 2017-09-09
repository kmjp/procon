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

int O[9];
int from[1<<9][1<<9];
int to[1<<9][1<<9];

class Avoid9 {
	public:
	int maxSizeOf9Free(vector <int> A) {
		
		ZERO(O);
		ZERO(from);
		ZERO(to);
		
		int m1,m2,i;
		FORR(a,A) {
			memmove(from,to,sizeof(from));
			a%=9;
			
			FOR(m1,9) if(O[m1]) {
				to[(1<<m1)|(1<<a)][1<<((m1+a)%9)]=max(to[(1<<m1)|(1<<a)][1<<((m1+a)%9)],2);
			}
			FOR(m2,1<<9) {
				int left=(9-a)%9;
				if(m2&(1<<left)) continue;
				FOR(m1,1<<9) {
					int nm2=m2;
					FOR(i,9) if(m1&(1<<i)) nm2 |= 1<<((i+a)%9);
					
					to[m1|(1<<a)][nm2]=max(to[m1|(1<<a)][nm2],from[m1][m2]+1);
				}
			}
			O[a]++;
		}
		
		int ma=0;
		FOR(m1,1<<9) FOR(m2,1<<9) ma=max(ma,to[m1][m2]);
		if(ma<=2) ma=-1;
		return ma;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {6, 9, 5, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, maxSizeOf9Free(Arg0)); }
	void test_case_1() { int Arr0[] = {6, 9, 18, 3, 15, 12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, maxSizeOf9Free(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 10, 7, 19, 16, 28, 9, 46, 0, 37}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(2, Arg1, maxSizeOf9Free(Arg0)); }
	void test_case_3() { int Arr0[] = {3, 12, 30, 6, 21, 4, 15, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, maxSizeOf9Free(Arg0)); }
	void test_case_4() { int Arr0[] = {600308, 404694, 939932, 748673, 891293, 706905, 978182, 625631, 708003, 977632, 828206, 972547, 
184606, 929681, 237869, 610370, 559760, 939323, 272684, 162248, 168143, 753163, 302535, 153367, 
568583, 750868, 735416, 97724, 620300, 509987, 129310, 993312, 323413, 676205, 629534, 894380, 1791, 
499727, 751959, 456281}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 23; verify_case(4, Arg1, maxSizeOf9Free(Arg0)); }
	void test_case_5() { int Arr0[] = {12, 93, 48}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(5, Arg1, maxSizeOf9Free(Arg0)); }
	void test_case_6() { int Arr0[] = {993320, 112864, 892808, 821699, 227492, 901628, 467512, 142654, 810125}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(6, Arg1, maxSizeOf9Free(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Avoid9 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

