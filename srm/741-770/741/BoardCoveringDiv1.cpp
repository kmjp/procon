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

class BoardCoveringDiv1 {
	public:
	vector <string> make(int N, int R, int C) {
		if(N%3==0) return {};
		vector<string> V;
		int i,j,k,y,x;
		FOR(i,N) V.push_back(string(N,'.'));
		V[R][C]='#';
		
		if(N==1) return V;
		
		vector<pair<int,int>> cand;
		int SL=0,SR=N-1;
		int SU=0,SD=N-1;
		while(SR-SL>=4 && SL+3<=C) {
			for(y=SU;y<=SD;y++) cand.push_back({SL,y}), cand.push_back({SL+1,y}), cand.push_back({SL+2,y});
			SL+=3;
		}
		while(SR-SL>=4 && C<=SR-3) {
			for(y=SU;y<=SD;y++) cand.push_back({SR,y}), cand.push_back({SR-1,y}), cand.push_back({SR-2,y});
			SR-=3;
		}
		while(SD-SU>=4 && SU+3<=R) {
			for(x=SL;x<=SR;x++) cand.push_back({x,SU}), cand.push_back({x,SU+1}), cand.push_back({x,SU+2});
			SU+=3;
		}
		while(SD-SU>=4 && R<=SD-3) {
			for(x=SL;x<=SR;x++) cand.push_back({x,SD}), cand.push_back({x,SD-1}), cand.push_back({x,SD-2});
			SD-=3;
		}
		
		if((SR-SL+1)*(SD-SU+1)%2==0) {
			vector<pair<int,int>> C2;
			if((SD-SU+1)%2==0) {
				for(y=SU;y<=SD;y++) {
					if((y-SU)%2==0) {
						for(x=SR-1;x>=SL;x--) C2.push_back({x,y});
					}
					else {
						for(x=SL;x<=SR-1;x++) C2.push_back({x,y});
					}
				}
				for(y=SD;y>=SU;y--) C2.push_back({SR,y});
			}
			else {
				for(x=SL;x<=SR;x++) {
					if((x-SL)%2==0) {
						for(y=SD-1;y>=SU;y--) C2.push_back({x,y});
					}
					else {
						for(y=SU;y<=SD-1;y++) C2.push_back({x,y});
					}
				}
				for(x=SR;x>=SL;x--) C2.push_back({x,SD});
			}
			auto it=find(ALL(C2),make_pair(C,R));
			rotate(C2.begin(),it,C2.end());
			C2.erase(C2.begin());
			FORR(c,C2) cand.push_back(c);
		}
		else if(SR-SL==4 && SD-SU==4) {
			for(x=SL;x<=SR;x++) cand.push_back({x,SU});
			for(x=SR;x>=SL;x--) cand.push_back({x,SU+1});
			cand.push_back({SL,SU+2});
			cand.push_back({SL+1,SU+2});
			cand.push_back({SL+1,SU+3});
			cand.push_back({SL,SU+3});
			cand.push_back({SL,SU+4});
			cand.push_back({SL+1,SU+4});
			cand.push_back({SL+2,SU+4});
			cand.push_back({SL+2,SU+3});
			cand.push_back({SL+3,SU+3});
			cand.push_back({SL+3,SU+4});
			cand.push_back({SL+4,SU+4});
			cand.push_back({SL+4,SU+3});
			cand.push_back({SL+4,SU+2});
			cand.push_back({SL+3,SU+2});
		}
		
		for(i=0;i<cand.size();i+=3) {
			set<char> S;
			for(j=i;j<i+3;j++) {
				int dd[4]={0,1,0,-1};
				FOR(k,4) {
					int ty=cand[j].second+dd[k];
					int tx=cand[j].first+dd[k^1];
					if(tx<0 || tx>=N || ty<0 || ty>=N) continue;
					S.insert(V[ty][tx]);
				}
			}
			char ret='0';
			while(S.count(ret)) ret++;
			for(j=i;j<i+3;j++) V[cand[j].second][cand[j].first]=ret;
		}
		return V;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 0; string Arr3[] = {"#" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, make(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 1; int Arg2 = 1; string Arr3[] = {"0011", "0#21", "3220", "3300" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, make(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 1; int Arg2 = 5; string Arr3[] = {"1123344", "12235#4", "0066557", "0446877", "1242889", "1232299", "1233000" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, make(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BoardCoveringDiv1 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

