#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int P[101010];
int L[101010],R[101010];
int MR[101010];
int delta[101010];

class SettingShield {
	public:
	int N,H,T;
	
	ll calc(ll v) {
		int i;
		if(v<0) return 1LL<<60;
		ll w=v,cost=0;
		ZERO(delta);
		FOR(i,N) {
			w+=delta[i];
			if(w<P[i]) {
				if(MR[i]<i) return 1LL<<60;
				cost += P[i]-w;
				delta[MR[i]+1] -= P[i]-w;
				w = P[i];
			}
		}
		return cost + v*T;
	}
	
	long long getOptimalCost(int n, int h, int t, vector <int> val0, vector <int> a, vector <int> b, vector <int> m) {
		int i,j;
		N=n;
		H=h;
		T=t;
		P[0]=val0[0];
		for(i=1;i<N;i++) P[i]=(1LL*a[0]*P[i-1]+b[0]) % m[0];
		
		MINUS(MR);
		L[0]=val0[1];
		R[0]=val0[2];
		MR[L[0]]=R[0];
		for(i=1;i<H;i++) {
			L[i] = min(N-1LL,(1LL*a[1]*L[i-1]+b[1]) % m[1]);
			R[i] = min(N-1LL,L[i]+(1LL*a[2]*(R[i-1]-L[i-1])+b[2]) % m[2]);
			MR[L[i]]=max(MR[L[i]],R[i]);
		}
		for(i=1;i<N;i++) MR[i]=max(MR[i],MR[i-1]);
		
		
		ll ret=1LL<<60;
		int LL=0,RR=10000005;
		FOR(i,30) {
			int m1=(LL*2+RR)/3;
			int m2=(RR*2+LL)/3;
			ll v1=calc(m1);
			ll v2=calc(m2);
			if(v2>=1LL<<60) LL=m2;
			else if(v1<v2) RR=m2;
			else if(v1>v2) LL=m1;
			else LL=m1,RR=m2;
		}
		for(i=LL-10;i<=RR+10;i++) ret=min(ret,calc(i));
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 10; int Arr3[] = {4, 0, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 1, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {3, 1, 1}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {6, 10, 10}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); long long Arg7 = 8LL; verify_case(0, Arg7, getOptimalCost(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 10; int Arr3[] = {4, 0, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 1, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {3, 1, 1}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {6, 10, 10}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); long long Arg7 = 40LL; verify_case(1, Arg7, getOptimalCost(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 3; int Arg2 = 2; int Arr3[] = {4, 1, 3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {2, 4, 3}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {3, 2, 2}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {20, 9, 4}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); long long Arg7 = 22LL; verify_case(2, Arg7, getOptimalCost(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arg0 = 12; int Arg1 = 6; int Arg2 = 4; int Arr3[] = {4, 3, 7}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {2, 4, 5}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {3, 8, 7}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {40, 23, 13}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); long long Arg7 = 108LL; verify_case(3, Arg7, getOptimalCost(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_4() { int Arg0 = 50; int Arg1 = 77; int Arg2 = 4; int Arr3[] = {4, 11, 30}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {9, 40, 7}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {33, 8, 12}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {20000, 200, 13}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); long long Arg7 = 79111LL; verify_case(4, Arg7, getOptimalCost(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_5() { int Arg0 = 555; int Arg1 = 120; int Arg2 = 4; int Arr3[] = {10000000, 301, 520}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {9999999, 9999998, 9999997}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {9995999, 0, 9919999}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {1999999, 9993999, 9299999}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); long long Arg7 = 40000000LL; verify_case(5, Arg7, getOptimalCost(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_6() { int Arg0 = 501; int Arg1 = 2; int Arg2 = 2; int Arr3[] = {10000000, 500, 500}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {10000000, 10000000, 10000000}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {0, 0, 500}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {1000003, 10000000, 10000000}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); long long Arg7 = 10000000LL; verify_case(6, Arg7, getOptimalCost(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SettingShield ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
