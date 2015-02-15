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

ll numf[19][180];
ll num[19][180];

class FoxAndSorting {
	public:
	
	string keta(int ke,int le, ll idx) {
		int d,i;
		
		if(le==0) {
			string s="";
			FOR(i,idx-1) s+='0';
			return s;
		}
		if(ke==0) {
			string s="";
			s+=le+'0';
			return s;
		}
		
		FOR(d,10) {
			if(ke==17 && d==0) continue;
			ll tot=(le==d);
			FOR(i,ke) tot+=num[i][le-d];
			
			if(idx<=tot) {
				string s="";
				s+='0'+d;
				return s + keta(ke-1, le-d, idx);
			}
			idx-=tot;
		}
		return "";
	}
	
	
	long long get(long long idx) {
		int x,y,d;
		if(idx==1) return 0;
		idx--;
		
		ZERO(num);
		ZERO(numf);
		FOR(d,9) numf[0][d+1]=1;
		FOR(d,10) num[0][d]=1;
		
		FOR(x,17) FOR(y,180) FOR(d,10) numf[x+1][y+d] += numf[x][y];
		FOR(x,17) FOR(y,180) FOR(d,10) num[x+1][y+d] += num[x][y];
		FOR(x,18) FOR(y,180) numf[18][y]+=numf[x][y];
		
		FOR(d,180) {
			if(idx<=numf[18][d]) return atoll(keta(17,d,idx).c_str());
			idx -=numf[18][d];
		}
		return 0;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 10LL; long long Arg1 = 100000000LL; verify_case(0, Arg1, get(Arg0)); }
	void test_case_1() { long long Arg0 = 1000000000000000000LL; long long Arg1 = 999999999999999999LL; verify_case(1, Arg1, get(Arg0)); }
	void test_case_2() { long long Arg0 = 58LL; long long Arg1 = 100000000100LL; verify_case(2, Arg1, get(Arg0)); }
	void test_case_3() { long long Arg0 = 314159265358979LL; long long Arg1 = 646003042230121105LL; verify_case(3, Arg1, get(Arg0)); }
	void test_case_42() { long long Arg0 = 271828182845904523LL; long long Arg1 = 132558071125756493LL; verify_case(4, Arg1, get(Arg0)); }
	void test_case_4() { long long Arg0 = 1000000000000000000LL; long long Arg1 = 132558071125756493LL; verify_case(4, Arg1, get(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FoxAndSorting ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

