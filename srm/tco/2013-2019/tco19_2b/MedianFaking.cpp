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

class MedianFaking {
	public:
	vector <int> minimize(int F, int M, vector <int> data, int goal) {
		int C[3]={};
		int N=F*M;
		FORR(d,data) {
			if(d<goal) d=0;
			else if(d>goal) d=2;
			else d=1;
			C[d]++;
		}
		
		int target,del;
		int x,y;
		vector<int> V;
		if(C[0]>=(N+1)/2) {
			target=0;
			del=C[0]-(N+1)/2+1;
			
		}
		else if(C[2]>=N/2+1) {
			target=2;
			del=C[2]-(N/2+1)+1;
		}
		else {
			return {0,0};
		}
		
		FOR(x,F) {
			int sum=0;
			FOR(y,M) if(data[x*M+y]==target) sum++;
			V.push_back(sum);
		}
		sort(ALL(V));
		reverse(ALL(V));
		
		int lef=0;
		FOR(x,F) {
			lef+=V[x];
			if(lef>=del) return {x+1,del};
		}
		
		return {};
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 5; int Arr2[] = {1,2,3,4,5, 10,9,8,7,6, 25,24,23,22,21, 18,16,17,19,20, 11,13,12,14,15}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; int Arr4[] = {1, 5 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, minimize(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 5; int Arr2[] = {1,2,25,24,23, 3,4,22,21,20, 5,6,19,18,17, 7,16,15,14,13, 8,12,11,10,9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; int Arr4[] = {2, 5 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, minimize(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 4; int Arr2[] = {10, 40, 30, 20}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 20; int Arr4[] = {0, 0 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, minimize(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 3; int Arr2[] = {3,8,12, 3,8,12, 3,8,12, 8,12,17}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 12; int Arr4[] = {1, 2 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, minimize(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 1; int Arr2[] = {10, 20, 30, 40, 50}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 23; int Arr4[] = {1, 1 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(4, Arg4, minimize(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MedianFaking ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

