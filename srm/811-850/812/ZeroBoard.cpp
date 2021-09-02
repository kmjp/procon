#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int A[202][202];

class ZeroBoard {
	public:
	vector<int> ret;
	void down(int y,int x,int v) {
		ret.push_back(y);
		ret.push_back(x);
		ret.push_back(0);
		ret.push_back(v);
		A[y][x]+=v;
		A[y+1][x]+=v;
	}
	void right(int y,int x,int v) {
		ret.push_back(y);
		ret.push_back(x);
		ret.push_back(1);
		ret.push_back(v);
		A[y][x]+=v;
		A[y][x+1]+=v;
	}
	
	vector <int> solve(int R, int C, vector <int> data) {
		int y,x;
		ll sum=0;
		FOR(y,R) FOR(x,C) {
			A[y][x]=data[y*C+x];
			if((y+x)%2) sum+=A[y][x];
			else sum-=A[y][x];
		}
		if(sum) return {-1};
		ret.clear();
		FOR(y,R) FOR(x,C) if(A[y][x]) {
			if(y+1<R&&A[y][x]<=A[y+1][x]) down(y,x,-A[y][x]);
			else if(x+1<C&&A[y][x]<=A[y][x+1]) right(y,x,-A[y][x]);
			else if(x+2<C) {
				int dif=A[y][x]-A[y][x+1];
				right(y,x+1,dif);
				right(y,x,-A[y][x]);
			}
			else if(y+2<R) {
				int dif=A[y][x]-A[y+1][x];
				down(y+1,x,dif);
				down(y,x,-A[y][x]);
			}
			else if(y+1<R&&x+1<C) {
				int dif=A[y][x]-A[y+1][x];
				right(y+1,x,dif);
				down(y,x,-A[y][x]);
			}
		}
		if(A[R-1][C-1]) {
			if(R>=2&&A[R-1][C-1]==A[R-2][C-1]) {
				down(R-2,C-1,-A[R-1][C-1]);
			}
			else if(C>=2&&A[R-1][C-1]==A[R-1][C-2]) {
				right(R-1,C-2,-A[R-1][C-1]);
			}
			else {
				assert(0);
			}
		}
		
		
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 4; int Arr2[] = {0, 0, 0, 0,
 0, 0, 0, 0, 
 0, 0, 0, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 4; int Arr2[] = {1, 2, 1, 0,
 0, 4, 6, 0,
 0, 0, 2, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 0, 1, -1, 0, 1, 0, -1, 1, 1, 1, -3, 0, 2, 0, -1, 1, 2, 0, -2 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 2; int Arr2[] = {4, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_3_() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {1, 2,
 0, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 0, 1, 1, 0, 0, 0, -1, 0, 1, 0, -2 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 18; int Arg1 = 7; int Arr2[] = {415, 413, 406, 424, 397, 407, 384, 437, 406, 393, 413, 420, 366, 388, 384, 397, 405, 396, 355, 398, 415, 374, 408, 377, 396, 382, 399, 406, 420, 415, 376, 431, 395, 392, 399, 408, 453, 433, 431, 393, 417, 399, 389, 384, 391, 417, 397, 427, 398, 396, 401, 384, 404, 400, 378, 400, 411, 450, 386, 411, 420, 398, 374, 385, 410, 394, 402, 432, 416, 398, 398, 383, 371, 398, 391, 374, 396, 366, 387, 374, 395, 410, 422, 403, 384, 374, 408, 373, 373, 359, 394, 407, 427, 370, 412, 401, 393, 380, 409, 381, 422, 393, 427, 385, 434, 417, 407, 433, 422, 406, 383, 373, 411, 430, 402, 421, 412, 403, 403, 420, 402, 406, 380, 454, 387, 416}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 0, 1, 1, 0, 0, 0, -1, 0, 1, 0, -2 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, solve(Arg0, Arg1, Arg2)); }




// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ZeroBoard ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

