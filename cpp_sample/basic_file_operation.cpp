#include <stdio.h>

//打开文件
FILE *fp = fopen((dir_name + "/" + file_name + ".txt").c_str(),"w");    //写文件
FILE *fp = fopen(file_name.c_str(),"r");                                //读文件

if (!fp) {                       //打开文件失败返回NULL
    success = false;
    return groundtruth;
}

//写入文件
fprintf(fp,"%f %f \n",(double)i/(N_SAMPLE_PTS-1.0),vals[0][i]);   //写入float类型
fprintf(fp,"set term png size 450,315 font \"Helvetica\" 11\n");  //带引号的使用"\"转义
fprintf(fp,"set output \"%s.png\"\n",file_name.c_str());          //写入字符串
fprintf(fp,"\"%s.txt\" using 1:2 title 'Easy' with lines ls 1 lw %d,",file_name.c_str(),lw);  //写入int类型

//读取文件(逐行读取) 这里使用%f和使用%lf没有差别
while (!feof(fp)) {
    tGroundtruth g;
    char str[255];
    if (fscanf(fp, "%s %lf %d %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
                   str, &g.truncation, &g.occlusion, &g.box.alpha,
                   &g.box.x1,   &g.box.y1,     &g.box.x2,    &g.box.y2,
                   &g.h,      &g.w,        &g.l,       &g.t1,
                   &g.t2,      &g.t3,        &g.ry )==15 && !strcasecmp(str, "Car")) {   // 只需要Car类型
      g.box.type = str;
      groundtruth.push_back(g);
    }
}

//关闭文件
fclose(fp);

