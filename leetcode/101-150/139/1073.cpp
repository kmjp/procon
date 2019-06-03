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


class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> R(2040);
        int i;
        reverse(ALL(arr1));
        reverse(ALL(arr2));
        FOR(i,2010) {
			if(i<arr1.size()) R[i]+=arr1[i];
			if(i<arr2.size()) R[i]+=arr2[i];
			R[i+2]+=R[i]/2;
			R[i+1]+=R[i]/2;
			R[i]%=2;
		}
        while(R.size()>1&&R.back()==0) R.pop_back();
        if(R.size()>2010) {
	        R.pop_back();
	        R.pop_back();
	    }
        while(R.size()>1&&R.back()==0) R.pop_back();
        reverse(ALL(R));
        return R;
    }
};

