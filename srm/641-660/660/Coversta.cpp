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

class Coversta {
	public:
	int H,W,N;
	int sum[101][101];
	vector <int> X,Y;
	vector <string> a;
	
	int dodo(int x1,int y1,int x2,int y2) {
		int i;
		int tot=0;
		vector<pair<int,int> > S;
		FOR(i,N) S.push_back(make_pair(y1+X[i],x1+Y[i]));
		FOR(i,N) S.push_back(make_pair(y2+X[i],x2+Y[i]));
		sort(S.begin(),S.end());
		S.erase(unique(S.begin(),S.end()),S.end());
		FORR(r,S) {
			if(r.first<0) continue;
			if(r.second<0) continue;
			if(r.first>=H) continue;
			if(r.second>=W) continue;
			tot += a[r.first][r.second]-'0';
		}
		return tot;
	}
	
	int place(vector <string> a, vector <int> X, vector <int> Y) {
		this->X=X;
		this->Y=Y;
		this->a=a;
		H=a.size(),W=a[0].size();
		N=X.size();
		vector<pair<int,pair<int,int> > > SS;
		
		int y,x,i,j;
		set<pair<int,int> > S;
		FOR(y,H) FOR(x,W) {
			sum[y][x]=0;
			FOR(i,N) {
				int cy=y+X[i],cx=x+Y[i];
				if(cy>=0 && cy<H && cx>=0 && cx<W) sum[y][x] += a[cy][cx]-'0';
			}
			SS.push_back(make_pair(-sum[y][x],make_pair(x,y)));
		}
		
		sort(SS.begin(),SS.end());
		if(SS.size()>105) SS.resize(105);
		int ma=0;
		FOR(y,SS.size()) FOR(x,y) ma=max(ma,dodo(SS[y].second.first,SS[y].second.second,SS[x].second.first,SS[x].second.second));
		return ma;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"11",
 "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(0, Arg3, place(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"11",
 "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(1, Arg3, place(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"15",
 "61"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 11; verify_case(2, Arg3, place(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"151",
 "655",
 "661"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,1,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 33; verify_case(3, Arg3, place(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"303",
 "333",
 "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 12; verify_case(4, Arg3, place(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"0000000",
 "1010101"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(5, Arg3, place(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Coversta ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
