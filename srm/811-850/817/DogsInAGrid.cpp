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



class DogsInAGrid {
	public:
	vector <string> construct(int N) {
		
		vector<string> R;
		int y,x;
		string S="OOGOOOGOOOGOOOGOOOGOOOGOOOGOOOGOOOGOOOGO";
		int tot=0;
		FOR(y,40) R.push_back(S);
		for(int x=0;x<=36;x+=4) {
			FOR(y,40) {
				int num=0;
				if(x>=2) num+=1+(y>=2)+(y<=37);
				if(x+2<=39) num+=1+(y>=2)+(y<=37);
				if(tot+num<=N) {
					R[y][x]='D';
					tot+=num;
				}
				
			}
		}
		for(y=2;y<=37;y+=4) R[y][39]='G';
		for(y=0;y<=39;y+=4) {
			int num=0;
			if(y+2<=37) num++;
			if(y-2>=0) num++;
			if(tot+num<=N) {
				R[y][39]='D';
				tot+=num;
			}
		}
		
		
		int sum=0;
		int dy[9]={1,1,1,0,0,0,-1,-1,-1};
		int dx[9]={1,0,-1,1,0,-1,1,0,-1};
		
		FOR(y,40) FOR(x,40) if(R[y][x]=='D') {
			int d;
			FOR(d,9) {
				if(y+dy[d]*2<0||y+dy[d]*2>=40) continue;
				if(x+dx[d]*2<0||x+dx[d]*2>=40) continue;
				if(R[y+dy[d]][x+dx[d]]!='O') continue;
				if(R[y+dy[d]*2][x+dx[d]*2]!='G') continue;
				sum++;
			}
		}
		assert(sum==N);
		return R;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 4; string Arr1[] = {"DGODD", "OOGOG", "GOGDD" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, construct(Arg0)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = {"OOOOO", "OODOO", "ODOGO", "OOGOO", "OOOOO" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, construct(Arg0)); }
	void test_case_2() { int Arg0 = 7; string Arr1[] = {"DOGDOGDOGDOGDOGODOG" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, construct(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DogsInAGrid ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

