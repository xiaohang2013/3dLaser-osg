#include "macro.h"
#include "file.h"
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

int File::f_save(string v_fPath)
{
    return CUR_OK;
}

int File::f_save_as(string v_fPath)
{
    return CUR_OK;
}

int File::f_close(string  v_fPath)
{
    return CUR_OK;
}

int File::f_open_pcd(string  v_fPath)
{
    return CUR_OK;
}

int File::f_open_dxf(string v_fPath)
{
    return CUR_OK;
}
