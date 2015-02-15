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

class SkewedPerspectives {
	vector <int> C;
	int B,W;
	public:
	
	int okok(string req) {
		int CB=B;
		int h=0;
		int w=0;
		int i,x,y;
		vector<int> C2=C;
		vector<int> yo;
		
		FOR(i,req.size()) {
			if(req[i]!='b') {
				h++;
				if(C2[req[i]-'0']--==0) return 0;
			}
			else {
				int numb=0;
				while(i<req.size() && req[i]=='b') numb++,i++;
				i--;
				if(numb%2) {
					if(h==0) {
						if(numb==1) return 0;
						CB--;
						h=2;
						numb-=2;
					}
					yo.push_back(h-1);
					h+=numb;
					CB-=(1+numb)/2;
					if(CB<0) return 0;
					if(++w>=W) return 0;
				}
				else {
					h+=numb;
					CB-=numb/2;
					if(CB<0) return 0;
				}
			}
		}
		int NC=C2[0]+C2[1]+C2[2];
		FOR(i,yo.size()) {
			while(yo[i]>=2 && CB) CB--,yo[i]-=2;
			while(yo[i]>=1 && NC) NC--,yo[i]-=1;
			if(yo[i]) return 0;
		}
		return 1;
		
	}
	
	vector <string> areTheyPossible(vector <int> cubes, int B, int w, vector <string> views) {
		vector<string> R;
		int i;
		C=cubes;
		this->B=B;
		W=w;
		
		FOR(i,views.size()) {
			if(okok(views[i])) R.push_back("valid");
			else R.push_back("invalid");
		}
		return R;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; string Arr3[] = { "012", "012bb", "bb0", "21bb", "21b", "1bb20" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"valid", "valid", "valid", "valid", "valid", "valid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; string Arr3[] = {"b","bb","bbb","bbbb","bbbbb","bbbbbb",
 "1", "1b","1bb","1bbb","1bbbb","1bbbbb","1bbbbbb",
 "b1","b1b","b1bb","b1bbb","b1bbbb","b1bbbbb",
 "bb1","bb1b","bb1bb","bb1bbb","bb1bbbb",
 "bbb1","bbb1b","bbb1bb","bbb1bbb",
 "bbbb1","bbbb1b","bbbb1bb",
 "bbbbb1","bbbbb1b",
 "bbbbbb1" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"invalid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "invalid", "invalid", "invalid", "invalid", "invalid", "invalid", "valid", "valid", "valid", "invalid", "valid", "invalid", "invalid", "invalid", "invalid", "valid", "invalid", "valid", "invalid", "invalid", "valid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {100,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; int Arg2 = 3; string Arr3[] = {"00000000000000000000000000000000000000000000000000",
 "00000000000000000000000000000000000b00000000000000",
 "0000000000000000000000000000000000000000000000000b",
 "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb0000000000000"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"valid", "valid", "valid", "valid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {5,6,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; string Arr3[] = {"00000111111222", "0000111111222", "0000011111222", "000001111111222", "0000011111122", "b"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"valid", "valid", "valid", "invalid", "valid", "invalid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {100,100,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 50; string Arr3[] = {"2",
 "bb1b012012012012012012012",
 "bb1b012012012012012012012b",
 "bb1b012012012b012b012b012012b",
 "bb1b0b1b2b0b1b2b0b1b2bb012b012b012012b",
 "b1b0b1b2b0b1b2b0b1b2bb012b012b012012b",
 "bbb1b012012012012012012012"
}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"valid", "valid", "valid", "valid", "valid", "invalid", "valid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(4, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; string Arr3[] = {"0", "bb"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"invalid", "invalid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(5, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arr0[] = {3,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 3; string Arr3[] = {"00b0b", "bbbbbbbb", "000b"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"invalid", "valid", "valid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(6, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SkewedPerspectives ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

