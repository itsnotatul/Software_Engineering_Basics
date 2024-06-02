#include <iostream>
#include<string>
using namespace std;

template<typename V>
class mapnode{
    public:
string key;
V value;
mapnode<V> * next;

 mapnode(string key,V value){
     this->key = key;
     this->value= value;
     next = NULL;
 }

 ~mapnode(){
    delete next;
 }


};

template<typename V>
class hashmap
{
private:
     mapnode<V>** buckets; /// array consisting of mapnodes head
    int count ; /// no. of entries in the map
    int numbuckets ; /// size of buckets array = number of buckets

public:
     hashmap(){
      count = 0;
      numbuckets = 5;
      buckets = new mapnode<V>*[numbuckets];

        /// we've created an array of size numbuckets & it contains rn 0 entries but at every index there is some garbage which is very dangerous so, let;s clear it first

      for (int i=0;i<numbuckets;i++){
        buckets[i]=NULL;

      }
}
      ~hashmap(){
       for(int i=0;i<numbuckets;i++){
        delete buckets[i];
      }
        delete [] buckets;
    }

    /// functions : size , insert (getbucketindex),remove, getvalue

    int size(){
    return count;
    }
private:
    int getbucketindex(string key){
    int hashcode =0;
    int currentcoefficient = 1;

    for(int i =key.length()-1;i>=0;i--){
        hashcode += key[i]*currentcoefficient;
        hashcode = hashcode%numbuckets;
        currentcoefficient *=37;
        currentcoefficient= currentcoefficient%numbuckets;
    }
    return hashcode%numbuckets;
    }

   void rehash(){
        mapnode<V>** temp = buckets;
        buckets = new mapnode<V>*[2*numbuckets];

        for(int i=0;i<2*numbuckets;i++){
            buckets[i]=NULL;
        }

   int oldbucketcount = numbuckets;
   numbuckets *=2;
   count =0;

   for(int i=0;i<oldbucketcount;i++){
    mapnode<V>* head = temp[i];

    while(head!=NULL){
        string key = head->key;
        V value = head->value;
        insert(key,value);
        head= head->next;
    }
}
    /// lets delete old array
         for(int i=0;i<oldbucketcount;i++){
                mapnode<V> * head = temp[i];
         delete head;
    }
         delete [] temp;

   }

public:
   void insert(string key,V value){
          int bucketsindex = getbucketindex(key);
          mapnode<V>* head = buckets[bucketsindex];

          while(head!=NULL){
            if(head->key==key){
                head->value = value;
                return ;  /// notice in this case we only have to update the value of pre-existing key so no change in count
            }
            head = head->next;

}
          head = buckets[bucketsindex];
          mapnode<V> *node = new mapnode<V>(key,value);
          buckets[bucketsindex] = node;
          node->next = head;
          count++;
   ///rehashing : to maintain the load factor , if n increases then b also has to increase
      double loadfactor = (1.0*count)/numbuckets;
      if(loadfactor > 0.7){
        rehash();
      }

   }

   /// remove
   V remove (string key){
     int bucketsindex = getbucketindex(key);
          mapnode<V>* head = buckets[bucketsindex];
          mapnode<V>* prev = NULL;

          while(head!=NULL){
            if(head->key ==key){
                if(prev==NULL){
                    buckets[bucketsindex] = head->next;

                }
                else{
                    prev->next = head->next;

                }
                V ans = head->value;
                head->next = NULL;
                delete head;
                count --;
                return ans;

            }
        prev = head;
        head= head->next;


          }
 return 0;

   }

    /// get value
    V getvalue(string key ){
       int bucketsindex = getbucketindex(key);
          mapnode<V>* head = buckets[bucketsindex];

          while(head!=NULL){
            if(head->key==key){
                return head->value;
            }
            head= head->next;
          }
          return 0;
    }

};

int main(){

}
