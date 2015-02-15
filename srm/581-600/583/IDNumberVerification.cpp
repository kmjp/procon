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

#define DEBUG
#ifdef DEBUG
#define DBG(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define DV(...) cerr << __VA_ARGS__ << endl
#else
#define DBG(...)
#define DV(...)
#endif

typedef signed long long ll;
typedef unsigned long long ull;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------


class IDNumberVerification {
	public:
	int validdate(int y,int m,int d) {
		int md[12]={31,28,31,30,31,30,31,31,30,31,30,31};
		
		if(y<1900 || y>2011) return 0;
		if(m<1 || m>12) return 0;
		if((y%400==0) || ((y%100!=0) && (y%4==0))) md[1]++;
		if(d<1 || d>md[m-1]) return 0;
		return 1;
	}
	
	string verify(string id, vector <string> regionCodes) {
		int i;
		
		FOR(i,regionCodes.size()) if(id.substr(0,6)==regionCodes[i]) break;
		if(i==regionCodes.size()) return "Invalid";
		int y=(id[6]-'0')*1000+(id[7]-'0')*100+(id[8]-'0')*10+(id[9]-'0');
		int m=(id[10]-'0')*10+(id[11]-'0');
		int d=(id[12]-'0')*10+(id[13]-'0');
		if(!validdate(y,m,d)) return "Invalid";
		if(id.substr(14,3)=="000") return "Invalid";
		int c=(id[17]=='X')?10:(id[17]-'0');
		FOR(i,17) c+=(id[i]-'0')<<(17-i);
		if(c%11!=1) return "Invalid";
		if((id[16]-'0')%2) return "Male";
		return "Female";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "441323200312060636"; string Arr1[] = {"441323"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Male"; verify_case(0, Arg2, verify(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "62012319240507058X"; string Arr1[] = {"620123"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Female"; verify_case(1, Arg2, verify(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "321669197204300886"; string Arr1[] = {"610111","659004"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Invalid"; verify_case(2, Arg2, verify(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "230231198306900162"; string Arr1[] = {"230231"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Invalid"; verify_case(3, Arg2, verify(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "341400198407260005"; string Arr1[] = {"341400"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Invalid"; verify_case(4, Arg2, verify(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "520381193206090891"; string Arr1[] = {"532922","520381"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Invalid"; verify_case(5, Arg2, verify(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  IDNumberVerification ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
