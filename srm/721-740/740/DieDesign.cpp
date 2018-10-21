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

int win[30*5100+1];
int ma[31][30*5100];
int from[31][30*5100];


class DieDesign {
	public:
	vector <int> design(vector <int> P) {
		int i,j,k;
		int N=P.size();
		int S=0;
		FORR(p,P) S+=p;
		
		vector<int> C;
		C.push_back(0);
		FOR(i,30*5002) {
			win[i]=0;
			FORR(p,P) if(p<i) win[i]++;
			if(i && win[i]>win[i-1]) C.push_back(i);
		}
		
		MINUS(from);
		MINUS(ma);
		ma[0][S]=0;
		FOR(i,N-1) FOR(j,S+1) FORR(c,C) if(j>=c) {
			if(ma[i][j]+win[c]>ma[i+1][j-c]) {
				ma[i+1][j-c]=ma[i][j]+win[c];
				from[i+1][j-c]=c;
			}
		}
		
		int be=-1;
		int ca=-1;
		FOR(i,S+1) if(ma[N-1][i]+win[i]>be) be=ma[N-1][i]+win[i], ca=i;
		vector<int> R;
		R.push_back(ca);
		for(i=N-1;i>=1;i--) {
			R.push_back(from[i][ca]);
			ca+=from[i][ca];
		}
		cout<<be<<endl;
		return R;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4,5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 0, 7, 7, 7 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, design(Arg0)); }
	void test_case_1() { int Arr0[] = {0,0,0,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, design(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,13,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 4, 4, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, design(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DieDesign ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

