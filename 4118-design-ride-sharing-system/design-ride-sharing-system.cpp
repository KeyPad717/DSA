class RideSharingSystem {
public:
    queue<int> rq;
    queue<int> dq;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        rq.push(riderId);
    }
    
    void addDriver(int driverId) {
        dq.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        vector<int> v(2,-1);
        if(!rq.empty() && !dq.empty()){
            v[0]=dq.front();
            v[1]=rq.front();
            dq.pop();
            rq.pop();
            return v;
        }
        return v;
    }
    
    void cancelRider(int riderId) {
        vector<int> v1;
        while(!rq.empty()){
            if(rq.front()==riderId){
                rq.pop();
                continue;
            }
            v1.push_back(rq.front());
            rq.pop();
        }
        for(int i=0;i<v1.size();i++){
            rq.push(v1[i]);
        }
        //if(rq.front()==riderId)    rq.pop();
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */