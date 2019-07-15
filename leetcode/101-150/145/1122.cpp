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

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		vector<int> A,B;
		map<int,int> M;
		FORR(a,arr1) {
			if(count(ALL(arr2),a)) {
				M[a]++;
			}
			else {
				B.push_back(a);
			}
		}
		
		FORR(a,arr2) {
			while(M[a]) A.push_back(a),M[a]--;
		}
		sort(ALL(B));
		FORR(b,B) A.push_back(b);
		return A;
		
        
    }


};

