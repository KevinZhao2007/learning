#pragma once
extern double x,y,z,tx,ty,tz,rx,ry,rz;//外参
extern double fx,fy,cx,cy;//内参
extern double u,v;//像素坐标与欧式距离
extern double R1[3][3];
bool cal();
double cal_dis(double a,double b);
