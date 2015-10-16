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

ll mo;
ll from[200][1<<13];
ll to[200][1<<13];
vector<int> fp[1<<13];

class BearDestroys {
	int od,R,B,T;
	public:
	
	void dfs(int y,int tmask,int fmask,int pat,int fall) {
		int i;
		if(y>B) {
			FORR(r,fp[tmask]) (to[r+fall][fmask] += from[r][tmask]<<pat)%=mo;
			return;
		}
		
		// used
		dfs(y+1,tmask,fmask,pat+1,fall);
		// unused
		if((fmask&(1<<y)) && (fmask&(1<<(y+1)))) {
			dfs(y+1,tmask + (1<<y),fmask^(1<<y),pat,fall+1);
			dfs(y+1,tmask + (1<<y),fmask^(2<<y),pat,fall+1);
		}
		else if(fmask&(1<<y)) {
			dfs(y+1,tmask+ (1<<y),fmask^(1<<y),pat+1,fall+1);
		}
		else if(fmask&(2<<y)) {
			dfs(y+1,tmask+ (1<<y),fmask^(2<<y),pat+1,fall+1);
		}
		else {
			dfs(y+1,tmask+ (1<<y),fmask,pat+1,fall);
		}
		
	}
	
	int sumUp(int W, int H, int MOD) {
		mo=MOD;
		int i,j,k;
		
		ZERO(from);
		from[0][1]=1;
		
		for(od=0;od<=(W-1+H-1);od++) {
			FOR(j,1<<H) {
				FORR(r,fp[j]) to[r][j]=0;
				fp[j].clear();
				FOR(i,200) if(from[i][j]) fp[j].push_back(i);
			}
			
			R=min(od,W-1);
			B=min(od,H-1);
			T=od-R;
			int fmask=0,y;
			FOR(y,H) {
				int x=od-y+1;
				if(x>=0 && x<W) fmask |= 1<<y;
			}
			dfs(T,0,fmask,0,0);
			swap(from,to);
		}
		
		ll ret=0;
		ll pat=0;
		FOR(i,200) ret+=i*from[i][0]%mo, pat+=from[i][0];
		return ret%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 999999937; int Arg3 = 24064; verify_case(0, Arg3, sumUp(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 999999937; int Arg3 = 24576; verify_case(1, Arg3, sumUp(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 20; int Arg1 = 2; int Arg2 = 584794877; int Arg3 = 190795689; verify_case(2, Arg3, sumUp(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 5; int Arg2 = 3; int Arg3 = 1; verify_case(3, Arg3, sumUp(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 19; int Arg3 = 0; verify_case(4, Arg3, sumUp(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 30; int Arg1 = 13; int Arg2 = 312880987; int Arg3 = 107607437; verify_case(5, Arg3, sumUp(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BearDestroys ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
