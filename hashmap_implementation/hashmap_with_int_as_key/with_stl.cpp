
#include<vector>
#include<list>
using namespace std;

class MyHashMap {
    vector<list<pair<int,int>>>buckets;
    int size;
    int numOfBuckets;
public:
    MyHashMap() {
        size = 0; // no keys as of now in our hashmap
        numOfBuckets = 2069; //generally a large prime number
        buckets.resize(numOfBuckets); 
    }
    
    void put(int key, int value) {
        int index = getIndex(key);

        auto& list = buckets[index]; // get the linked list present at this bucket
        for(auto it= list.begin();it!=list.end();it++){
            if(it->first == key){
                it->second = value;
                return;
            }
        }

        list.push_back({key,value});
        size++;
        if( ( (1.0)*size/numOfBuckets) > 0.7 ) rehash();
    }
    
    int get(int key) {
        int index = getIndex(key);
        auto& list = buckets[index];

        for(auto it=list.begin();it!=list.end();it++){
            if(it->first == key) return it->second;
        }
        return -1;
    }
    
    void remove(int key) {
        int index = getIndex(key);
        auto& list = buckets[index];

        for(auto it=list.begin();it!=list.end();it++){
            if(it->first == key){
                list.erase(it);
                size--;
                return;
            }
        }
    }

private:
    int getIndex(int key){ return key%numOfBuckets;}  

    void rehash(){
        auto oldBuckets = buckets;
        int oldBucketCount = numOfBuckets;

        buckets.clear();
        buckets.resize(2*numOfBuckets);
        numOfBuckets*=2;
        size =0;

        for(int i=0;i<oldBucketCount;i++){
            auto&list = oldBuckets[i];

            for(auto it=list.begin();it!=list.end();it++){
                put(it->first,it->second);
            }
        }
    }  
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */