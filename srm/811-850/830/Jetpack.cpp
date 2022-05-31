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

ll dp[55][55][2];

class Jetpack {
	public:
	int travel(vector <string> S, int T) {
		int H=S.size();
		int W=S[0].size();
		int x,y,i;
		FOR(y,H) cout<<S[y].size()<<endl;
		FOR(y,H) FOR(x,W) FOR(i,2) dp[y][x][i]=1LL<<60;
		int sx,sy,gx,gy;
		priority_queue<pair<ll,int>> Q;
		FOR(y,H) FOR(x,W) {
			if(S[y][x]=='A') {
				sx=x,sy=y;
				S[y][x]='.';
				dp[y][x][0]=0;
				Q.push({0,y*50+x});
			}
			if(S[y][x]=='B') {
				gx=x,gy=y;
				S[y][x]='.';
			}
		}
		while(Q.size()) {
			ll co=-Q.top().first;
			int cy=Q.top().second/50%50;
			int cx=Q.top().second%50;
			int num=Q.top().second/2500;
			Q.pop();
			if(dp[cy][cx][num]!=co) continue;
			if(cy==gy&&cx==gx) return co;
			
			if(S[cy][cx]=='C') {
				if(dp[cy][cx][1]>co) {
					dp[cy][cx][1]=co;
					Q.push({-dp[cy][cx][1],(1)*2500+cy*50+cx});
				}
			}
			int d[4]={0,1,0,-1};
			FOR(i,4) {
				int ty=cy+d[i];
				int tx=cx+d[i^1];
				if(ty<0||ty>=H||tx<0||tx>=W) continue;
				if(S[ty][tx]=='#') continue;
				if(S[ty][tx]=='_'&&num==0) continue;
				if(dp[ty][tx][num]>co+1+(S[ty][tx]=='_')*T) {
					dp[ty][tx][num]=co+1+(S[ty][tx]=='_')*T;
					Q.push({-dp[ty][tx][num],num*2500+ty*50+tx});
				}
			}
			
		}
		
		return -1;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"A###B",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 47; int Arg2 = 6; verify_case(0, Arg2, travel(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"A#.#B",
 "..#.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 47; int Arg2 = -1; verify_case(1, Arg2, travel(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"A#.#B",
 ".._C."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = -1; verify_case(2, Arg2, travel(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"B_C_C_CA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 37; verify_case(3, Arg2, travel(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"___B__.",
 "C#####.",
 "AC....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 8; verify_case(4, Arg2, travel(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"___B__.",
 "C#####.",
 "AC....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 31; verify_case(5, Arg2, travel(Arg0, Arg1)); }


// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Jetpack ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

