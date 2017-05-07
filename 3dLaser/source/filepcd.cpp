#include "macro.h"
#include "filepcd.h"
#include <iostream>
#include <pcl/io/pcd_io.h>
using namespace std;

PcdFile::PcdFile()
{
}

PcdFile::~PcdFile()
{
}
int PcdFile::pcd_r(string  v_fPath, pcl::PointCloud<pcl::PointXYZ>::Ptr cloud)
{
    string fPath = v_fPath;
    if (pcl::io::loadPCDFile<pcl::PointXYZ>(fPath, *cloud) == -1) //* load the file
    {
        return CUR_ERROR;
    }
    return CUR_OK;
}