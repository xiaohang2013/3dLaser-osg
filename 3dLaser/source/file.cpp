#include "macro.h"
#include "file.h"
#include <iostream>
using namespace std;
File::File()
{
}

File::~File()
{
}

int File::f_open(string v_fPath)
{
    int rtn = CUR_ERROR;
    //rtn = f_open_pcd(v_fPath);
    return rtn;
}

int f_save(string v_fPath)
{
    return CUR_OK;
}

int f_save_as(string v_fPath)
{
    return CUR_OK;
}

int f_close(string  v_fPath)
{
    return CUR_OK;
}

int File::f_open_pcd(string  v_fPath)
{
    return CUR_OK;
}

int f_open_dxf(string v_fPath)
{
    return CUR_OK;
}
