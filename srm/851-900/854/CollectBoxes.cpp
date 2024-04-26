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

ll B[505050];
ll BS[505050];

class CollectBoxes {
	public:
	long long collect(int N, vector <int> Bprefix, int seed, int blo, int bhi) {
		int i;
		FOR(i,Bprefix.size()) B[i]=Bprefix[i];
		ll state=seed;
		ll spread = bhi - blo + 1;

		for(i=Bprefix.size();i<N;i++) {
		    state = (state * 1103515245 + 12345) % (1LL<<31);
		    B[i] = blo + (state %spread);
		}
		ll ret=1LL<<60;
		int j;
		ll a=0;
		FOR(i,N) a+=abs(B[i])*2;
		ret=min(ret,a);
		
		FOR(j,2) {
			sort(B,B+N);
			if(B[0]==B[N-1]) return 0;
			FOR(i,N) BS[i+1]=BS[i]+B[i];
			FOR(i,N) if(B[i]>=0) {
				ll sum=0;
				if(B[0]>=0) {
					sum+=B[i];
				}
				else {
					sum+=B[i]+abs(B[0])*2;
				}
				sum+=2*(B[i]*(i-1)-(BS[i]-BS[1]));
				sum+=2*((BS[N]-BS[i])-B[i]*(N-i));

				ret=min(ret,sum);
				
			}
			FOR(i,N) B[i]=-B[i];
		}
		
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {11, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; long long Arg5 = 11LL; verify_case(0, Arg5, collect(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {10, 10, 11, 10, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; long long Arg5 = 12LL; verify_case(1, Arg5, collect(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 2; int Arr1[] = {-10, -11}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; long long Arg5 = 11LL; verify_case(2, Arg5, collect(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 2; int Arr1[] = {-47, 47}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; long long Arg5 = 141LL; verify_case(3, Arg5, collect(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 9; int Arr1[] = {10, 20, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 47; int Arg3 = -20; int Arg4 = 100; long long Arg5 = 322LL; verify_case(4, Arg5, collect(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 3; int Arr1[] = {1000000000, -1000000000, 1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 47; int Arg3 = 47; int Arg4 = 47; long long Arg5 = 3000000000LL; verify_case(5, Arg5, collect(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CollectBoxes ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

