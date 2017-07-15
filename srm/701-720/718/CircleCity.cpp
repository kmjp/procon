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

class CircleCity {
	public:
	int N;
	ll X[2020];
	int ok(ll v) {
		int i,num=0;
		ll range=-1;
		FOR(i,N) {
			if(X[i]>range) {
				range=X[i]+v;
				num++;
			}
		}
		return num;
	}
	
	int findMin(vector <int> dist, int k) {
		int i,j;
		
		ll mi=1LL<<50;
		N=dist.size();
		FOR(i,N) {
			FOR(j,N-1) X[j+1]=X[j]+dist[j];
			
			rotate(dist.begin(),dist.begin()+1,dist.end());
			ll ret=(1LL<<50)-1;
			for(j=49;j>=0;j--) if(ok(ret-(1LL<<j))<=k) ret -= 1LL<<j;
			mi=min(mi,ret);
		}
		return mi;
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,5,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(0, Arg2, findMin(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3,5,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 0; verify_case(1, Arg2, findMin(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,2,3,4,5,6,5,4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 5; verify_case(2, Arg2, findMin(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1, 100, 1,1,1, 100, 1, 100, 1,1,1, 100, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 3; verify_case(3, Arg2, findMin(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {3,1,4,1,5,9,2,6,5,3,5,8,9,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 8; verify_case(4, Arg2, findMin(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000,
1000000,1000000,1000000,1000000,1000000,1000000
}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 9000000; verify_case(5, Arg2, findMin(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CircleCity ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

