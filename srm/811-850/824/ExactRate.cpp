#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


class ExactRate {
	public:
	vector <int> getLongest(int N, int seed, int threshold, int S, int F) {
		int i;
		map<ll,int> R;
		
		ll cur=0;
		R[0]=0;
		int mi=0,ma=0;
		FOR(i,N) {
			seed=(1LL*seed*1103515245+12345)%(1LL<<31);
			if(seed>threshold) cur+=F;
			else cur-=S;
			if(R.count(cur)==0) R[cur]=i+1;
			else {
				if(i+1-R[cur]>ma-mi) {
					mi=R[cur];
					ma=i+1;
				}
			}
		}
		
		return {mi,ma};
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 12; int Arg1 = 47; int Arg2 = 1012345678; int Arg3 = 1; int Arg4 = 2; int Arr5[] = {0, 6 }; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(0, Arg5, getLongest(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 12; int Arg1 = 47; int Arg2 = 1012345678; int Arg3 = 2; int Arg4 = 1; int Arr5[] = {2, 8 }; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(1, Arg5, getLongest(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2_() { int Arg0 = 12; int Arg1 = 47; int Arg2 = 1012345678; int Arg3 = 7; int Arg4 = 11; int Arr5[] = {0, 0 }; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(2, Arg5, getLongest(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 120000; int Arg1 = 47; int Arg2 = 1012345678; int Arg3 = 7; int Arg4 = 11; int Arr5[] = {0, 0 }; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(2, Arg5, getLongest(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ExactRate ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

