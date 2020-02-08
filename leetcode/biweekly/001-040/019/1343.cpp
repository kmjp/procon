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
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
		vector<int> V;
		V.push_back(0);
		int num=0;
		int X=threshold*k;
		FORR(v,arr) {
			V.push_back(v+V.back());
			if(V.size()>k) {
				int b=V.back()-V[V.size()-k-1];
				cout<<b<<endl;
				if(b>=X) num++;
			}
		}
		
		return num;
		
        
    }
};


