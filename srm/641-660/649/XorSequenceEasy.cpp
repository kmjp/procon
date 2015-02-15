#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class XorSequenceEasy {
	public:
	ll ret;
	
	ll dfs(int D,vector<vector<ll> >& V) {
		if(D<0) return 0;
		if(V.empty()) return 0;
		int i,j;
		vector<vector<ll> > NV;
		ll ret0=0,ret1=0;
		FOR(i,V.size()) {
			vector<ll> v[2];
			int n0=0,n1=0;
			FOR(j,V[i].size()) {
				if(V[i][j]&(1<<D)) {
					n1++;
					ret1 += n0;
					v[1].push_back(V[i][j]);
				}
				else {
					n0++;
					ret0 += n1;
					v[0].push_back(V[i][j]);
				}
			}
			if(v[0].size()>1) NV.push_back(v[0]);
			if(v[1].size()>1) NV.push_back(v[1]);
		}
		return max(ret0,ret1)+dfs(D-1,NV);
		
	}
	
	int getmax(vector <int> A, int N) {
		int B=0,i,j,k;
		while(1LL<<(B+1)<=N) B++;
		
		vector<vector<ll> > V;
		vector<ll> v;
		FOR(i,A.size()) v.push_back(A[i]);
		V.push_back(v);
		return dfs(B-1,V);
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,2,1,0,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 8; verify_case(0, Arg2, getmax(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3,0,4,6,1,5,7,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 21; verify_case(1, Arg2, getmax(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; int Arg2 = 76; verify_case(2, Arg2, getmax(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 0; verify_case(3, Arg2, getmax(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {408024109,11635919,196474438,117649705,812669700,553475508,445349752,271145432,730417256,738416295
,147699711,880268351,816031019,686078705,1032012284,182546393,875376506,220137366,906190345,16216108
,799485093,715669847,413196148,122291044,777206980,68706223,769896725,212567592,809746340,964776169
,928126551,228208603,918774366,352800800,849040635,941604920,326686120,920977486,964528038,659998484
,207195539,607901477,725914710,655525412,949610052,142750431,766838105,1024818573,836758851,97228667}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1073741824; int Arg2 = 720; verify_case(4, Arg2, getmax(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  XorSequenceEasy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
