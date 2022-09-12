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

int B[202020];
int C[202020];
ll sum[202020];

ll from[303],to[303];

class HashingWithBackupTapes {
	public:
	long long optimize(int H, int T, int N, int L, vector <int> W, int seed) {
		vector<int> who;
		
		ZERO(sum);
		int i,j;
		FOR(i,H) FOR(j,W[i]) who.push_back(i);
		ll state=seed;
		FOR(i,N) {
			state = (state * 1103515245 + 12345)%(1LL<<31);
			B[i]=who[state%who.size()];
			state = (state * 1103515245 + 12345)%(1LL<<31);
			C[i]=1 + (state%L);
			sum[B[i]]+=C[i];
		}
		
		ZERO(from);
		int x,y;
		FOR(i,H) {
			FOR(j,T+1) to[j]=1LL<<60;
			ll pen=0;
			while(1<<pen<sum[i]) pen++;
			pen=(2*sum[i])*pen;
			FOR(x,T+1) {
				ll sc=0;
				ll a=sum[i]/(x+1);
				ll b=sum[i]%(x+1);
				sc+=b*(a+1)*(a+2)/2+(x+1-b)*(a+0)*(a+1)/2;
				if(x) sc+=pen;
				for(y=0;x+y<=T;y++) to[x+y]=min(to[x+y],sc+from[y]);
			}
			swap(from,to);
			
		}
		ll mi=1LL<<60;
		FOR(i,T+1) mi=min(mi,from[i]);
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 2; int Arg3 = 10; int Arr4[] = {1, 2, 3}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 4747; long long Arg6 = 39LL; verify_case(0, Arg6, optimize(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 5; int Arg3 = 1000; int Arr4[] = {42}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 42; long long Arg6 = 3446625LL; verify_case(1, Arg6, optimize(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 5; int Arg3 = 1000; int Arr4[] = {11}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 42; long long Arg6 = 1786969LL; verify_case(2, Arg6, optimize(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 7; int Arg3 = 29; int Arr4[] = {5, 4, 3, 2, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 335; long long Arg6 = 1013LL; verify_case(3, Arg6, optimize(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  HashingWithBackupTapes ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

