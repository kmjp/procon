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


class BearSortsDiv2 {
	public:
	
	int dodo(vector<int> VV) {
		if(VV.size()<=1) return 0;
		int i,N=VV.size();
		vector<int> V[2];
		FOR(i,N) V[i<N/2].push_back(VV[i]);
		
		int ret=dodo(V[0])+dodo(V[1]);
		sort(V[0].begin(),V[0].end());
		sort(V[1].begin(),V[1].end());
		int x=0,y=0;
		while(x<V[0].size()&&y<V[1].size()) {
			ret++;
			if(V[0][x]<V[1][y]) x++;
			else y++;
		}
		return ret;
	}
	
	double getProbability(vector <int> seq) {
		int N=seq.size(),x;
		vector<int> V(N,0);
		
		FOR(x,seq.size()) V[seq[x]-1]=x;
		return log(pow(2,-dodo(V)));
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = -0.6931471805599453; verify_case(0, Arg1, getProbability(Arg0)); }
	void test_case_1() { int Arr0[] = {1,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = -1.3862943611198906; verify_case(1, Arg1, getProbability(Arg0)); }
	void test_case_2() { int Arr0[] = {10,13,18,2,4,6,24,22,19,5,7,20,23,14,21,17,25,3,1,11,12,8,15,16,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = -57.53121598647546; verify_case(2, Arg1, getProbability(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BearSortsDiv2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
