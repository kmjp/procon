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

int from[20][20];
int to[20][20];

class TheSquareCityDiv2 {
	public:
	vector <int> find(int r, vector <int> t) {
		int N=0;
		while((N+1)*(N+1) <= t.size()) N++;
		int x,y,i,y2,x2;
		FOR(y,N) FOR(x,N) from[y][x]=1;
		
		while(1) {
			int up=0;
			ZERO(to);
			FOR(y,N) FOR(x,N) if(from[y][x]) {
				int by=y,bx=x;
				FOR(y2,N) FOR(x2,N) if(abs(y2-y)+abs(x2-x)<=r) {
					if(t[y2*N+x2]>t[by*N+bx]) by=y2, bx=x2;
				}
				if(by!=y || bx!=x) up=1;
				to[by][bx] += from[y][x];
			}
			swap(from,to);
			if(up==0) break;
			
		}
		
		int house=0;
		int cnt=0;
		FOR(y,N) FOR(x,N) {
			if(from[y][x]) house++;
			cnt=max(cnt,from[y][x]);
		}
		return {house,cnt};
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 1; int Arr1[] = {
9, 1, 6, 
5, 3, 2, 
7, 4, 8
}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4, 4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {
9, 1, 6, 
5, 3, 2, 
7, 4, 8
}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 7; int Arr1[] = {
9, 1, 6, 
5, 3, 2, 
7, 4, 8
}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 9 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; int Arr1[] = {
59, 22,  2, 17, 77, 43, 67, 
16, 49, 51, 46, 61,  4,  9, 
42, 12, 80, 82, 24, 29,  1, 
27, 63, 65, 26, 10, 28, 83, 
 7, 73,  8, 47, 37, 23, 38, 
75, 54, 71, 58, 78, 21, 45, 
35, 81, 48, 41, 44, 52, 32
}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5, 20 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TheSquareCityDiv2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

