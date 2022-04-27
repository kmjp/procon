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

ll A[252525];
int C[252525];
multiset<int> S;

class ContiguousConstantSegment {
	public:
	int produce(int N, int MOD, vector <int> Aprefix, int seed, int E) {
		int i;
		ll s=seed;
		FOR(i,N) {
			if(i<Aprefix.size()) {
				A[i]=Aprefix[i];
			}
			else {
			    s = (s * 1103515245 + 12345)%(1LL<<31);
			    A[i] = (s / 16)%MOD;
			}
		}
		
		FOR(i,N) if(A[i]!=A[0]) break;
		if(i==N) {
			if(N==1||E>1||E==0) return N;
			return N-1;
		}
		
		
		int L=0,R=0,ma=1;
		ZERO(C);
		S.clear();
		FOR(i,250001) S.insert(0);
		
		for(L=0;L<N;L++) {
			while(R<N) {
				int x=A[R];
				S.erase(S.find(C[x]));
				S.insert(++C[x]);
				int y=*S.rbegin();
				if(R+1-L-y>E) {
					S.erase(S.find(C[x]));
					S.insert(--C[x]);
					break;
				}
				R++;
			}
			ma=max(ma,R-L);
			int x=A[L];
			S.erase(S.find(C[x]));
			S.insert(--C[x]);
		}
		return ma;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 9; int Arg1 = 10; int Arr2[] = {1, 2, 3, 2, 4, 5, 2, 2, 6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 47; int Arg4 = 0; int Arg5 = 2; verify_case(0, Arg5, produce(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 9; int Arg1 = 10; int Arr2[] = {1, 2, 3, 2, 4, 5, 2, 2, 6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 34424; int Arg4 = 1; int Arg5 = 3; verify_case(1, Arg5, produce(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 9; int Arg1 = 10; int Arr2[] = {1, 2, 3, 2, 4, 5, 2, 2, 6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 366122; int Arg4 = 2; int Arg5 = 5; verify_case(2, Arg5, produce(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 4700; int Arg1 = 1; int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 123; int Arg4 = 16; int Arg5 = 4700; verify_case(3, Arg5, produce(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 20; int Arg1 = 100; int Arr2[] = {0, 42, 47}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 123; int Arg4 = 6; int Arg5 = 8; verify_case(4, Arg5, produce(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ContiguousConstantSegment ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

