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


class SubstringQueries {
	public:
	long long solve(string S, int k) {
		int N=S.size();
		ll ret=0;
		vector<int> cand[2525];
		int i;
		S+=S;
		
		if(k==1) {
			vector<vector<int>> V;
			V.resize(1);
			FOR(i,N) V[0].push_back(i);
			for(int len=1;len<=N;len++) {
				vector<vector<int>> D;
				int mi=-1;
				FORR(W,V) {
					vector<int> C[26];
					FORR(v,W) {
						C[S[v+len-1]-'a'].push_back(v);
					}
					FOR(i,26) if(C[i].size()) {
						if(mi==-1) mi=C[i][0];
						if(C[i].back()+len>=N) C[i].pop_back();
						if(C[i].size()) D.push_back(C[i]);
					}
				}
				ret+=mi;
				swap(V,D);
			}
		}
		else {
			FOR(i,N) cand[0].push_back(i);
			for(int len=1;len<=N;len++) {
				char m='z'+1;
				FORR(i,cand[len-1]) {
					if(S[i+len-1]<m) {
						m=S[i+len-1];
						cand[len].clear();
					}
					if(S[i+len-1]==m) cand[len].push_back(i);
				}
				ret+=cand[len][0];
			}
			ret+=1LL*N*(k-2)*cand[N][0];
			int pre=0;
			for(int cur=1;cur<N;cur++) {
				int len=2*N-cur;
				if(S.substr(pre,len)>S.substr(cur,len)) {
					pre=cur;
				}
				ret+=pre;
			}
		}
		
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "dcbadcba"; int Arg1 = 1; long long Arg2 = 0LL; verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "zaba"; int Arg1 = 2; long long Arg2 = 7LL; verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "acaa"; int Arg1 = 2; long long Arg2 = 10LL; verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "aa"; int Arg1 = 4; long long Arg2 = 0LL; verify_case(3, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SubstringQueries ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

