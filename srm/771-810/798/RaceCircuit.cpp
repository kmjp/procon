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

unordered_map<ll,ll> from;
unordered_map<ll,ll> to;
ll LR[15][15],UD[15][15],CN[15][15];
int ov[256],con[256];
ll DM[1<<12],CM[1<<12];

class RaceCircuit {
	public:
	int construct(int R, int C, vector <int> costRight, vector <int> costDown, vector <int> costCorner) {
		int mask,i,j,y,x;
		FOR(y,R) FOR(x,C) {
			LR[y][x]=costRight[y*C+x];
			if(LR[y][x]==-1) LR[y][x]=1LL<<30;
			UD[y][x]=costDown[y*C+x];
			if(UD[y][x]==-1) UD[y][x]=1LL<<30;
			CN[y][x]=costCorner[y*C+x];
		}
		
		vector<int> cand;
		FOR(mask,1<<C) if(__builtin_popcount(mask)%2==0) cand.push_back(mask);
		
		from.clear();
		FOR(mask,1<<C) {
			ll state=0;
			ll sum=0;
			int right=0,p=0;
			FOR(x,C) {
				if(mask&(1<<x)) {
					sum+=UD[0][x]+CN[0][x];
					if(right==0) {
						p=x;
					}
					else {
						state|=(p+1LL)<<(4*x);
						state|=(x+1LL)<<(4*p);
					}
					right^=1;
				}
				else {
					if(right==0) sum=1LL<<30;
				}
				if(right) sum+=LR[0][x];
			}
			if(right||state==0||sum>=1LL<<30) continue;
			from[state]=sum;
		}
		for(y=1;y<R-1;y++) {
			FOR(mask,1<<C) {
				DM[mask]=CM[mask]=0;
				FOR(x,C) if(mask&(1<<x)) DM[mask]+=UD[y][x], CM[mask]+=CN[y][x];
			}
			to.clear();
			FORR(f,from) {
				ll sum=f.second;
				ll state=f.first;
				int up=0;
				int num=0;
				FOR(x,C) {
					int s=(state>>(4*x))&15;
					if(s) up|=1<<x, ov[x]=s-1,num++;
				}
				FORR(mask,cand) {
					int down=up^mask;
					if(down==0) continue;
					ll ret=sum+DM[down]+CM[mask];
					if(ret>=1LL<<30) continue;
					int wall=up&down;
					int right=0;
					int start=-100;
					FOR(x,C) {
						if(wall&(1<<x)) {
							if(right) {
								ret=1LL<<30;
								break;
							}
							con[x]=x+100;
							con[x+100]=x;
						}
						else if(right) {
							if(up&(1<<x)) {
								con[start]=x;
								con[x]=start;
								right=0;
							}
							else if(down&(1<<x)) {
								con[start]=100+x;
								con[100+x]=start;
								right=0;
							}
						}
						else {
							if(up&(1<<x)) {
								right=1;
								start=x;
							}
							else if(down&(1<<x)) {
								right=1;
								start=100+x;
							}
							else {
								ret+=1LL<<30;
								break;
							}
						}
						if(right) ret+=LR[y][x];
					}
					if(ret>=1LL<<30) continue;
					
					ll nstate=0;
					int cover=0;
					FOR(x,C) if(down&(1<<x)) {
						int tar=con[100+x];
						while(tar<100) tar=con[ov[tar]], cover+=2;
						tar-=100;
						down^=(1<<x)|(1<<tar);
						nstate|=(x+1LL)<<(4*tar);
						nstate|=(tar+1LL)<<(4*x);
					}
					if(nstate==0) continue;
					if(cover!=num) continue;
					if(to.count(nstate)==0) to[nstate]=1LL<<30;
					to[nstate]=min(to[nstate],ret);
				}
			}
			
			swap(from,to);
		}
		ll mi=1LL<<30;
		FORR(f,from) {
			ll state=f.first;
			ll sum=f.second;
			
			FOR(x,C) {
				int s=(state>>(4*x))&15;
				sum+=LR[R-1][x];
				if(x==0&&s==0) sum+=1LL<<30;
				if(s) {
					s--;
					if(x==0&&s!=C-1) sum+=1LL<<30;
					if(x>0&&x<s&&x+1!=s) sum+=1LL<<30;
					if(x==0) sum-=LR[R-1][C-1];
					else if(x<s) sum-=LR[R-1][x];
					sum+=CN[R-1][x];
				}
			}
			mi=min(mi,sum);
		}
		
		
		
		if(mi>=1LL<<30) mi=-1;
		return mi;
		
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {10, -1,
 40, -1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {20, 30,
 -1, -1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {5, 4,
 9, 7}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 125; verify_case(0, Arg5, construct(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {0, -1,
 0, -1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-1,  0,
 -1, -1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {5, 4,
 9, 7}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = -1; verify_case(1, Arg5, construct(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 4; int Arr2[] = {1, 2, 1, -1,
 2, 1, 2, -1,
 1, 1, 1, -1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 1,  1,  1,  1,
  1,  2,  2,  1,
 -1, -1, -1, -1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {100, 100, 100, 100,
 100, 100, 100, 100,
 100, 100, 100, 100}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 812; verify_case(2, Arg5, construct(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3_() { int Arg0 = 3; int Arg1 = 4; int Arr2[] = {1, 2, 1, -1,
 2, 1, 2, -1,
 1, 1, 1, -1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 1,  1,  1,  1,
  1,  2,  2,  1,
 -1, -1, -1, -1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {100, 100, 100, 100,
 100, 100, 100, 100,
 100,  50,  50, 100}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 715; verify_case(3, Arg5, construct(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 11; int Arg1 = 12; int Arr2[] = {893, 338, 270, 609, 414, 14, 713, 797, 753, 880, 281, -1, 29, 491, 919, 957, 497, 667, 883, 713, 759, 487, 321, -1, 872, 117, 171, 659, 429, 579, 756, 607, 734, 0, 354, -1, 474, 628, 385, 459, 939, 937, 384, 256, 309, 65, 618, -1, 296, 207, 605, 552, 406, 779, 31, 486, 425, 501, 185, -1, 317, 930, 349, 750, 957, 662, 381, 8, 419, 358, 214, -1, 703, 312, 326, 513, 361, 106, 725, 615, 695, 33, 483, -1, 321, 566, 834, 291, 104, 447, 670, 998, 320, 684, 863, -1, 428, 467, 162, 82, 3, 955, 656, 553, 963, 206, 934, -1, 674, 195, 245, 265, 551, 23, 216, 774, 229, 602, 694, -1, 811, 826, 308, 810, 886, 989, 67, 709, 467, 395, 477, -1};
	vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {395, 650, 872, 611, 296, 772, 832, 660, 313, 49, 159, 347, 738, 366, 520, 564, 950, 352, 522, 102, 671, 60, 787, 188, 623, 382, 177, 429, 921, 75, 488, 890, 872, 823, 665, 150, 183, 171, 214, 842, 165, 335, 541, 475, 112, 930, 408, 460, 839, 616, 667, 230, 93, 639, 749, 90, 480, 738, 73, 241, 98, 921, 703, 199, 705, 393, 40, 112, 581, 938, 918, 100, 518, 94, 635, 586, 813, 776, 199, 381, 961, 401, 454, 596, 955, 701, 762, 881, 350, 623, 961, 119, 617, 144, 6, 450, 99, 543, 79, 208, 241, 297, 454, 216, 443, 230, 313, 712, 770, 936, 877, 189, 75, 353, 923, 298, 489, 285, 857, 993, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
	vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {421, 550, 105, 44, 964, 728, 438, 542, 89, 725, 922, 81, 495, 985, 365, 391, 60, 556, 150, 660, 822, 617, 437, 300, 666, 529, 671, 205, 320, 438, 916, 368, 71, 49, 451, 889, 388, 142, 455, 552, 142, 706, 553, 888, 179, 488, 71, 653, 888, 753, 947, 842, 635, 479, 160, 44, 333, 290, 668, 181, 584, 245, 817, 710, 575, 411, 742, 640, 895, 481, 314, 86, 684, 890, 940, 205, 712, 520, 509, 717, 504, 132, 158, 570, 173, 815, 56, 583, 631, 582, 771, 806, 37, 467, 766, 54, 659, 116, 623, 805, 940, 238, 125, 723, 555, 504, 524, 23, 930, 979, 852, 73, 675, 550, 43, 468, 898, 504, 516, 709, 531, 116, 845, 759, 815, 269, 899, 125, 648, 526, 959, 320};
	vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 715; verify_case(3, Arg5, construct(Arg0, Arg1, Arg2, Arg3, Arg4)); }
// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RaceCircuit ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

