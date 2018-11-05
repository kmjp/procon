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


template<int um> class UF {
	public:
	vector<int> par,rank;
	UF() {rank=vector<int>(um,0); for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};

vector<pair<int,int>> V[50][50];

class BoardCoveringDiv2 {
	public:
	
	int N;
	vector <string> make(vector <string> B) {
		UF<3000> uf;
		N=B.size();
		int i,y,x;
		
		FOR(y,N) FOR(x,N) {
			V[y][x].clear();
			if(y && B[y][x]==B[y-1][x]) uf(y*N+x,(y-1)*N+x);
			if(x && B[y][x]==B[y][x-1]) uf(y*N+x,y*N+x-1);
		}
		
		FOR(y,N) FOR(x,N) {
			V[uf[y*N+x]/N][uf[y*N+x]%N].push_back({x,y});
		}
		
		FOR(y,N) FOR(x,N) if((B[y][x]<'0' || B[y][x]>'9')&&B[y][x]!='#') {
			vector<pair<int,int>> C=V[uf[y*N+x]/N][uf[y*N+x]%N];
			set<char> S;
			FORR(c,C) {
				int dd[4]={0,1,0,-1};
				FOR(i,4) {
					int ty=c.second+dd[i];
					int tx=c.first+dd[i^1];
					if(tx<0 || tx>=N || ty<0 || ty>=N) continue;
					S.insert(B[ty][tx]);
				}
			}
			char ret='0';
			while(S.count(ret)) ret++;
			FORR(c,C) B[c.second][c.first]=ret;
		}
		return B;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"#a",
 "aa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"#0", "00" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, make(Arg0)); }
	void test_case_1() { string Arr0[] = {"AAAE",
 "BBBE",
 "CCCE",
 "DDD#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0001", "2221", "0001", "111#" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, make(Arg0)); }
	void test_case_2() { string Arr0[] = {"ABCCC",
 "ABAAA",
 "AB#EF",
 "GGGEF",
 "HHHEF"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"01000", "01222", "01#01", "22201", "11101" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, make(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BoardCoveringDiv2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

