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

int isis[3200][3200];

class NonXorLife {
	public:
	int countAliveCells(vector <string> field, int K) {
		int i,x,y,d,res=0;
		ZERO(isis);
		set<pair<int,int> > nn;
		FOR(y,field.size()) FOR(x,field[y].size()) if(field[y][x]=='o')
			isis[y+1510][x+1510]=1,nn.insert(make_pair(y+1510,x+1510)),res++;
		
		FOR(i,K) {
			set<pair<int,int> > ne;
			ITR(it,nn) {
				FOR(d,4) {
					int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
					int tx=it->second+dx[d];
					int ty=it->first+dy[d];
					if(isis[ty][tx]==0) {
						res++;
						isis[ty][tx]=1;
						ne.insert(make_pair(ty,tx));
					}
				}
			}
			
			swap(nn,ne);
			ne.clear();
		}
		return res;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"oo"
,"o."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 36; verify_case(0, Arg2, countAliveCells(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {".."
,".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 23; int Arg2 = 0; verify_case(1, Arg2, countAliveCells(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"o"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 2002001; verify_case(2, Arg2, countAliveCells(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"o.oo.ooo"
,"o.o.o.oo"
,"ooo.oooo"
,"o.o..o.o"
,"o.o..o.o"
,"o..oooo."
,"..o.o.oo"
,"oo.ooo.o"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1234; int Arg2 = 3082590; verify_case(3, Arg2, countAliveCells(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  NonXorLife ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

