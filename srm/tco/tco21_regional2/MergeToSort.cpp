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


ll S[202020];
pair<int,int> dp[202020];
class MergeToSort {
	public:
	int minSteps(int N, vector <int> Aprefix, int seed, int blo, int bhi) {
		vector<ll> A;
		FORR(a,Aprefix) A.push_back(a);
		ll state = seed;
		int i;
		while(A.size()<N) {
			state = (state * 1103515245 + 12345) % (1LL<<31);
			int b = blo + ((state / 1000) % (bhi-blo+1));
			state = (state * 1103515245 + 12345) % (1LL<<31);
			int x = 1<<(b-1);
			A.push_back(x + ((state / 10) % x));
		}
		
		ZERO(dp);
		FOR(i,N) S[i+1]=S[i]+A[i];
		dp[0]={1,0};
		
		FOR(i,N) {
			dp[i+1]=max(dp[i],dp[i+1]);
			ll sum=S[i+1]-S[dp[i].second];
			
			if(S[N]-S[i+1]<sum) continue;
			int L=i,R=N;
			while(L+1<R) {
				int M=(L+R)/2;
				if(S[M]-S[i+1]>=sum) R=M;
				else L=M;
			}
			dp[R-1]=max(dp[R-1],{dp[i].first+1,i+1});
		}
		
		return N-dp[N-1].first;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {20, 10, 35, 38}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 1; int Arg4 = 1; int Arg5 = 1; verify_case(0, Arg5, minSteps(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {10, 10, 10, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 47; int Arg3 = 15; int Arg4 = 25; int Arg5 = 0; verify_case(1, Arg5, minSteps(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 15; int Arr1[] = {420, 470}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 420047; int Arg3 = 9; int Arg4 = 10; int Arg5 = 7; verify_case(2, Arg5, minSteps(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MergeToSort ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

