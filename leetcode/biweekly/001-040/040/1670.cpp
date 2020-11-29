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





class FrontMiddleBackQueue {
public:
deque<int> A,B;
    FrontMiddleBackQueue() {
        A.clear();
        B.clear();
    }
    
    void pushFront(int val) {
        A.push_front(val);
        hoge();
    }
    
    void pushMiddle(int val) {
        A.push_back(val);
        hoge();
        
    }
    
    void pushBack(int val) {
        B.push_back(val);
        hoge();
    }
    void hoge() {
		while(A.size()>B.size()) {
			B.push_front(A.back());
			A.pop_back();
		}
		while(A.size()+1<B.size()) {
			A.push_back(B.front());
			B.pop_front();
		}
		/*
		FORR(a,A) cout<<a;
		cout<<":";
		FORR(a,B) cout<<a;
		cout<<endl;
		*/
	}
    int popFront() {
		int ret=-1;
		if(A.size()) {
			ret=A.front();
			A.pop_front();
		}
		else if(B.size()) {
			ret=B.front();
			B.pop_front();
		}
		
        hoge();
        return ret;
    }
    
    int popMiddle() {
		int ret=-1;
		if(A.size()==B.size()&&A.size()) {
			ret=A.back();
			A.pop_back();
		}
		else if(B.size()) {
			ret=B.front();
			B.pop_front();
		}
        hoge();
        return ret;
    }
    
    int popBack() {
		int ret=-1;
		if(B.size()) {
			ret=B.back();
			B.pop_back();
		}
		else if(A.size()) {
			ret=A.back();
			A.pop_back();
		}
        hoge();
        return ret;
        
    }
};
