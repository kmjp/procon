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

class Chains5 {
	public:

	int construct(vector <int> x, vector <int> y, int n, int seed, int a, int b, int c, int m) {
		while(x.size()<n) {
			int nx,ny;
			seed=(1LL*a*seed+b)%c;
			nx=seed%m;
			seed=(1LL*a*seed+b)%c;
			ny=seed%m;
			if(nx>ny) swap(nx,ny);
			x.push_back(nx);
			y.push_back(ny);
		}
		
		map<int,vector<int>> M;
		int i;
		int zero=0;
		FOR(i,n) {
			if(x[i]==y[i]) {
				zero++;
			}
			else {
				M[x[i]].push_back(y[i]);
			}
		}
		
		vector<int> V;
		FORR(m,M) {
			vector<int> B=m.second;
			sort(ALL(B));
			reverse(ALL(B));
			
			for(i=0;i<B.size();) {
				int num=1;
				while(i+num<B.size() && B[i+num]==B[i]) num++;
				int id=lower_bound(ALL(V),B[i])-V.begin();
				
				int j;
				FOR(j,num) {
					if(V.size()==id) V.push_back(B[i]);
					else V[id]=B[i];
					id++;
				}
				i+=num;
				
			}
		}
		return max(zero,(int)V.size());
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 4, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 1; int Arg7 = 1; int Arg8 = 1; verify_case(0, Arg8, construct(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_1() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 14}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 1; int Arg7 = 1; int Arg8 = 2; verify_case(1, Arg8, construct(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 3, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3, 4, 4, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 1; int Arg7 = 1; int Arg8 = 4; verify_case(2, Arg8, construct(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_3() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 1; int Arg7 = 1; int Arg8 = 0; verify_case(3, Arg8, construct(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_4() { int Arr0[] = {10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; int Arg3 = 47; int Arg4 = 100; int Arg5 = 1; int Arg6 = 1073741824; int Arg7 = 1000000; int Arg8 = 4; verify_case(4, Arg8, construct(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Chains5 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

