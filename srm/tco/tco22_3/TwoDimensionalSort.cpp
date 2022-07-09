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

int Y[26],X[26];
vector<int> ret;
vector <string> S;
class TwoDimensionalSort {
	public:
	void move(int r1,int c1,int r2,int c2) {
		if(r1==r2&&c1==c2) return;
		int dy=0;
		
		ret.push_back(r1);
		ret.push_back(c1);
		ret.push_back(r2);
		ret.push_back(c2);
		swap(S[r1][c1],S[r2][c2]);
	}
	vector <int> sortLetters(vector <string> board) {
		S=board;
		int N=26;
		MINUS(X);
		MINUS(Y);
		int y,x,i;
		
		ret.clear();
		int TX[26]={};
		MINUS(TX);
		int nex=0;
		FOR(y,N) {
			int cnt=0;
			deque<pair<int,int>> V;
			FOR(x,N) if(S[y][x]!='.') V.push_back({x,nex++});
			while(V.size()) {
				FOR(i,V.size()) {
					if(V[i].first==V[i].second) {
						V.erase(V.begin()+i);
						break;
					}
					int L,R;
					if(V[i].first<V[i].second) {
						L=V[i].first+1;
						R=V[i].second;
					}
					else {
						L=V[i].second;
						R=V[i].first-1;
					}
					for(x=L;x<=R;x++) if(S[y][x]!='.') break;
					if(x==R+1) {
						move(y,V[i].first,y,V[i].second);
						V.erase(V.begin()+i);
						break;
					}
					
					
				}
			}
		}
		
		FOR(y,N) FOR(x,N) if(S[y][x]!='.') {
			move(y,x,S[y][x]-'A',x);
		}
		FOR(y,N) cout<<S[y]<<endl;
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 ".........................."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, sortLetters(Arg0)); }
	void test_case_1() { string Arr0[] = {"..........................",
 "..........................",
 "......B...................",
 "..............Q...........",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 ".........................."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 14, 3, 17 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, sortLetters(Arg0)); }
	void test_case_2() { string Arr0[] = {"..........................",
 "..........................",
 "..........................",
 ".....BCDE.................",
 ".....F....................",
 ".....G.A..................",
 ".....H....................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 ".........................."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 7, 5, 9, 5, 9, 2, 9 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, sortLetters(Arg0)); }
	void test_case_3() { string Arr0[] = {"..........................",
 "..........................",
 "..........................",
 ".....BCED.................",
 ".....F....................",
 ".....G.A..................",
 ".....H....................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 "..........................",
 ".........................."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 7, 2, 7, 2, 7, 2, 11, 5, 7, 0, 7, 2, 11, 3, 11 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, sortLetters(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TwoDimensionalSort ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

