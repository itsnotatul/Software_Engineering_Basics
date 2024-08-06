#include "Library.h"

callback g_cb;
int init(callback cb)
{
    g_cb = cb;
    return 0;
}

void ServerFun(string x)
{
    string res = Server::fun(x);
    g_cb(res,nullptr);
    
}
