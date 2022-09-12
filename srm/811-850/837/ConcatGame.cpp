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

ll N[10];

int len[13];
string S[13];

int dp[66][6][1<<13];

int cmp[66][66][66];

class ConcatGame {
	public:
	string analyze(vector <int> upperBounds, string claim) {
		N[0]=1;
		int i,j;
		ll sum=0;
		for(i=1;i<=6;i++) {
			N[i]=N[i-1]*26;
			sum+=N[i];
		}
		int M=upperBounds.size();
		FOR(i,M) {
			len[i]=1;
			int x=upperBounds[i];
			while(N[len[i]]<x) {
				x-=N[len[i]];
				len[i]++;
			}
			S[i]="";
			x--;
			FOR(j,len[i]) {
				S[i]+='a'+(x%26);
				x/=26;
			}
			reverse(ALL(S[i]));
		}
		
		int C=claim.size();
		if(C>65) return "lie";
		
		int a,b,c,d;
		FOR(a,C) for(b=0;a+b<=C;b++) {
			string s=claim.substr(a,b);
			for(c=0;a+b+c<=C;c++) {
				string t=claim.substr(a+b,c);
				cmp[a][b][c]=s+t<t+s;
			}
		}
		
		ZERO(dp);
		dp[0][0][0]=1;
		for(int cur=0;cur<C;cur++) {
			for(int plen=0;plen<=5;plen++) {
				if(plen>cur) continue;
				for(int mask=0;mask<1<<M;mask++) if(dp[cur][plen][mask]) {
					for(j=1;j<=5;j++) {
						if(cur+j>C) continue;
						string now=claim.substr(cur,j);
						FOR(i,M) if((mask&(1<<i))==0) {
							if(j>len[i]||(j==len[i]&&now>S[i])) continue;
							if(cmp[cur-plen][plen][j]) {
								dp[cur+j][j][mask|(1<<i)]|=2;
							}
							else {
								dp[cur+j][j][mask|(1<<i)]|=dp[cur][plen][mask];
							}
						}
					}
				}
			}
		}
		
		int pat=0;
		for(int plen=0;plen<=5;plen++) pat|=dp[C][plen][(1<<M)-1];
		cout<<pat<<endl;
		if(pat==0) return "lie";
		if(pat==1) return "good";
		if(pat==2) return "bad";
		if(pat==3) return "unknown";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "go"; string Arg2 = "lie"; verify_case(0, Arg2, analyze(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {26, 26}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "go"; string Arg2 = "bad"; verify_case(1, Arg2, analyze(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {30, 20, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "salad"; string Arg2 = "good"; verify_case(2, Arg2, analyze(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {30, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "abc"; string Arg2 = "bad"; verify_case(3, Arg2, analyze(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {200, 200}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "dad"; string Arg2 = "unknown"; verify_case(4, Arg2, analyze(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {10, 100, 1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "topcoder"; string Arg2 = "lie"; verify_case(5, Arg2, analyze(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {10, 100, 1000, 10000, 100000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "topcoder"; string Arg2 = "bad"; verify_case(6, Arg2, analyze(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ConcatGame ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

