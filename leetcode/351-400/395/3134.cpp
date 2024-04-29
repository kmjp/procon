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

int nex[101010];
int C[101010];
class Solution {
public:


    int medianOfUniquenessArray(vector<int>& nums) {
		unordered_map<int,int> M;
        int N=nums.size();
        ll pat=1LL*N*(N+1)/2;
        pat=(pat%2)?(pat+1)/2:(pat/2+1);
        int ret=1;
        int i;
        for(i=20;i>=0;i--) if(ret+(1<<i)<=N) {
			M.clear();
			ll sum=0;
			for(int L=0,R=0;L<N;L++) {
				R=max(R,L);
				while(R<N&(M.size()<ret+(1<<i))) M[nums[R]]++,R++;
				if(M.size()>=ret+(1<<i)) sum+=N+1-R;
				if(--M[nums[L]]==0) M.erase(nums[L]);
			}
			if(sum>=pat) ret+=1<<i;
		}
        return ret;
        
    }
};
