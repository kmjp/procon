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

class ResistorFactory {
	public:
	vector <int> construct(long long nanoOhms) {
		double D=nanoOhms/1e9;
		double V[200]={};
		vector<int> R,R2;
		
		int i;
		V[0]=1;
		for(i=1;i<100;i++) {
			R.push_back(i-1);
			R.push_back(i-1);
			R.push_back(0);
			V[i]=V[i-1]*2;
		}
		R.push_back(0);
		R.push_back(0);
		R.push_back(1);
		V[100]=0.5;
		for(i=101;i<200;i++) {
			R.push_back(i-1);
			R.push_back(i-1);
			R.push_back(1);
			V[i]=V[i-1]*0.5;
		}
		
		for(i=99;i>=0;i--) {
			if(D>=V[i]) {
				R2.push_back(i);
				D-=V[i];
			}
		}
		for(i=100;i<199;i++) {
			if(D>=V[i]) {
				R2.push_back(i);
				D-=V[i];
			}
		}
		R2.push_back(199);
		
		for(i=1;i<R2.size();i++) {
			if(i==1) {
				R.push_back(R2[0]);
				R.push_back(R2[1]);
				R.push_back(0);
			}
			else {
				R.push_back(R.size()/3);
				R.push_back(R2[i]);
				R.push_back(0);
				
			}
		}
		return R;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { long long Arg0 = 3000000000LL; int Arr1[] = {0, 0, 0, 0, 1, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, construct(Arg0)); }
	void test_case_1() { long long Arg0 = 1200000000LL; int Arr1[] = {0, 0, 0, 1, 0, 0, 1, 2, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, construct(Arg0)); }
	void test_case_2() { long long Arg0 = 1428571428LL; int Arr1[] = {0, 0, 0, 0, 1, 0, 1, 2, 0, 3, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, construct(Arg0)); }
	void test_case_3() { long long Arg0 = 12000000001LL; int Arr1[] = {0, 0, 0, 0, 1, 0, 2, 2, 0, 3, 3, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, construct(Arg0)); }
	void test_case_4() { long long Arg0 = 333333333LL; int Arr1[] = {0, 0, 1, 0, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, construct(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ResistorFactory ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

