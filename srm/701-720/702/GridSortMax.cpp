#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class GridSortMax {
	public:
	int A[51][51];
	int R[51*51];
	int H,W;
	int NGR[51],NGC[51];
	
	string findMax(int n, int m, vector <int> grid) {
		int y,x,y2,x2;
		H=n;
		W=m;
		
		ZERO(NGR);
		ZERO(NGC);
		
		FOR(y,H) FOR(x,W) A[y][x]=grid[y*W+x]-1, R[grid[y*W+x]-1]=y*100+x;
		
		FOR(y,H) FOR(x,W) {
			int cy=R[y*W+x]/100;
			int cx=R[y*W+x]%100;
			int ng=0;
			if(y!=cy && (NGR[y]||NGR[cy])) continue;
			if(x!=cx && (NGC[x]||NGC[cx])) continue;
			
			FOR(x2,W) {
				swap(A[y][x2],A[cy][x2]);
				R[A[y][x2]]=y*100+x2;
				R[A[cy][x2]]=cy*100+x2;
			}
			FOR(y2,H) {
				swap(A[y2][x],A[y2][cx]);
				R[A[y2][x]]=y2*100+x;
				R[A[y2][cx]]=y2*100+cx;
			}
			
			NGR[y]=NGC[x]=1;
		}
		
		string S;
		FOR(y,H) FOR(x,W) S+=(A[y][x]==y*W+x)+'0';
		return S;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {
 1,2,
 3,4
}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "1111"; verify_case(0, Arg3, findMax(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {
 2,1,
 3,4
}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "1100"; verify_case(1, Arg3, findMax(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {
 4,2,
 3,1
}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "1001"; verify_case(2, Arg3, findMax(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 10; int Arr2[] = {10,6,2,3,5,7,1,9,4,8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "1111111111"; verify_case(3, Arg3, findMax(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 3; int Arg1 = 5; int Arr2[] = {
 5,2,10,7,9,
 3,4,14,11,1,
 15,12,6,8,13
}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "101100100100000"; verify_case(4, Arg3, findMax(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 6; int Arg1 = 2; int Arr2[] = {
 3,9,
 5,1,
 10,6,
 2,7,
 8,11,
 12,4
}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "100000101010"; verify_case(5, Arg3, findMax(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  GridSortMax ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

