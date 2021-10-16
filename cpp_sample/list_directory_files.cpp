#include<iostream>
#include<sys/types.h>
#include<dirent.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cout<<"getFiles usage: getFiles <dir>"<<endl;
    cout<<"input the dir:"<<endl; // 输入需要获取的Linux目录
    char dir[50];
    cin>>dir;

    DIR * dir_ptr;
    vector<string> vec_str;
    if((dir_ptr = opendir(dir))==NULL){  // 打开目录
        cout<<"OpenDirFile error!"<<endl;
        return 1; 
    }
  
    cout<<"the files in the dir:"<<endl;
    dirent * dir_file;
    while((dir_file = readdir(dir_ptr))!=NULL){ // 读取目录中的文件信息
        string str(dir_file->d_name);
        if(str.length() >= 10)
            //cout<<dir_file->d_name<<"   "; // 输出目录下文件的名称
            vec_str.push_back(str);
    }
    closedir(dir_ptr); // 关闭目录
    sort(vec_str.begin(), vec_str.end());
    for(auto s : vec_str)
        cout<<s<<" ";
    cout<<endl;
    return 0;
}
