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

class MedianSegments {
	public:
	long long count(int N, int K, vector <int> Aprefix, int M) {
		vector<ll> A;
		FORR(a,Aprefix) A.push_back(a);
		ll state=A.back();
		int i;
		for(i=Aprefix.size();i<N;i++) {
			state = (state * 1103515245 + 12345)%(1LL<<31);
			A.push_back(state%M);
		}
		vector<ll> V;
		
		ll ret=0;
		map<int,int> T;
		int cur=0;
		T[0]=1;
		for(i=K+1;i<N;i++) {
			if(A[i]>A[K]) cur--;
			else if(A[i]<A[K]) cur++;
			T[cur]++;
		}
		cur=0;
		ret+=T[0];
		for(i=K-1;i>=0;i--) {
			if(A[i]>A[K]) cur++;
			if(A[i]<A[K]) cur--;
			ret+=T[cur];
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 3; int Arr2[] = {30, 40, 50, 60, 70, 80, 90, 100, 110, 120}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 12345; long long Arg4 = 4LL; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 9; int Arg1 = 4; int Arr2[] = {0, 10, 2, 9, 5, 4, 6, 7, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 47; long long Arg4 = 11LL; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 13; int Arg1 = 5; int Arr2[] = {47023}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 12345678; long long Arg4 = 5LL; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MedianSegments ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

