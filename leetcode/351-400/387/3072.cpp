#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt1,bt2;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
		auto A=nums;
		int N=A.size();
		sort(ALL(nums));
		vector<int> X,Y;
		int step=0;
		FORR(a,A) {
			a=lower_bound(ALL(nums),a)-nums.begin();
			if(step==0) {
				X.push_back(a);
				bt1.add(a,1);
			}
			else if(step==1) {
				Y.push_back(a);
				bt2.add(a,1);
			}
			else {
				if(bt1(N)-bt1(a)>bt2(N)-bt2(a)) {
					X.push_back(a);
					bt1.add(a,1);
				}
				else if(bt1(N)-bt1(a)<bt2(N)-bt2(a)) {
					Y.push_back(a);
					bt2.add(a,1);
				}
				else if(X.size()<=Y.size()) {
					X.push_back(a);
					bt1.add(a,1);
				}
				else {
					Y.push_back(a);
					bt2.add(a,1);
				}
				
			}
			step++;
		}
        
		FORR(a,X) {
			bt1.add(a,-1);
			a=nums[a];
		}
		FORR(a,Y) {
			bt2.add(a,-1);
			X.push_back(nums[a]);
		}
		return X;
			
    }
};
