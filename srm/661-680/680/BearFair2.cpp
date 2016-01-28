#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int from[26][26][26];
int to[26][26][26];
int must[1010];

class BearFair2 {
	public:
	string isFair(int n, int b, vector <int> upTo, vector <int> quantity) {
		int i;
		MINUS(must);
		FOR(i,upTo.size()) {
			if(must[upTo[i]]!=-1 && n-quantity[i]!=must[upTo[i]]) return "unfair";
			must[upTo[i]] = n-quantity[i];
		}
		
		ZERO(from);
		from[n/3][n/3][n/3]=1;
		for(i=1;i<=b;i++) {
			ZERO(to);
			int m0,m1,m2;
			FOR(m0,n/3+1) FOR(m1,n/3+1) FOR(m2,n/3+1) if(from[m0][m1][m2]) {
				// nottake
				to[m0][m1][m2] = 1;
				if(i%3==0 && m0) to[m0-1][m1][m2]=1;
				if(i%3==1 && m1) to[m0][m1-1][m2]=1;
				if(i%3==2 && m2) to[m0][m1][m2-1]=1;
			}
			if(must[i]!=-1) {
				FOR(m0,n/3+1) FOR(m1,n/3+1) FOR(m2,n/3+1) if(m0+m1+m2!=must[i]) to[m0][m1][m2]=0;
			}
			swap(from,to);
		}
		if(from[0][0][0]) return "fair";
		else return "unfair";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 5; int Arr2[] = {2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "fair"; verify_case(0, Arg4, isFair(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 1000; int Arr2[] = {500,100,950}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4,3,6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "fair"; verify_case(1, Arg4, isFair(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 20; int Arr2[] = {5,19,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,3,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "unfair"; verify_case(2, Arg4, isFair(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 6; int Arr2[] = {1,2,3,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "unfair"; verify_case(3, Arg4, isFair(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 48; int Arg1 = 1000; int Arr2[] = {38,450,202,685,971,661,946,226,901,353,12,937,655,108,31,908,845,908,981,896,296,987,77,790,679,
152,412,492,286,54,214,651,59,189,107,445,728,327,438,523,527,663,825,67,523,400,65,892,587,995}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,19,8,32,48,31,48,8,43,13,0,46,30,8,1,45,42,45,48,43,13,48,6,40,32,8,17,20,13,3,8,30,3,8,8,19,
37,13,19,21,21,31,41,4,21,16,4,43,23,48}
; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "fair"; verify_case(4, Arg4, isFair(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 3; int Arg1 = 100; int Arr2[] = {40,60}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "unfair"; verify_case(5, Arg4, isFair(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BearFair2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
