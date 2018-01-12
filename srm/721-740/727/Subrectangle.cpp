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

class Subrectangle {
	public:
	int minMissed(string S) {
		vector<pair<int,int>> V;
		V.push_back({0,0});
		FORR(c,S) {
			c=(c=='#');
			if(V.empty() || V.back().first!=c) V.push_back({c,1});
			else V.back().second++;
		}
		if(V.back().first==1) V.push_back({0,0});
		
		if(V.size()==1) return 1;
		if(V.size()==3) return 0;
		
		int A[2]={0,0};
		FORR(v,V) A[v.first]=max(A[v.first],v.second);
		
		
		
		int mi=1<<20;
		int x,y,z;
		FOR(x,301) FOR(y,A[1]+1) FOR(z,A[0]-x+1) if(y && x+y+z<mi) {
			int W=x+y+z;
			int H=0;
			deque<pair<int,int>> D;
			FORR(v,V) D.push_back(v);
			while(D.front().second>x) {
				H+=W;
				D.front().second-=W;
				if(D.front().second<0) D.front().second=0;
				if(H>=mi) break;
			}
			if(H>=mi) continue;
			while(D.size()>1) {
				H+=W;
				if(H>=mi) break;
				if(D.front().first==0 && D.front().second>x) {
					if(x+z==0) {
						H=mi+1;
						break;
					}
					D.front().second-=x+z;
					continue;
				}
				if(D.front().first<=0) D.pop_front();
				if(D.front().second>y) {
					D.front().second-=y;
					if(H>mi) break;
					continue;
				}
				D.pop_front();
				D.front().second-=z;
			}
			if(H>mi) continue;
			H+=(D.back().second+W-1)/W*W;
			mi=min(mi,H);
			
		}
		
		return mi-S.size();
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "..###.##"; int Arg1 = 2; verify_case(0, Arg1, minMissed(Arg0)); }
	void test_case_1() { string Arg0 = "#.##.#.#.."; int Arg1 = 2; verify_case(1, Arg1, minMissed(Arg0)); }
	void test_case_2() { string Arg0 = "####"; int Arg1 = 0; verify_case(2, Arg1, minMissed(Arg0)); }
	void test_case_3() { string Arg0 = ""; int Arg1 = 1; verify_case(3, Arg1, minMissed(Arg0)); }
	void test_case_4() { string Arg0 = "........................................"; int Arg1 = 1; verify_case(4, Arg1, minMissed(Arg0)); }
	void test_case_5() { string Arg0 = "###...###"; int Arg1 = 3; verify_case(5, Arg1, minMissed(Arg0)); }
	void test_case_6() { string Arg0 = ".#.###.##...#.####.###...###.##"; int Arg1 = 15; verify_case(6, Arg1, minMissed(Arg0)); }
	void test_case_7() { string Arg0 = ".................................................##..##...##.............................."; int Arg1 = 5; verify_case(7, Arg1, minMissed(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Subrectangle ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

