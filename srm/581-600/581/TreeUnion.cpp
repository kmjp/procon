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


class TreeUnion {
	int T,K;
	int dist[2][302][302];
	ll dd[2][5];
	public:
	string concatvec(vector <string> expr) { return accumulate(expr.begin(),expr.end(),string("")); }
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
	
	double expectedCycles(vector <string> tree1, vector <string> tree2, int K) {
		int i,j,k,x,y,z,z2;
		
		vector<int> t1=split_int(concatvec(tree1),' ');
		vector<int> t2=split_int(concatvec(tree2),' ');
		T=t1.size()+1;
		FOR(x,T) FOR(y,T) dist[0][x][y]=100;
		FOR(x,T) FOR(y,T) dist[1][x][y]=100;
		FOR(x,T) dist[0][x][x]=dist[1][x][x]=0;
		FOR(i,t1.size()) dist[0][i+1][t1[i]]=dist[0][t1[i]][i+1]=1;
		FOR(i,t2.size()) dist[1][i+1][t2[i]]=dist[1][t2[i]][i+1]=1;
		
		FOR(i,T) FOR(j,T) FOR(k,T) dist[0][j][k] = min(dist[0][j][k], dist[0][j][i]+dist[0][i][k]);
		FOR(i,T) FOR(j,T) FOR(k,T) dist[1][j][k] = min(dist[1][j][k], dist[1][j][i]+dist[1][i][k]);
		
		ZERO(dd);
		FOR(i,2) FOR(x,T) for(y=x+1;y<T;y++) {
			if(dist[i][x][y]<5) dd[i][dist[i][x][y]]++;
		}
		
		double res=0;
		for(x=1;x<=4;x++) {
			y=K-2-x;
			if(0<y && y<5) {
				res += 2*dd[0][x]*dd[1][y];
			}
		}
		
		res /= T*(T-1);
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; double Arg3 = 1.0; verify_case(0, Arg3, expectedCycles(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"0 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; double Arg3 = 1.3333333333333333; verify_case(1, Arg3, expectedCycles(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"0 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; double Arg3 = 0.3333333333333333; verify_case(2, Arg3, expectedCycles(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"0 ", "1 1 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1 0 ", "1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; double Arg3 = 4.0; verify_case(3, Arg3, expectedCycles(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"0 1 2 0 1 2 0 1 2 5 6 1", "0 11", " 4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1 1 0 2 3 4 3 4 6 6", " 10 12 12"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; double Arg3 = 13.314285714285713; verify_case(4, Arg3, expectedCycles(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  TreeUnion ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
