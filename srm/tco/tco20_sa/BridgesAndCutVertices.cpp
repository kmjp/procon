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

class BridgesAndCutVertices {
	public:
	vector <int> construct(int B, int C) {
		vector<int> R;
		int i;
		
		if(C==0) {
			FOR(i,B) {
				R.push_back(i*2);
				R.push_back(i*2+1);
			}
		}
		else {
			int com=min(B,C);
			B-=com;
			C-=com;
			
			
			if(B==0) {
				int cur=0;
				while(C>=0) {
					C--;
					R.push_back(cur);
					R.push_back(cur+1);
					R.push_back(cur);
					R.push_back(cur+2);
					R.push_back(cur+1);
					R.push_back(cur+2);
					cur+=2;
				}
			}
			else {
				
				
				FOR(i,B) {
					R.push_back(i);
					R.push_back(B+2);
				}
				R.push_back(B);
				R.push_back(B+1);
				R.push_back(B);
				R.push_back(B+2);
				R.push_back(B+1);
				R.push_back(B+2);
				
			}
			
			while(com--) {
				R.push_back(R.back());
				R.push_back(R.back()+1);
			}
		}
		
		
		return R;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 1; int Arr2[] = {0, 1, 0, 2, 0, 3, 0, 4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, construct(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 1; int Arr2[] = {0, 1, 0, 2, 1, 2, 2, 5, 5, 4, 4, 3, 3, 2, 2, 4, 6, 7, 6, 49, 7, 49 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, construct(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BridgesAndCutVertices ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

