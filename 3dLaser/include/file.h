#ifndef FILE_H
#define FILE_H
#include <string>
using namespace std;
class File
{
public:
    File();
    ~File();
int f_open(string v_fPath);
int f_close(string  v_fPath);
int f_save(string  v_fPath);
int f_save_as(string v_fPath);
int f_open_pcd(string v_fPath);
int f_open_dxf(string v_fPath);

};

#endif // FILE_H
