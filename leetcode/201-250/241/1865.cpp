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


class FindSumPairs {
public:
vector<int> A,B;
unordered_map<int,int> M;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        A=nums1;
        B=nums2;
        M.clear();
        FORR(n,nums2) M[n]++;
    }
    
    void add(int index, int val) {
		M[B[index]]--;
		B[index]+=val;
		M[B[index]]++;
    }
    
    int count(int tot) {
        ll sum=0;
        FORR(n,A) sum+=M[tot-n];
        return sum;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
 