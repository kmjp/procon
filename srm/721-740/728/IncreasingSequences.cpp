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

ll mo=998244353;

ll T[616][313];
ll table[616][313];
ll rev(ll a) {
	ll r=1, n=mo-2;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

class IncreasingSequences {
	public:
	int count(vector <int> L, vector <int> R) {
		L.push_back(1000000005);
		R.push_back(1000000005);
		
		int N=L.size();
		int i,x,y;
		FOR(i,N) {
			L[i]+=N-i;
			R[i]+=N-i;
			if(i) L[i]=max(L[i],L[i-1]);
		}
		for(i=N-2;i>=0;i--) R[i]=min(R[i],R[i+1]);
		FOR(i,N) if(L[i]>R[i]) return 0;
		
		vector<int> C;
		C.push_back(0);
		C.push_back(1<<30);
		FOR(i,N) C.push_back(L[i]),C.push_back(R[i]+1);
		sort(ALL(C));
		C.erase(unique(ALL(C)),C.end());
		
		ZERO(T);
		int M=C.size();
		FOR(i,M-1) if(L[0]<=C[i] && C[i+1]<=R[0]+1) T[i][0]=1;
		
		FOR(i,M-1) {
			ll p=C[i+1]-C[i]-1;
			ll q=0;
			table[i][0]=1;
			for(x=1;x<=300;x++) {
				p++;
				q++;
				table[i][x]=table[i][x-1]*p%mo*rev(q)%mo;
			}
		}
		ll ret=0;
		for(i=1;i<N;i++) {
			ll S=0;
			FOR(x,M-1) {
				if(L[i]<=C[x] && C[x+1]<=R[i]+1) T[x][i]=S;
				if(L[i-1]<=C[x] && C[x+1]<=R[i-1]+1) {
					for(y=i-1;y>=0;y--) {
						if(!(L[y]<=C[x] && C[x+1]<=R[y]+1)) break;
						if(T[x][y]) (S += T[x][y]*table[x][i-y])%=mo;
					}
				}
			}
			ret=S;
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 3, 1, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 5, 4, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {10, 30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20, 40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 121; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {30, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {40, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {4, 46, 46, 35, 20, 77, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {41, 65, 84, 90, 49, 86, 88}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2470; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1755647; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  IncreasingSequences ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

