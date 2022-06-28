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

vector<int> ev[303030];
deque<int> D[303030];
template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;
const ll mo=1000000007;


class PopChartDominance {
	public:
	
	int count(int N, int Q, vector <int> Aprefix, int Alimit, vector <int> Lprefix, vector <int> Hprefix, int minQL, int maxQL, int seed) {
		ll state = seed;
		int i;
		vector<ll> A,L,H;
		FORR(a,Aprefix) A.push_back(a);
		while(A.size()<N) {
			state = (state * 1103515245 + 12345) % (1LL<<31);
		    A.push_back(state%Alimit);
		}
		
		FORR(a,Lprefix) L.push_back(a);
		FORR(a,Hprefix) H.push_back(a);
		while(L.size()<Q) {
			state = (state * 1103515245 + 12345) % (1LL<<31);
			ll ql = minQL + (state % (maxQL-minQL+1));
			state = (state * 1103515245 + 12345) % (1LL<<31);
			ll lo = state%(N-ql+1);
		    L.push_back(lo);
		    H.push_back(lo+ql);
		}
		
		ZERO(bt.bit);
		FOR(i,N) D[i].clear(), ev[i].clear();
		FOR(i,N) {
			if(D[A[i]].size()) bt.add(i,i-D[A[i]].back());
			D[A[i]].push_back(i);
		}
		FOR(i,Q) {
			ev[L[i]].push_back(i);
		}
		ll ret=0;
		FOR(i,N) {
			FORR(e,ev[i]) {
				ll a=bt(H[e]-1)%mo;
				(ret+=a*(e+1))%=mo;
			}
			D[A[i]].pop_front();
			if(D[A[i]].size()) {
				bt.add(D[A[i]][0],i-D[A[i]][0]);
			}
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arg1 = 2; int Arr2[] = {10, 20, 30, 40, 50, 60, 70}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 100; int Arr4[] = {0, 3}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {7, 5}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 1; int Arg7 = 7; int Arg8 = 47; int Arg9 = 0; verify_case(0, Arg9, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_1() { int Arg0 = 9; int Arg1 = 5; int Arr2[] = {10, 20, 10, 30, 10, 20, 10, 40, 30}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 100; int Arr4[] = {0, 0, 5, 0, 3}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {9, 9, 9, 5, 8}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 1; int Arg7 = 9; int Arg8 = 47; int Arg9 = 71; verify_case(1, Arg9, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_2() { int Arg0 = 30; int Arg1 = 10; int Arr2[] = {4, 7, 5, 18}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 20; int Arr4[] = {0, 5}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {30, 18}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 3; int Arg7 = 10; int Arg8 = 47; int Arg9 = 189; verify_case(2, Arg9, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_3() { int Arg0 = 300000; int Arg1 = 300000; int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arr4[] = {}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 2; int Arg7 = 2; int Arg8 = 424242; int Arg9 = 149685; verify_case(3, Arg9, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PopChartDominance ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

