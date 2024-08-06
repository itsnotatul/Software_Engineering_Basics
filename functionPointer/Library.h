#pragma once
#include<iostream>
#include<string>
#include "Server.h"

typedef void(*callback)(string response, void* user_data);

int init(callback cb);
void ServerFun(string x);
