#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll A[202020];
ll mo=1LL<<62;

class XorOrderDiv2 {
	public:
	pair<ll,ll> dfs(int cur,int L,int R,int d,int X,int Y) {
		if(d<0) return {0,0};
		int X2 = (X+Y)/2;
		int M = lower_bound(A+L,A+R,X2)-A;
		
		pair<ll,ll> r;
		ll num;
		if(cur<X2) {
			num = R-M;
			r = dfs(cur,L,M,d-1,X,X2);
		}
		else {
			num = M-L;
			r = dfs(cur,M,R,d-1,X2,Y);
		}
		r.second = (2*r.second + 2*num*r.first +  ((num*num%mo)<<(d)))%mo;
		r.first = (2*r.first + (num<<(d)))%mo;
		return r;
	}
	vector<long long> getExpectation(int m, vector <int> a) {
		int N=a.size();
		int i;
		FOR(i,N) A[i]=a[i];
		sort(A,A+N);
		
		vector<ll> V;
		FOR(i,N) V.push_back(dfs(a[i],0,N,m-1,0,1<<m).second);
		return V;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {0,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arr2[] = {6, 6, 8 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arr2[] = {0 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arr1[] = {13,17}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arr2[] = {16, 16 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 30; int Arr1[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arr2[] = {29527900160, 28991029248, 28991029248, 27917287424, 27917287424, 27917287424, 27917287424, 35433480192, 35433480192, 35970351104 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getExpectation(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  XorOrderDiv2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
