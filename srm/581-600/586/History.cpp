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
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

vector<int> split_int(const string &str, char delim){
	vector<int> res;
	size_t current = 0, found;
	while((found = str.find_first_of(delim, current)) != string::npos){
		string s = string(str, current, found - current);
		res.push_back(atoi(s.c_str()));
		current = found + 1;
	}
	string s = string(str, current, str.size() - current);
	res.push_back(atoi(s.c_str()));
	return res;
}
string concatvec(vector <string> expr) { return accumulate(expr.begin(),expr.end(),string("")); }


class History {
	public:
	int N;

	vector<int> D[51];
	int diff[26][26][2];
	
	void AddCons(int n1,int m1,int n2,int m2) {
		diff[n1][n2][0]=max(diff[n1][n2][0],D[n2][m2]-(D[n1][m1+1]-1));
		diff[n1][n2][1]=min(diff[n1][n2][1],D[n2][m2+1]-1-D[n1][m1]);
		diff[n2][n1][0]=max(diff[n2][n1][0],D[n1][m1]-(D[n2][m2+1]-1));
		diff[n2][n1][1]=min(diff[n2][n1][1],D[n1][m1+1]-1-D[n2][m2]);
	}
	
	string okok(int n1,int m1,int n2,int m2) {
		int d1=D[n2][m2]-(D[n1][m1+1]-1);
		int d2=D[n2][m2+1]-1-D[n1][m1];
		if(diff[n1][n2][1]<d1) return "N";
		if(diff[n1][n2][0]>d2) return "N";
		
		return "Y";
	}
	
	string verifyClaims(vector <string> dynasties, vector <string> battles, vector <string> queries) {
		int i,j,x,y,k;
		N=dynasties.size();
		FOR(i,N) {
			vector<int> VV=split_int(dynasties[i],' ');
			D[i].clear();
			FOR(j,VV.size()) D[i].push_back(VV[j]-VV[0]);
		}
		FOR(i,26) {
			FOR(j,26) diff[i][j][0]=-(1<<29),diff[i][j][1]=1<<29;
			diff[i][i][0]=diff[i][i][1]=0;
		}
		
		string B=concatvec(battles);
		for(i=0;i<B.size();i+=6) 
			AddCons(B[i]-'A',B[i+1]-'0',B[i+3]-'A',B[i+4]-'0');
		
		FOR(i,N) FOR(j,N) FOR(k,N) {
			diff[j][k][0]=max(diff[j][k][0], diff[j][i][0]+diff[i][k][0]);
			diff[j][k][1]=min(diff[j][k][1], diff[j][i][1]+diff[i][k][1]);
		}
		
		string r="";
		FOR(i,queries.size())
			r+=okok(queries[i][0]-'A',queries[i][1]-'0',queries[i][3]-'A',queries[i][4]-'0');
		return r;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 2 4",
 "1 2 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A1-B0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"A0-B0",
 "A0-B1",
 "A1-B0",
 "A1-B1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "NNYY"; verify_case(0, Arg3, verifyClaims(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"1000 2000 3000 10000",
 "600 650 2000",
 "1 1001 20001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"B1-C0 A0-B0 A2-C1 B1-C1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"A0-B1",
 "A1-B1",
 "A2-B1",
 "C0-A0",
 "B0-A2",
 "C1-B0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "YYYYNN"; verify_case(1, Arg3, verifyClaims(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"1 4 5",
 "10 13 17"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A0-B0 A0-B0 B0-A0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"A1-B0",
 "A0-B1",
 "A1-B1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "YYY"; verify_case(2, Arg3, verifyClaims(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"1 5 6",
 "1 2 5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A0",
 "-B0 A",
 "1-B1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"A0-B0",
 "A1-B0",
 "A0-B1",
 "A1-B1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "YNYY"; verify_case(3, Arg3, verifyClaims(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"2294 7344","366 384 449 965 1307 1415","307 473 648 688 1097","1145 1411 1569 2606","87 188 551 598 947 998 1917 1942"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A0-B4 B4-E2 B3-E2 D2-E4 A0-E4 B1-C3 A0-E3 A0-E6 D0","-E2 B2-E1 B4-E3 B4-D0 D0-E3 A0-D1 B2-C3 B1-C3 B4-E","3 D0-E1 B3-D0 B3-E2"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"A0-C2","E6-C2","A0-E4","B3-C1","C0-D2","B0-C1","D1-C3","C3-D0","C1-E3","D1-A0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "YNYNNYNNNY"; verify_case(4, Arg3, verifyClaims(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  History ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
