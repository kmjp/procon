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

ll Xs[1010101];
ll Ys[1010101];
ll Zs[1010101];
map<pair<int,int>,vector<int>> M[3];
class ThreeDChessRooks {
	public:
	long long count(int C, int R, vector <int> XP, vector <int> YP, vector <int> ZP, int seed) {
		vector<ll> X,Y,Z;
		int i;
		FOR(i,XP.size()) {
			X.push_back(XP[i]);
			Y.push_back(YP[i]);
			Z.push_back(ZP[i]);
		}
		ll s=seed;
		FOR(i,R-XP.size()) {
			s = (s * 1103515245 + 12345)%(1LL<<31);
			X.push_back(s%C);
			s = (s * 1103515245 + 12345)%(1LL<<31);
			Y.push_back(s%C);
			s = (s * 1103515245 + 12345)%(1LL<<31);
			Z.push_back(s%C);
		}
		ZERO(Xs);
		ZERO(Ys);
		ZERO(Zs);
		FOR(i,3) M[i].clear();
		
		ll ret=0;
		FOR(i,R) {
			Xs[X[i]]++;
			Ys[Y[i]]++;
			Zs[Z[i]]++;
			M[0][{Y[i],Z[i]}].push_back(X[i]);
			M[1][{X[i],Z[i]}].push_back(Y[i]);
			M[2][{X[i],Y[i]}].push_back(Z[i]);
		}
		FOR(i,C) {
			ret+=Xs[i]*(Xs[i]-1);
			ret+=Ys[i]*(Ys[i]-1);
			ret+=Zs[i]*(Zs[i]-1);
		}
		FOR(i,3) {
			FORR(m,M[i]) {
				auto v=m.second;
				ret-=v.size()*(v.size()-1);
				map<int,int> A;
				FORR(a,v) A[a]++;
				ret-=1LL*A[1]*A[0];
				ret-=1LL*A[C-1]*A[C-2];
			}
		}
		
		
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 4; int Arr2[] = {0, 0, 0, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 0, 0, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {2, 3, 5, 7}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 0; long long Arg6 = 12LL; verify_case(0, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 4; int Arr2[] = {1, 1, 1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4, 4, 4, 4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0, 0, 0, 0}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 0; long long Arg6 = 0LL; verify_case(1, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 4; int Arr2[] = {9, 2, 3, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5, 6, 7, 8}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {9, 0, 1, 9}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 0; long long Arg6 = 2LL; verify_case(2, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 10; int Arr2[] = {9, 2, 3, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5, 6, 7, 8}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {9, 0, 1, 9}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 47474747; long long Arg6 = 16LL; verify_case(3, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 7; int Arr2[] = {1, 1, 1, 1, 1, 1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4, 7, 4, 7, 4, 7, 4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {2, 2, 2, 2, 2, 2, 2}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 42; long long Arg6 = 24LL; verify_case(4, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_5() { int Arg0 = 99; int Arg1 = 8; int Arr2[] = {47, 48, 49, 50, 50, 51, 52, 53}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {12, 12, 12, 12, 12, 12, 12, 12}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {12, 12, 12, 12, 12, 12, 12, 12}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 111; long long Arg6 = 54LL; verify_case(5, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_6() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0, 0}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 0; long long Arg6 = 0LL; verify_case(6, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ThreeDChessRooks ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

