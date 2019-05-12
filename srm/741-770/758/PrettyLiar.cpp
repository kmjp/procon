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

ll X[101][10101];
ll Y[101][10101];
ll Z[101][10101];
ll W[10101],SS[10101];
ll mo=1000000007;
ll fact[201];

class PrettyLiar {
	public:
	int count(int S, vector <int> A, vector <int> B) {
		ZERO(X);
		ZERO(Y);
		ZERO(Z);
		int N=A.size();
		
		int i,a,b,j,x,y;
		fact[0]=1;
		for(i=1;i<=200;i++) fact[i]=fact[i-1]*i%mo;
		X[0][0]=Y[0][0]=Z[0][0]=1;
		FOR(i,N) {
			for(a=i;a>=0;a--) FOR(b,a*100+1) {
				X[a+1][b+A[i]]+=X[a][b];
				if(X[a+1][b+A[i]]>=mo) X[a+1][b+A[i]]-=mo;
				Y[a+1][b+B[i]]+=Y[a][b];
				if(Y[a+1][b+B[i]]>=mo) Y[a+1][b+B[i]]-=mo;
			}
		}
		ll ret=0;
		FOR(i,N) {
			int b=B[i];
			for(x=1;x<=N;x++) {
				ll pat=fact[x]%mo*fact[N-x]%mo*fact[x-1]%mo*fact[N-x]%mo;
				FOR(j,x*100+1) {
					Z[x][j]=Y[x][j];
					if(j>=b) {
						Z[x][j]+=mo-Z[x-1][j-b];
						if(Z[x][j]>=mo) Z[x][j]-=mo;
					}
					W[j]=Z[x-1][j];
					if(j) W[j]+=W[j-1];
					if(W[j]>=mo) W[j]-=mo;
				}
				FOR(j,x*100+1) if(X[x][j]) {
					int L=S-b-j,R=min(x*100,S-j-1);
					if(R<0 || R<L) continue;
					ll sum=W[R];
					if(L>0) sum+=mo-W[L-1];
					if(sum) ret+=X[x][j]*sum%mo*pat%mo;
				}
				ret%=mo;
			}
		}
		return ret;
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 60; int Arr1[] = {10,40}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {20,30}
; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 100 ; int Arr1[] = {10,40}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {20,30}
; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10 ; int Arr1[] = {10,40}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {20,30}
; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 25 ; int Arr1[] = {6,14}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7,1}
; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 178; int Arr1[] = {25,6,14,100,71,49}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {17,7,1,100,62,43}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 240192; verify_case(4, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 1546 ; int Arr1[] = {50,77,74,23,43,4,57,13,50,94,43,72,94,36,20,23,27,7,3,21,16,64,28,20,2,40,92,93,17,94,43,17,1,87,58,67,43,22,99,76,13,10,45,28,2,5,37,26,76,12}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {40,93,80,23,20,71,23,14,43,45,38,20,61,84,35,9,85,71,7,21,10,42,23,20,38,73,58,97,32,3,43,99,31,39,33,73,81,3,9,73,17,68,50,27,25,86,22,47,64,8}
; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 949234178; verify_case(5, Arg3, count(Arg0, Arg1, Arg2)); }
//	void test_case_6() { int Arg0 = 4; int Arr1[] = {1,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1,1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 576; verify_case(6, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 9727; int Arr1[] = {100, 100, 100, 95, 98, 96, 90, 97, 98, 94, 90, 95, 90, 100, 97, 99, 99, 90, 90, 96, 93, 90, 98, 100, 94, 96, 91, 99, 94, 96, 93, 99, 96, 99, 95, 99, 98, 98, 98, 92, 96, 93, 96, 99, 91, 99, 96, 96, 95, 99, 97, 94, 93, 97, 92, 97, 91, 95, 96, 100, 93, 95, 100, 96, 92, 100, 91, 93, 94, 98, 96, 91, 99, 96, 98, 92, 92, 92, 97, 92, 99, 95, 90, 93, 100, 92, 94, 98, 96, 90, 98, 96, 91, 93, 92, 94, 98, 100, 98, 94}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {93, 100, 99, 93, 97, 95, 92, 95, 96, 97, 96, 90, 99, 93, 90, 100, 96, 92, 90, 93, 92, 100, 91, 98, 93, 98, 91, 95, 95, 96, 99, 94, 97, 93, 95, 97, 96, 93, 93, 100, 95, 93, 98, 91, 100, 90, 94, 99, 100, 97, 92, 92, 97, 93, 99, 95, 98, 93, 96, 99, 97, 98, 96, 94, 92, 90, 93, 93, 94, 91, 96, 92, 98, 95, 100, 97, 92, 96, 97, 98, 94, 97, 91, 90, 93, 95, 96, 99, 97, 99, 93, 91, 96, 93, 97, 96, 97, 91, 91, 93}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 768695830; verify_case(6, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PrettyLiar ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

