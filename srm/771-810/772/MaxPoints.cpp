#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll A[202020];
ll B[202020];
ll D[202020];
ll P[202020];
template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,22> XS,YS,XN,YN;

class MaxPoints {
	public:
	int findMaxPoints(int N, vector <int> X, vector <int> Y, long long K, int seedX, int seedY) {
		A[0]=seedX;
		B[0]=seedY;
		int i;
		for(i=1;i<N;i++) A[i]=(A[i-1]*1103515245 + 12345) % 2147483648;
		for(i=1;i<N;i++) B[i]=(B[i-1]*1103515245 + 12345) % 2147483648;
		for(i=X.size();i<N;i++) X.push_back(A[i]%2000001-1000000);
		for(i=Y.size();i<N;i++) Y.push_back(B[i]%2000001-1000000);
		ZERO(XS.bit);
		ZERO(YS.bit);
		ZERO(XN.bit);
		ZERO(YN.bit);
		FOR(i,N) {
			X[i]+=1000005;
			Y[i]+=1000005;
			XS.add(X[i],X[i]);
			YS.add(Y[i],Y[i]);
			XN.add(X[i],1);
			YN.add(Y[i],1);
		}
		ll diff=0;
		FOR(i,N) {
			D[i]=0;
			D[i]+=(XS(1<<21)-XS(X[i]))-(XN(1<<21)-XN(X[i]))*X[i];
			D[i]+=(XN(X[i]-1)*X[i])-XS(X[i]-1);
			D[i]+=(YS(1<<21)-YS(Y[i]))-(YN(1<<21)-YN(Y[i]))*Y[i];
			D[i]+=(YN(Y[i]-1)*Y[i])-YS(Y[i]-1);
			diff-=D[i];
		}
		diff/=2;
		if(diff>K) return -1;
		
		sort(D,D+N);
		int ret=0;
		while(ret<N) {
			if(diff+D[ret]<=K) {
				diff+=D[ret];
				ret++;
			}
			else break;
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {1, 2, 1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 1000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 2LL; int Arg4 = 1; int Arg5 = 1; int Arg6 = 2; verify_case(0, Arg6, findMaxPoints(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 2, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 0LL; int Arg4 = 1; int Arg5 = 1; int Arg6 = 3; verify_case(1, Arg6, findMaxPoints(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 2, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = -1LL; int Arg4 = 1; int Arg5 = 1; int Arg6 = -1; verify_case(2, Arg6, findMaxPoints(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 4; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = -5397718LL; int Arg4 = 1825126330; int Arg5 = 704277911; int Arg6 = 0; verify_case(3, Arg6, findMaxPoints(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arg0 = 100000; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = -3829423936963408LL; int Arg4 = 1225224201; int Arg5 = 441244497; int Arg6 = 26190; verify_case(4, Arg6, findMaxPoints(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MaxPoints ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

