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


class MappingABC {
	public:
	
	int countStrings(vector <int> t) {
		ll mo=1000000007;
		ll pall[8][3030];
		ll pex[8][3030];
		
		int N = t.size();
		int num[3030]={};
		
		int i,j,l,r;
		FOR(i,8) {
			pall[i][0]=pex[i][0]=1;
			FOR(j,3020) {
				pall[i][j+1]=pall[i][j] * __builtin_popcount(i) % mo;
				pex[i][j+1]=pex[i][j] * __builtin_popcount(i&5) % mo;
			}
		}
		
		FORR(r,t) num[r]++;
		ll ret=0;
		int mask[3030];
		
		FOR(l,N) {
			int in[8]={}, out[8]={};
			int tnum[3030]={};
			FOR(i,3020) if(num[i]) mask[i]=7, tnum[i]=num[i];
			FOR(i,l) mask[t[i]] &= 6;
			mask[t[l]] &= 1;
			
			FOR(i,l+1) tnum[t[i]]--;
			FOR(i,3020) if(num[i]) {
				if(tnum[i]==0) out[mask[i]]++;
				else in[mask[i]]++;
			}
			if((mask[t[l]]&1)==0) continue;
			
			for(r=N-1;r>=l+2;r--) {
				in[mask[t[r]]]--;
				
				if(t[l]!=t[r] && (mask[t[r]]&4)) {
					ll in_all=1, in_ex=1, out_all=1;
					FOR(j,8) {
						(in_all *= pall[j][in[j]])%=mo;
						(out_all *= pall[j][out[j]])%=mo;
						(in_ex *= pex[j][in[j]])%=mo;
					}
					
					ret += (in_all-in_ex+mo)*out_all%mo;
				}
				
				tnum[t[r]]--;
				mask[t[r]] &= 3;
				if(tnum[t[r]]) in[mask[t[r]]]++;
				else out[mask[t[r]]]++;
			}
			
		}
		
		return ret % mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {9,9,2,9,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, countStrings(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, countStrings(Arg0)); }
	void test_case_2() { int Arr0[] = {1,2,2,1,2,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, countStrings(Arg0)); }
	void test_case_3() { int Arr0[] = {7,3000,1,3000,1,3000,1,10,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; verify_case(3, Arg1, countStrings(Arg0)); }
	void test_case_4() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,
26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 166952139; verify_case(4, Arg1, countStrings(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MappingABC ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

