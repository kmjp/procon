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

string S;
int NS[2][2600],L;
ll nb[2600],nc[2600],sum[2600],sum2[2600];

class LittleElephantAndRGB {
	
	public:
	long long getNumber(vector <string> list, int minGreen) {
		ll a,b,c,d,x,y,ret=0;
		int i,j;
		
		S="";
		FOR(i,list.size()) S+=list[i];
		L=S.size();
		ZERO(NS);
		
		FOR(i,L) if(S[i]=='G') NS[0][i]=1+((i==0)?0:NS[0][i-1]);
		for(i=L-1;i>=0;i--) if(S[i]=='G') NS[1][i]=1+((i==L-1)?0:NS[1][i+1]);
		
		ZERO(nb);ZERO(nc);
		x=-1;
		y=L;
		for(b=0;b<L;b++) {
			a=b-(minGreen-1);
			if(a>=0 && NS[1][a]>=minGreen) x=a;
			nb[b]=x;
		}
		for(c=L-1;c>=0;c--) {
			d=c+(minGreen-1);
			if(d<L && NS[0][d]>=minGreen) y=d;
			nc[c]=y;
		}
		
		FOR(b,L) {
			ZERO(sum);
			ZERO(sum2);
			for(i=min(minGreen-1,NS[0][b]);i>=1;i--) sum[i] = sum[i+1] + ((NS[0][b]==i)?(b-nb[b]-i+1):1);
			for(i=1;i<=minGreen-1;i++) sum2[i] = sum2[i-1]+sum[minGreen-i];
			
			for(c=b+1;c<L;c++) {
				// include GGG in either side
				ret += (nb[b]+1)*(L-minGreen-c+1) + (b+1)*(L-nc[c]) - (nb[b]+1)*((L-minGreen)-nc[c]+1); 
				if(S[b]!='G' || S[c]!='G') continue;
				
				if(NS[1][c]<=minGreen) ret += (nc[c]-c-NS[1][c]+1)*sum[minGreen-NS[1][c]] + sum2[NS[1][c]-1];
				else ret += sum2[minGreen-1];
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
	void test_case_0() { string Arr0[] = {"GRG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; long long Arg2 = 1LL; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"GG", "GG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; long long Arg2 = 9LL; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"GRBGRBBRG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; long long Arg2 = 11LL; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"RRBRBBRRR", "R", "B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; long long Arg2 = 0LL; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"GRGGGRBRGG", "GGGGGGGG", "BRGRBRB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; long long Arg2 = 12430LL; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LittleElephantAndRGB ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

