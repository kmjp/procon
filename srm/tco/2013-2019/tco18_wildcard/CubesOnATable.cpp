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


class CubesOnATable {
	public:
	void push(vector<int>& v,int x,int y,int z) {
		v.push_back(x);
		v.push_back(y);
		v.push_back(z);
	}
	vector <int> placeCubes(int surface) {
		vector<int> ret,empty;
		
		if(surface<5 || surface==6 || surface==7) return empty;
		push(ret,0,0,0);
		if(surface%4==1) {
			surface-=5;
		}
		else if(surface%4==0) {
			push(ret,1,0,0);
			surface-=8;
		}
		else if(surface%4==2) {
			push(ret,1,1,0);
			surface-=10;
		}
		else if(surface%4==3) {
			push(ret,1,0,0);
			push(ret,2,0,0);
			surface-=11;
		}
		int nex=1;
		while(surface) {
			push(ret,0,0,nex++);
			surface-=4;
		}
		
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {0, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, placeCubes(Arg0)); }
	void test_case_1() { int Arg0 = 20; int Arr1[] = {5, 5, 0, 5, 5, 1, 5, 6, 0, 5, 6, 1, 6, 5, 0, 6, 5, 1, 6, 6, 0, 6, 6, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, placeCubes(Arg0)); }
	void test_case_2() { int Arg0 = 25; int Arr1[] = {0, 0, 0, 2, 2, 0, 4, 4, 0, 6, 6, 0, 8, 8, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, placeCubes(Arg0)); }
	void test_case_3() { int Arg0 = 32; int Arr1[] = {1, 3, 0, 2, 3, 0, 2, 3, 1, 3, 3, 0, 3, 3, 1, 3, 3, 2, 4, 3, 0, 4, 3, 1, 4, 3, 2, 4, 3, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, placeCubes(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CubesOnATable ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

