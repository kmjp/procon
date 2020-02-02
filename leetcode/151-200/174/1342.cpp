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
    int minSetSize(vector<int>& arr) {
		map<int,int> M;
		int num=arr.size();
		FORR(m,arr) M[m]++;
		vector<int> V;
		FORR(m,M) V.push_back(m.second);
		sort(ALL(V));
		int sum=0;
		int ret=0;
		while(sum<num/2) {
			ret++;
			sum+=V.back();
			V.pop_back();
		}
		return ret;
		
		
        
    }
};

