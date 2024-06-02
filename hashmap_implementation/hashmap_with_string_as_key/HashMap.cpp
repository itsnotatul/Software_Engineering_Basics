#include "HashMap.h"
#include <iostream>

mapnode::mapnode(string _key, int _value): key(_key),value(_value),next(nullptr)
{
  cout << "MapNode inside bucket is CREATED" << endl;
}

mapnode::~mapnode()
{
  delete next;
  cout << "MapNode inside bucket is Destructed" << endl;
}

HashMap::HashMap()
{
  count = 0;
  numbuckets = 5;
  buckets = new mapnode* [numbuckets];

  /// we've created an array of size numbuckets & it contains rn 0 entries but at every index there is some garbage which is very dangerous so, let's clear it first

  for(int i = 0; i < numbuckets; i++)
  {
    buckets[i] = nullptr;
  }
}

HashMap::~HashMap()
{
  for (int i = 0; i < numbuckets; i++)
  {
    delete buckets[i];
  }
  delete[] buckets;
}

void HashMap::insert(string key, int value)
{
  int bucketsindex = getbucketindex(key);
  mapnode *head = buckets[bucketsindex];

  while (head != nullptr)
  {
    if (head->key == key)
    {
      head->value = value;
      return; /// notice in this case we only have to update the value of pre-existing key so no change in count
    }
    head = head->next;
  }
  head = buckets[bucketsindex];
  mapnode* node = new mapnode(key, value);
  buckets[bucketsindex] = node;
  node->next = head;
  count++;
  /// rehashing : to maintain the load factor , if n increases then b also has to increase
  double loadfactor = (1.0 * count) / numbuckets;
  if (loadfactor > 0.7)
  {
    rehash();
  }
}

int HashMap::getvalue(string key)
{
  int bucketsindex = getbucketindex(key);
  mapnode *head = buckets[bucketsindex];

  while (head != nullptr)
  {
    if (head->key == key)
    {
      return head->value;
    }
    head = head->next;
  }
  cout<<"invalid key sent"<<endl;
  return -1;
}

void HashMap::remove(string key)
{
  int bucketsindex = getbucketindex(key);
  mapnode *head = buckets[bucketsindex];
  mapnode *prev = nullptr;

  while (head != nullptr)
  {
    if (head->key == key)
    {
      if (prev == nullptr)
      {
        buckets[bucketsindex] = head->next;
      }
      else
      {
        prev->next = head->next;
      }

      head->next = nullptr;
      delete head;
      count--;
    }
    prev = head;
    head = head->next;
  }
}

int HashMap::size()
{
  return count;
}

int HashMap::getbucketindex(string key)
{
  int hashcode = 0;
  int currentcoefficient = 1;

  for (int i = key.length() - 1; i >= 0; i--)
  {
    hashcode += key[i] * currentcoefficient;
    hashcode = hashcode % numbuckets;
    currentcoefficient *= 37;
    currentcoefficient = currentcoefficient % numbuckets;
  }
  return hashcode % numbuckets;
}

void HashMap::rehash()
{
  mapnode** temp = buckets;
  buckets = new mapnode* [2*numbuckets];

  for (int i = 0; i < 2*numbuckets; i++)
  {
    buckets[i] = nullptr;
  }

  int oldbucketcount = numbuckets;
  numbuckets *= 2;
  count = 0;

  for (int i = 0; i < oldbucketcount; i++)
  {
    mapnode* head = temp[i];

    while (head != nullptr)
    {
      string key = head->key;
      int value = head->value;
      insert(key, value);
      head = head->next;
    }
  }
  /// lets delete old array
  for (int i = 0; i < oldbucketcount; i++)
  {
    mapnode* head = temp[i];
    delete head;
  }
  delete[] temp;
}
