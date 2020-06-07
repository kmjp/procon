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
    vector<int> getStrongest(vector<int>& arr, int k) {
		sort(ALL(arr));
		int m=(arr.size()+1)/2-1;
		int L=0,R=arr.size()-1;
		vector<int> ret;
		while(ret.size()<k) {
			if(abs(arr[L]-arr[m])>abs(arr[R]-arr[m])) {
				ret.push_back(arr[L++]);
			}
			else {
				ret.push_back(arr[R--]);
			}
			
		}
		return ret;
        
    }
};

