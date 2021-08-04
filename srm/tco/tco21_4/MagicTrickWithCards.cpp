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

class MagicTrickWithCards {
	public:
	vector <int> findTheirCard(vector <string> queryCards, vector <int> queryX) {
		vector<int> R;
		int i,x,y;
		FOR(i,queryCards.size()) {
			string S=queryCards[i];
			int num=0;
			FORR(c,S) {
				if(c!='-') c='o';
				else num++;
			}
			int ma[52]={};
			int be=0;
			FOR(x,52) {
				FOR(y,52) if(S[(x+y)%52]=='-') break;
				ma[x]=y;
				if(ma[x]>ma[be]) be=x;
			}
			int lef=num-queryX[i];
			FOR(x,52) {
				if(S[(x+be)%52]=='-') {
					lef--;
					if(lef==0) {
						R.push_back((x+be)%52);
						break;
					}
				}
			}
			assert(R.size()==i+1);
		}
		return R;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"ncmN-z-yG--q-v-K-D-J-B--e----i-p-Q-s-F-d-ZjaxgfbOHAS",
 "NdyuiS--C-t-Q-D--Ys-n-q-K-r-ex-J-l-AHcVvBmbwagETGLjo",
 "m-fI-j-Y--u-D-rioGLXWsqdFpwESeBPhTAvU-Q-M-t-V-c--N-C",
 "MF-l-W-yVc-p-N-b-Y-L--f-s--KqwoeIvJaDuETdRQ-z-m-k-U-",
 "F-n-b-UqCQZHVBuLcXszgaRoN-J-P-M-Y--Gd--lf--k-v-K-E--",
 "s-f--c-M-vZHCjLDFgPbndeR-o-N-y-G-O-V-S-TUWYp-h-K--u-",
 "HAdJblNSWt-c-m-r-Y-p-w-X-eZ-Ky--T-E--FQ--IOsvkVBCMRj",
 "o-pm-w--S-Ez-K-J-eRubcxXAIVFMlg-i-a--BH-W-Q-k-ZU-C--",
 "-y-B-A-b-HXGOIacWPELuJTzsUjSQFKlD-n-m-Y-Z-ek--w--x-r",
 "laHpnNmQIzgRVFYh-M-d-Sb--c-JX-U--T---e-B--u-x-w-o-Z-",
 "K-O-mG-w-y--H-J-F-B--T-e-I-tQ-qS-x--jNLpMvsEcVfnYuD-",
 "-y-K-uOEqrPaTeXcwRNpUhf-i-xF-H-v--C-ZM-d-----jB-o-bl",
 "-L-I--oAF-P-h--S-W-g-U-steEKXafxCbRVluYmGNJjQr-T-c-H",
 "-B-e--WlzETxGNJVKtrQMHbSwRCPp-L-I-X-f-g-k-F--s-m-y-n",
 "Q--Vp-s-lUNfHzwFWdOnLrMcAmDkKC-x-P-J--R-j-B-g--hS--a",
 "C-Ji-m-l-z-BuDK-o--YV--Ae-n-S-v-pTMPGqhZdHIEOaNUr-g-",
 "-j-w-am-v----c-Xi-R-W-kH-guAFOTlZBJKSnNqUo-M--d-E--s",
 "-g-W-i-C-O--XRQhKTfYvDewIJFrdxctM-o-j-m--b-pA-y-uZ-B",
 "V-mw-r-l-k-zy-K-f-pUNxJM--h-W--b-T--t-IYCBQnAsXPdiEa",
 "D--S-e-J-cv-ZE-P-M-W-lhmRACudQsTpgIwGinBKx-b-z-j-a-H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 1, 2, 1, 4, 4, 1, 1, 0, 0, 0, 2, 3, 3, 2, 4, 0, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {9, 5, 11, 23, 23, 1, 33, 14, 6, 23, 23, 4, 18, 0, 1, 27, 14, 51, 34, 16 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, findTheirCard(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MagicTrickWithCards ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

