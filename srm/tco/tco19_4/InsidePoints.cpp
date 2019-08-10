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



class InsidePoints {
	public:
	vector<int> R;
	void add(int x,int y) {
		if(R.size() && R[R.size()-2]==x &&R[R.size()-1]==y) return;
		R.push_back(x);
		R.push_back(y);
	}
	vector <int> construct(vector <int> X, vector <int> Y) {
		vector<int> V[51];
		int i,x,y;
		R.clear();
		
		FOR(i,X.size()) V[Y[i]].push_back(X[i]);
		add(51,0);
		add(51,51);
		add(0,51);
		
		for(y=50;y>=1;y--) {
			int pre=51;
			sort(ALL(V[y]));
			reverse(ALL(V[y]));
			int x=0;
			FORR(xx,V[y]) {
				if(xx+2<=pre) {
					add(pre-1,y);
					add(xx+1,y);
					x--;
					add(x,y+1);
				}
				pre=xx;
			}
			add(pre-1,y);
			add(0,y);
		}
		
		return R;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 7, 4, 8, 5, 6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, construct(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {4, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 6, 7, 6, 7, 8, 5, 7, 3, 8 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, construct(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 1, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 0, 3, 0, 3, 3, 0, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, construct(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1, 2, 3, 3, 3, 3, 5, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 3, 1, 5, 2, 4, 3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 2, 2, 2, 2, 0, 4, 0, 4, 2, 6, 2, 6, 4, 4, 4, 4, 6, 2, 6, 2, 4, 3, 3, 1, 4, 0, 4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, construct(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  InsidePoints ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

