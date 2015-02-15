#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef signed long long ll;
typedef unsigned long long ull;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(x) x.begin(),x.end()
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

class FarStrings {
	public:
	
	pair<int,int> dist(string A,string B,int bl) {
		int al=A.size();
		int dp[51][51],dp2[51][51],x,y;
		FOR(x,51) FOR(y,51) dp[x][y]=dp2[x][y]=10000;
		dp[0][0]=dp2[0][0]=0;
		
		FOR(x,al+1) FOR(y,al+1) {
			if(x<al) dp[x+1][y]=min(dp[x+1][y],dp[x][y]+1), dp2[x+1][y]=min(dp2[x+1][y],dp2[x][y]+1);
			if(y<al) dp[x][y+1]=min(dp[x][y+1],dp[x][y]+1), dp2[x][y+1]=min(dp2[x][y+1],dp2[x][y]+1);
			if(x<al) {
				if(y<bl) {
					dp[x+1][y+1]=min(dp[x+1][y+1],dp[x][y]+(A[x]!=B[y]));
					dp2[x+1][y+1]=min(dp2[x+1][y+1],dp2[x][y]+(A[x]!=B[y]));
				}
				else if(y<al) {
					dp[x+1][y+1]=min(dp[x+1][y+1],dp[x][y]);
					dp2[x+1][y+1]=min(dp2[x+1][y+1],dp2[x][y]+1);
				}
			}
		}
		
		return pair<int,int>(make_pair(dp[al][al],dp2[al][al]));
	}
	
	vector <string> find(string t) {
		int ss=t.size(),i,j;
		vector<string> S;
		
		FOR(i,ss) {
			string h=string(ss,'*');
			FOR(j,ss) {
				for(h[j]='a';h[j]<='z';h[j]++) {
					pair<int,int> p=dist(t,h,j+1);
					if(p.first<=i+1 && i+1<=p.second) break;
				}
			}
			S.push_back(h);
		}
		return S;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "atan"; string Arr1[] = {"aaan", "aaaa", "aaba", "babb" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { string Arg0 = "ir"; string Arr1[] = {"ar", "aa" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { string Arg0 = "aaa"; string Arr1[] = {"aab", "abb", "bbb" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { string Arg0 = "bazinga"; string Arr1[] = {"aazinga", "aaainga", "aaaanga", "aaaaaga", "aaaaaaa", "aaaaaab", "abbaabb" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, find(Arg0)); }
	void test_case_4() { string Arg0 = "bcdab"; string Arr1[] = {"acdab", "aadab", "aaaab", "aaaaa", "aaaca" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, find(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FarStrings ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

