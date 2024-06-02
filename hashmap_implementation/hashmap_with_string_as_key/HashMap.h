#pragma once

#include <iostream>
#include <string>
using namespace std;

class mapnode
{
public:
  string key;
  int value;
  mapnode *next;

  mapnode(string _key, int _value);
  ~mapnode();
};

class HashMap
{
private:
  mapnode **buckets; /// array consisting of mapnodes head
  int count;         /// no. of keys in the map
  int numbuckets;    /// size of buckets array = number of buckets

public:
  HashMap();
  ~HashMap();
  void insert(string key, int value);
  int getvalue(string key);
  void remove(string key);
  int size();

private:
  int getbucketindex(string key);
  void rehash();
};