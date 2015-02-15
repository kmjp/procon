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


class CirclesGame {
	int ins[52][52];
	int parent[52],memo[52];
	int N;
	vector <int> X,Y,R;
	public:
	int INS(int a,int b) {
		if(a==b) return 0;
		ll dist = ((ll)(X[a]-X[b]))*((ll)(X[a]-X[b]))+((ll)(Y[a]-Y[b]))*((ll)(Y[a]-Y[b]));
		if(sqrt(dist)+R[b] <= R[a]+EPS) return 1;
		return 0;
		
	}
	
	int getnim(int cur) {
		if(memo[cur]==-1) {
			int del, nims[50000];
			ZERO(nims);
			FOR(del,N) {
				if(ins[cur][del]==0 && cur != del) continue;
				int tnim=0;
				// del‚¨‚æ‚Ñ‚»‚Ìedcur‚ÉŠÜ‚Ü‚ê‚È‚¢root‚Ìnim‚ðŽæ‚é
				int dcur = del;
				while(1) {
					int left;
					FOR(left,N) if(parent[left]==dcur && !ins[left][del] && left!=del) tnim ^= getnim(left);
					//_P("OK%d %d %d %d\n",cur,del,dcur,tnim);
					if(dcur==cur) break;
					dcur=parent[dcur];
				}
				nims[tnim]++;
				//_P("%d %d %d\n",cur,del,tnim);
			}
			memo[cur]=0;
			while(nims[memo[cur]]) memo[cur]++;
			//_P("%d %d\n",cur,memo[cur]);
		}
		return memo[cur];
	}
	
	string whoCanWin(vector <int> x, vector <int> y, vector <int> r) {
		X=x;Y=y;R=r;
		N=x.size();
		int a,b,c,d;
		
		FOR(a,N) FOR(b,N) ins[a][b]=INS(a,b);
		FOR(a,N) {
			parent[a]=-1;
			memo[a]=-1;
			FOR(b,N) if(ins[b][a]) {
				int ok=1;
				FOR(c,N) if(ins[b][c] && ins[c][a]) ok=0;
				if(ok) parent[a]=b;
			}
		}
		
		int nim=0;
		FOR(a,N) if(parent[a]==-1) nim ^= getnim(a);
		
		
		return (nim==0)?"Bob":"Alice";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Alice"; verify_case(0, Arg3, whoCanWin(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Bob"; verify_case(1, Arg3, whoCanWin(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0, 0, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Alice"; verify_case(2, Arg3, whoCanWin(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0, 0, 0, 10, 10, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 0, 0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3, 1, 2, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Bob"; verify_case(3, Arg3, whoCanWin(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {10,20,30,40,50,60,70,80}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8,7,6,5,4,3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,2,2,2,2,2,2,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Bob"; verify_case(4, Arg3, whoCanWin(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {0, 3, 6, 9, 12, -4747, -4777}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-5858, -5858, -5858, -5858, -5858, 777, 777}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {58, 1, 1, 1, 1, 44, 8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Bob"; verify_case(5, Arg3, whoCanWin(Arg0, Arg1, Arg2)); }
	void test_case_7() { int Arr0[] = {5202, 5699, -7433, 5068, -9483, -684, -6593, 5108, -7813, 6823, 3267, -8222, -8547, 2878, 2413, 8557, 5149, 5073, -8638, -6108, 8097}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8728, -7407, 4338, -8414, 7652, -3705, -984, 5976, -9180, -9119, 9301, 2398, 7915, 6205, 7665, 717, -9884, 11, -8579, -6903, -746}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4196, 9303, 7152, 5875, 2943, 788, 502, 416, 1958, 3174, 182, 1256, 1147, 444, 979, 65, 1040, 1233, 438, 175, 1140}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Alice"; verify_case(6, Arg3, whoCanWin(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arr0[] = {-8367, -2791, 7264, -4844, 1780, 9459, 3488, -2596, -3653, -4771, 7495, 8684, 5364, 2075, 8699, -2383, -9217, -9456, -4538, 3752, 9326, -3817, -5153, -8123, -8392, -2988, 4885, -5774, -1095, -8277, 6301, -4203, -8122, -7929, -5232, -134, 9211, 5344, -8261, -5956}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-9111, 6563, 2927, -7507, -9056, -7606, 4655, 3087, 5337, 9142, -7370, 9663, 9241, 9577, -5467, -2734, 7447, -7269, 8464, -2751, 5609, -2470, -8629, 3561, 9445, 6549, -7131, 2033, 7958, 2704, 6470, 3071, -5793, 4716, -8330, -1020, 9773, 4433, -2868, -1991}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7751, 4235, 1626, 3438, 1892, 2570, 1001, 30, 2732, 8387, 223, 428, 1416, 1285, 4953, 295, 362, 608, 517, 497, 884, 136, 1590, 152, 1155, 379, 25, 531, 130, 469, 1199, 69, 74, 436, 922, 165, 1074, 672, 266, 180}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Alice"; verify_case(6, Arg3, whoCanWin(Arg0, Arg1, Arg2)); }

// END CUT HERE
};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  CirclesGame ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
