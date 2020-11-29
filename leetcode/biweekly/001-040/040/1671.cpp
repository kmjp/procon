typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))

//-------------------------------------------------------

int del[1010][3];

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int N=nums.size();
        int i,j;
        int mi=N-1;
        for(j=0;j<N;j++) {
			del[j][0]=j;
			del[j][1]=del[j][2]=1<<20;
			FOR(i,j) {
				if(nums[i]<nums[j]) {
					del[j][1]=min(del[j][1],del[i][0]+(j-i-1));
					del[j][1]=min(del[j][1],del[i][1]+(j-i-1));
				}
				if(nums[i]>nums[j]) {
					del[j][2]=min(del[j][2],del[i][1]+(j-i-1));
					del[j][2]=min(del[j][2],del[i][2]+(j-i-1));
				}
			}
			cout<<j<<" "<<del[j][0]<<del[j][1]<<del[j][2]<<endl;
			mi=min(mi,N-1-j+del[j][2]);
		}
		return mi;
    }
};
