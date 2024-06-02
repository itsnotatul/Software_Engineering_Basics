class mapnode{
public:
    int key;
    int value;
    mapnode* next;
    mapnode(int _key, int _value): key(_key),value(_value),next(nullptr){}
    ~mapnode(){delete next;}  // helpful in sequential deletion. khud se delete hojaegi nodes saari  
};


class MyHashMap {
mapnode** buckets;
int numOfBuckets; 
int size;   
public:
    MyHashMap() {
        size =0; // no keys as of now in our hashmap
        numOfBuckets = 2069; // generally a large prime number
        buckets = new mapnode*[numOfBuckets];
        for(int i=0;i<numOfBuckets;i++){ buckets[i] = nullptr;}
    }
    
    void put(int _key, int _value) {
        int index = getIndex(_key);
        auto head = buckets[index];
        while(head!=nullptr){
            if(head->key == _key){
                head->value = _value;
                return;
            }
            head = head->next;
        }
        head = buckets[index];
        auto newHead = new mapnode(_key,_value);
        newHead->next = head;
        buckets[index] = newHead;
        size++;
        if(1.0*(size)/(numOfBuckets) > (0.7)) rehash();
    }
    
    int get(int _key) {
        int index = getIndex(_key);
        auto head = buckets[index];
        while(head!=nullptr){
            if(head->key == _key){
                return head->value;
            }
            head = head->next;
        }
        return -1;
    }
    
    void remove(int _key) {
        int index = getIndex(_key);
        auto head = buckets[index];
        mapnode* prev = nullptr;
        while(head!=nullptr){
            if(head->key == _key){
                if(prev == nullptr){
                    buckets[index] = head->next;
                }
                else{
                    prev->next = head->next;
                }
                head->next = nullptr;
                size--;
                delete head;
                return;
            }
            prev = head;
            head = head->next;
        }
    }
private:
    int getIndex(int key){
        return key%numOfBuckets;
    }

    void rehash(){
        int oldBucketsCount = numOfBuckets;

        auto oldBuckets = buckets;
        buckets = new mapnode*[2*numOfBuckets];
        for(int i=0;i<2*numOfBuckets;i++) buckets[i]= nullptr;

        numOfBuckets *= 2;
        size = 0;
        for(int i=0;i<oldBucketsCount;i++){
            auto head = oldBuckets[i];
            while(head!=nullptr){
                put(head->key,head->value);
                head = head->next;
            }
        }

        for(int i=0;i<oldBucketsCount;i++) delete oldBuckets[i];
        delete [] oldBuckets;
    }    
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */