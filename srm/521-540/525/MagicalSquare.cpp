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

int ok[3][3][51][51][51];
class MagicalSquare {
	public:
	
	long long getCount(vector <string> RS, vector <string> CS) {
		ll ret=0;
		int x,y,a,b,l;
		if(RS[0].size()+RS[1].size()+RS[2].size() != CS[0].size()+CS[1].size()+CS[2].size()) return 0;
		ZERO(ok);
		FOR(x,3) FOR(y,3) {
			FOR(a,RS[x].size()+1) FOR(b,CS[y].size()+1) FOR(l,51) {
				if(a+l>RS[x].size()) break;
				if(b+l>CS[y].size()) break;
				ok[x][y][a][b][l]=(RS[x].substr(a,l)==CS[y].substr(b,l));
			}
		}
		
		int l00,l01,l10,l11;
		FOR(l00,RS[0].size()+1) for(l01=0;l01<=RS[0].size()-l00;l01++) {
			FOR(l10,RS[1].size()+1) for(l11=0;l11<=RS[1].size()-l10;l11++) {
				int l02=RS[0].size()-l00-l01;
				int l12=RS[1].size()-l10-l11;
				int l20=CS[0].size()-l00-l10;
				int l21=CS[1].size()-l01-l11;
				if(l20<0 || l21<0) continue;
				if(RS[2].size()-l20-l21 != CS[2].size()-l02-l12) continue;
				int l22=RS[2].size()-l20-l21;
				if(l22<0) continue;
				if(!ok[0][0][0][0][l00]) continue;
				if(!ok[1][0][0][l00][l10]) continue;
				if(!ok[2][0][0][l00+l10][l20]) continue;
				if(!ok[0][1][l00][0][l01]) continue;
				if(!ok[1][1][l10][l01][l11]) continue;
				if(!ok[2][1][l20][l01+l11][l21]) continue;
				if(!ok[0][2][l00+l01][0][l02]) continue;
				if(!ok[1][2][l10+l11][l02][l12]) continue;
				if(!ok[2][2][l20+l21][l02+l12][l22]) continue;
				ret++;
			}
		}
		return ret;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"f", "o", "x"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"f", "o", "x"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1LL; verify_case(0, Arg2, getCount(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"x", "x", "x"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"x", "", "xx"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 3LL; verify_case(1, Arg2, getCount(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"cd", "cd", "cd"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"dvd", "dvd", "dvd"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(2, Arg2, getCount(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"abab", "ab", "abab"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"abab", "ab", "abab"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 11LL; verify_case(3, Arg2, getCount(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"qwer", "asdf", "zxcv"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"qaz", "wsx", "erdfcv"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1LL; verify_case(4, Arg2, getCount(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MagicalSquare ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

