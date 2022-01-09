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

int N,T;
int V[55];
int from[301010];
int to[301010];
class KnapsackTweak {
	public:
	int can(int d) {
		if(d<0) return 0;
		
		ZERO(from);
		int i,j;
		for(i=100000;i<=300000;i++) from[i]=1;
		FOR(i,N) {
			for(j=0;j<=300000;j++) {
				int ok=0;
				if(from[j]-(j>=1?from[j-1]:0)) ok=1;
				int L=max(0,j-V[i]-d);
				int R=min(300000,j-V[i]+d);
				if(L<=R&&from[R]-(L>=0?from[L-1]:0)) ok=1;
				to[j]=ok;
				if(j) to[j]+=to[j-1];
				if(j==T+100000&&ok) return 1;
			}
			swap(from,to);
		}
		return 0;
		
		
	}
	
	int smallest(vector <int> items, int target) {
		int ret=100000;
		int i;
		N=items.size();
		T=target;
		FOR(i,N) V[i]=items[i];
		for(i=20;i>=0;i--) if(can(ret-(1<<i))) ret-=1<<i;

		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {11, 21, 31, 41, 51}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 150; int Arg2 = 1; verify_case(0, Arg2, smallest(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {11, 21, 31, 41, 51}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 154; int Arg2 = 1; verify_case(1, Arg2, smallest(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {11, 21, 31, 41, 51}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 73; int Arg2 = 0; verify_case(2, Arg2, smallest(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {100, 100, 100, 100, 100000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 383; int Arg2 = 5; verify_case(3, Arg2, smallest(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {2, 8, 70}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; int Arg2 = 10; verify_case(4, Arg2, smallest(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  KnapsackTweak ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

