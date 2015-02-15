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

ll mo=1000000007;

class RowsOrdering {
	public:
	int H,W;
	ll p50[51];
	int order(vector <string> rows) {
		H=rows.size();
		W=rows[0].size();
		int x,y,j,i;
		
		p50[0]=1;
		FOR(x,50) p50[x+1]=p50[x]*50%mo;
		ll ret=H;
		
		int num2[55];
		ZERO(num2);
		
		FOR(x,W) {
			int num[55];
			ZERO(num);
			FOR(y,H) {
				if(rows[y][x]>='a' && rows[y][x]<='z') num[rows[y][x]-'a']++;
				if(rows[y][x]>='A' && rows[y][x]<='Z') num[rows[y][x]-'A'+26]++;
			}
			sort(num,num+51);
			reverse(num,num+51);
			num2[x]=0;
			FOR(i,51) num2[x]+=i*num[i];
		}
		
		sort(num2,num2+W);
		reverse(num2,num2+W);
		FOR(x,W) ret=(ret+num2[x]*p50[x])%mo;
		
		return (int)ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"bb", "cb", "ca"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 54; verify_case(0, Arg1, order(Arg0)); }
	void test_case_1() { string Arr0[] = {"abcd", "ABCD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 127553; verify_case(1, Arg1, order(Arg0)); }
	void test_case_2() { string Arr0[] = {"Example", "Problem"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 943877448; verify_case(2, Arg1, order(Arg0)); }
	void test_case_3() { string Arr0[] = {"a", "b", "c", "d", "e", "f", "g"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 28; verify_case(3, Arg1, order(Arg0)); }
	void test_case_4() { string Arr0[] = {"a", "a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, order(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RowsOrdering ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

