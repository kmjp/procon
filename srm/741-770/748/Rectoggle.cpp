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

int gr[1010][1010];
int gr2[1010][1010];

class Rectoggle {
	public:
	int MH,MW;
	
	int nim(int y,int x) {
		if(gr[y][x]!=-1) return gr[y][x];
		gr[y][x]=1;
		set<int> S;
		
		for(int r=1;r<=min(MH,y);r++) {
			int cur=0;
			for(int c=1;c<=min(MW,x);c++) {
				for(int cy=1;cy<=r;cy++) {
					if(cy!=1 || c!=1) cur^=nim(y-(cy-1),x-(c-1));
				}
				if(r!=1 || c!=1) S.insert(cur);
			}
		}
		while(S.count(gr[y][x])) gr[y][x]++;
		return gr[y][x];
	}
	int nim2(int y,int x) {
		int cy=0,cx=0;
		y=(y-1)%MH+1;
		x=(x-1)%MW+1;
		
		while(y&(1<<cy)) cy++;
		while(x&(1<<cx)) cx++;
		return nim3(cy,cx);
	}
	int nim3(int y,int x) {
		if(gr2[y][x]!=-1) return gr2[y][x];
		gr2[y][x]=1;
		set<int> S;
		
		for(int r=1;r<=min(MH,y+1);r++) {
			int cur=0;
			for(int c=1;c<=min(MW,x+1);c++) {
				for(int cy=1;cy<=r;cy++) {
					if(cy!=1 || c!=1) cur^=nim3(y-(cy-1),x-(c-1));
				}
				if(r!=1 || c!=1) S.insert(cur);
			}
		}
		while(S.count(gr2[y][x])) gr2[y][x]++;
		return gr2[y][x];
	}
	int whoWins(vector <int> ledrow, vector <int> ledcol, int maxrows, int maxcols) {
		MINUS(gr);
		
		MH=MW=1;
		while(MH*2<maxrows) MH*=2;
		while(MW*2<maxrows) MW*=2;
		int sum=0;
		for(int i=0;i<ledrow.size();i++) {
			int y=ledrow[i];
			int x=ledcol[i];
			sum^=nim(y,x);
		}
		
		for(MH=1;MH<=16;MH*=2) {
			for(MW=1;MW<=16;MW*=2) {
				MINUS(gr);
				MINUS(gr2);
				cout<<"!"<<MH<<" "<<MW<<endl;
				int y,x;
				for(y=1;y<=20;y++) {
					for(x=1;x<=20;x++) cout<<nim(y,x)<<" ";
					cout<<endl;
				}
			}
		}
		
		if(sum==0) return 2;
		return 1;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 7; int Arg4 = 2; verify_case(0, Arg4, whoWins(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0,0,0,0,1,1,1,1,2,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2,3,0,1,2,3,0,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 4; int Arg4 = 1; verify_case(1, Arg4, whoWins(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {0,0,0,0,1,1,1,1,2,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2,3,0,1,2,3,0,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 1; int Arg4 = 2; verify_case(2, Arg4, whoWins(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {100,101,102}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100,101,102}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 7; int Arg4 = 1; verify_case(3, Arg4, whoWins(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {1,1,2,3,5,8,13,21}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,5,8,13,21,34}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 7; int Arg4 = 1; verify_case(4, Arg4, whoWins(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Rectoggle ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

