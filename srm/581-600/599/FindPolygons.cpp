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

vector<pair<int,int> > A[2502];
int mat[2501][2501];

class FindPolygons {
	public:
	
	void setup(int L) {
		int i,x,y;
		
		for(x=1;x<=1+L/2;x++) A[x].clear();
		for(x=1;x<=1+L/2;x++) {
			for(y=1;y<=1+L/2;y++) {
				double z = sqrt(x*x+y*y+1e-9);
				if(z>L/2+1) break;
				if(x*x+y*y == (int)z*(int)z) {
					A[(int)z].push_back(make_pair(x,y));
					mat[x][y]=(int)z;
				}
			}
		}
		for(x=1;x<=1+L/2;x++) {
			A[x].push_back(make_pair(0,x));
			A[x].push_back(make_pair(x,0));
			mat[0][x]=x;
			mat[x][0]=x;
		}
	}
	
	int okok(int x,int y,int z) {
		return x*x+y*y==z*z;
	}
	
	int check3(int L) {
		int re=9999999;
		int x,y,z,ma,x2,y2;
		for(x=1;x<=L/2;x++) {
			for(y=x;y<=L/2;y++) {
				z=L-x-y;
				if(z>=x+y || z<=0) continue;
				ma=max(max(abs(x-y),abs(y-z)),abs(z-x));
				if(ma>=re) continue;
				FOR(x2,A[x].size()) FOR(y2,A[y].size()) {
					int ax=A[x][x2].first;
					int ay=A[x][x2].second;
					int bx=A[y][y2].first;
					int by=A[y][y2].second;
					if(ax*by==ay*bx) {
						if((okok(ax-bx,ay+by,z) && ay+by!=0) ||
						   (okok(ax+bx,ay-by,z) && ax+bx!=0)) {
							re=ma;
							goto ne;
						}
					}
					else {
						if(okok(ax+bx,ay+by,z) || okok(ax+bx,ay-by,z) || okok(ax-bx,ay+by,z) || okok(ax-bx,ay-by,z)) {
							re=ma;
							goto ne;
						}
					}
				}
			}
			ne:
			;
		}
		return re;
	}
	
	double minimumPolygon(int L) {
		int re;
		if(L<=3) return -1;
		
		setup(L);
		
		re=check3(L);
		if(re<L) return re;
		if(L%2==0) return L%4!=0;
		return -1;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; double Arg1 = 0.0; verify_case(0, Arg1, minimumPolygon(Arg0)); }
	void test_case_1() { int Arg0 = 5; double Arg1 = -1.0; verify_case(1, Arg1, minimumPolygon(Arg0)); }
	void test_case_2() { int Arg0 = 12; double Arg1 = 2.0; verify_case(2, Arg1, minimumPolygon(Arg0)); }
	void test_case_3() { int Arg0 = 4984; double Arg1 = 819.0; verify_case(3, Arg1, minimumPolygon(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FindPolygons ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

