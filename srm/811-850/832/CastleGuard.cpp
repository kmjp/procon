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

ll C[101010];
ll D[505];
class CastleGuard {
	public:
	vector<long long> walk(int N, int R, vector <int> commands) {
		ZERO(C);
		ZERO(D);
		int cur=0;
		int i,j;
		FORR(c,commands) {
			ll a=abs(c)/N;
			ll b=abs(c)%N;
			FOR(i,N) C[i]+=a;
			FOR(i,b) {
				if(c<0) {
					cur=(cur+N-1)%N;
				}
				else {
					cur=(cur+1)%N;
				}
				C[cur]++;
			}
		}
		int d=0;
		
		FOR(i,R) {
			D[d]++;
			(d+=cur)%=N;
		}
		
		vector<ll> ret(N);
		FOR(i,N) {
			FOR(j,N) ret[(i+j)%N]+=1LL*D[i]*C[j];
		}
		ret[0]++;
		
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 3; int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long Arr3[] = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0 }; vector<long long> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, walk(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 1234; int Arr2[] = {2, -3, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long Arr3[] = {2469, 2468, 1234, 0, 0, 0, 0, 0, 0, 1234 }; vector<long long> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, walk(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 97; int Arg1 = 1000; int Arr2[] = {314}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long Arr3[] = {3238, 3238, 3238, 3238, 3238, 3238, 3238, 3238, 3238, 3238, 3238, 3238, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237, 3237 }; vector<long long> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, walk(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 47; int Arg1 = 123; int Arr2[] = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long Arr3[] = {151, 151, 150, 148, 146, 144, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 144, 145, 147, 149 }; vector<long long> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, walk(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 3; int Arg1 = 9; int Arr2[] = {1000000000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long Arr3[] = {3000000001, 3000000000, 3000000000 }; vector<long long> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, walk(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CastleGuard ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

