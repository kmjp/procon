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



class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
		sort(ALL(nums));
		ll L=0,cur=0,R=0;
		ll sum=nums[0];
		ll ma=0;
		ll N=nums.size();
		for(ll L=0,cur=0,R=0;cur<N;cur++) {
			if(R<cur) {
				R=cur;
				sum+=nums[cur];
			}
			sum+=nums[cur]*(cur-L);
			sum-=nums[cur]*(R-cur+1);
			while(sum>k) {
				sum-=nums[cur]-nums[L];
				L++;
			}
			//cout<<L<<" "<<cur<<" "<<R<<" "<<sum<<endl;
			while(1) {
				//cout<<"#"<<L<<" "<<cur<<" "<<R<<" "<<sum<<endl;
				if(R+1<N&&L<cur&&(nums[R+1]-nums[cur])<=(nums[cur]-nums[L])) {
					sum+=(nums[R+1]-nums[cur]);
					sum-=(nums[cur]-nums[L]);
					R++;
					L++;
				}
				else if(R+1<N&&L>0&&(nums[R+1]-nums[cur])<=(nums[cur]-nums[L-1])) {
					if(sum+nums[R+1]-nums[cur]>k) break;
					sum+=nums[R+1]-nums[cur];
					R++;
				}
				else if(R+1<N&&L>0&&(nums[R+1]-nums[cur])>=(nums[cur]-nums[L-1])) {
					if(sum+nums[cur]-nums[L-1]>k) break;
					sum+=nums[cur]-nums[L-1];
					L--;
				}
				else if(R+1<N&&L==0) {
					if(sum+nums[R+1]-nums[cur]>k) break;
					sum+=nums[R+1]-nums[cur];
					R++;
				}
				else if(L>0&&R==N-1) {
					if(sum+nums[cur]-nums[L-1]>k) break;
					sum+=nums[cur]-nums[L-1];
					L--;
				}
				else {
					return N;
				}
			}
			ma=max(ma,R-L+1);
			sum-=nums[cur]*(cur-L);
			sum+=nums[cur]*(R-cur);
			sum-=nums[cur];
		}
        return ma;
    }
};
