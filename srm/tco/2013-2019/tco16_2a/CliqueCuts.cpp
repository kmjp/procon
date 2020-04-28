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

ll mat[51];
ll sc[51];

ll npat[1<<23];
ll tot[1<<23];
ll mo=1000000007;

class CliqueCuts {
	public:
	int sum(int n, vector <int> a, vector <int> b, vector <int> c) {
		ZERO(mat);
		ZERO(sc);
		
		int h=n/2,le=n-h;
		int i,x,y;
		ll mask;
		FOR(i,n) mat[i] |= 1LL<<i;
		FOR(i,a.size()) {
			mat[a[i]] |= 1LL<<b[i];
			mat[b[i]] |= 1LL<<a[i];
			sc[a[i]]+=c[i];
			sc[b[i]]+=c[i];
		}
		
		FOR(mask,1<<h) {
			int ok=1;
			ll to=0;
			FOR(i,h) {
				if(mask & (1<<i)) {
					if((mask & mat[i])!=mask) ok=0;
					to += sc[i];
				}
				else to -= sc[i];
			}
			if(ok) {
				tot[mask] = ((to%mo)+mo)%mo;
				npat[mask] = 1;
			}
			else {
				tot[mask]=npat[mask]=0;
			}
		}
		
		FOR(i,h) FOR(mask,1<<h) if(mask&(1<<i)) {
			npat[mask] = (npat[mask]+npat[mask^(1<<i)])%mo;
			tot[mask] = (tot[mask]+tot[mask^(1<<i)])%mo;
		}
		
		ll ret=0;
		for(mask=0;mask<1LL<<n;mask += 1LL<<h) {
			int ok=1;
			ll tmask = (1<<h)-1;
			ll to=0;
			for(i=h;i<n;i++) {
				if(mask & (1LL<<i)) {
					if((mask & mat[i])!=mask) ok=0;
					to += sc[i];
					tmask &= mat[i];
				}
				else to -= sc[i];
			}
			if(ok) ret += (((to%mo)+mo)%mo)*npat[tmask] % mo + tot[tmask];
		}
		
		FOR(i,n) ret += sc[i];
		return (ret%mo+mo)%mo * ((mo+1)/2) % mo;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {100}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 100; verify_case(0, Arg4, sum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {0,0,0,0,1,1,1,2,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,2,3,4,3,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,1,2,3,4,5,6,7,8,9}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 45; verify_case(1, Arg4, sum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 5; int Arr1[] = {0,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {9,2,4,3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 999999941; verify_case(2, Arg4, sum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 10; int Arr1[] = {0,1,2,9,5,3,4,7,3,4,1,5,2,3,0,7,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6,7,4,5,6,2,6,3,1,8,2,0,9,9,8,2,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {10000,10000000,100000000,100,10,1,1000,100,10000,100,10000,1000,100,10,100,100000000,10}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 209370454; verify_case(3, Arg4, sum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 45; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(4, Arg4, sum(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CliqueCuts ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
