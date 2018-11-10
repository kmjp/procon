typedef signed long long ll;
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)


class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        map<int,int> M;
        ll ret=0;
        M[0]=1;
        int cur=0;
        FORR(a,A) {
            cur+=a;
            ret+=M[cur-S];
            M[cur]++;
        }
        return ret;
    }
};
