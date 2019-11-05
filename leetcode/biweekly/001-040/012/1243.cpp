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
    vector<int> transformArray(vector<int>& arr) {
		int i,j;
		FOR(i,10100) {
			vector<int> V=arr;
			FOR(j,arr.size()) {
				arr[j]=V[j];
				if(j>0 && j<arr.size()-1) {
					if(V[j]<V[j+1]&&V[j]<V[j-1]) arr[j]++;
					if(V[j]>V[j+1]&&V[j]>V[j-1]) arr[j]--;
				}
				
			}
			
		}
        return arr;
    }
};
