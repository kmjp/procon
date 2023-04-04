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


const int prime_max = 1000000;
vector<int> prime;
int NP,divp[prime_max];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

int hoge(ll v) {
	int i;
	int num=0;
	FOR(i,NP) {
		int a=prime[i];
		if(1LL*a*a>v) break;
		while(v%a==0) {
			num++;
			v/=a;
		}
	}
	if(v>1) num++;
	return num;
}

class DivNim {
	public:
	vector <int> solve(long long lo, long long hi, vector<long long> board) {
		vector<ll> A;
		vector<int> num;
		for(ll v=lo;v<=hi;v++) {
			A.push_back(v);
			num.push_back(0);
		}
		int i;
		for(int a=2;a<=1000000;a++) {
			for(ll v=(lo+a-1)/a*a;v<=hi;v+=a) {
				i=v-lo;
				while(A[i]%a==0) {
					A[i]/=a;
					num[i]++;
				}
			}
		}
		
		cprime();
		vector<int> X;
		FORR(b,board) X.push_back(hoge(b));
		
		vector<int> ret(2);
		FOR(i,A.size()) {
			if(A[i]>1) num[i]++;
			int ma=num[i];
			int xo=num[i];
			FORR(a,X) {
				ma=max(ma,a);
				xo^=a;
			}
			if(xo==0) ret[0]++;
			if(ma>1) {
				if(xo==0) ret[1]++;
			}
			else {
				if(xo==1) ret[1]++;
			}
			
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 12LL; long Arr2[] = {}; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 5 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_1() { long long Arg0 = 12LL; long long Arg1 = 12LL; long Arr2[] = {12, 12, 12, 12, 12}; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_2() { long long Arg0 = 10LL; long long Arg1 = 30LL; long Arr2[] = {12, 16, 29, 24, 28}; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6, 6 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_3() { long long Arg0 = 1LL; long long Arg1 = 12LL; long Arr2[] = {1, 1, 1}; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 5 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, solve(Arg0, Arg1, Arg2)); }
	void test_case_3_() { long long Arg0 = 999999899999LL; long long Arg1 = 999999999999LL; long Arr2[] = {999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999,999999899999}; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 5 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, solve(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DivNim ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

