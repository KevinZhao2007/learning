#include<bits/stdc++.h>
#include "calculation.h"
#define pi 3.14159265358
using namespace std;
double u,v,dis;//像素坐标与欧式距离
double x,y,z,tx,ty,tz,rx,ry,rz;//外参
double fx,fy,cx,cy;//内参
double R1[3][3]={0};
double cal()
{
    cout<<"请输入相机内参fx,fy(焦距),cx,cy（像素中心）:"<<endl;
    cin>>fx>>fy>>cx>>cy;
    cout<<"请输入相机外参tx,ty,tz注意正负方向),rx,ry,rz（按右手定则规定正负，角度制）:"<<endl;
    cin>>tx>>ty>>tz>>rx>>ry>>rz;
    rx=rx*pi/180,ry=ry*pi/180,rz=rz*pi/180;//转弧度
    cout<<"请输入点的三维坐标x,y,z:"<<endl;
    cin>>x>>y>>z;
    double X[3][3]={{1,0,0},{0,cos(rx),-sin(rx)},{0,sin(rx),cos(rx)}},Y[3][3]={{cos(ry),0,-sin(ry)},{0,1,0},{sin(ry),0,cos(ry)}},Z[3][3]={{cos(rz),-sin(rz),0},{sin(rz),cos(rz),0},{0,0,1}},R[3][3]={0};//旋转矩阵
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    for(int k=0;k<3;k++)
    R1[i][j]+=X[i][k]*Y[k][j];
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    for(int k=0;k<3;k++)
    R[i][j]+=R1[i][k]*Z[k][j];
    double x0=R[0][0]*x+R[0][1]*y+R[0][2]*z+tx;
    double y0=R[1][0]*x+R[1][1]*y+R[1][2]*z+ty;
    double z0=R[2][0]*x+R[2][1]*y+R[2][2]*z+tz;
    if(z0<=0)
    {
        cout<<"点在相机后或在光心上，无法投影"<<endl;
        return 0;
    }
    else if(z0>0&&z0<1e-5)
    {
        cout<<"点在相机前方，但距离光心过近，无法投影"<<endl;
        return 0;
    }
    else
    {
    u=fx*x0/z0+cx;
    v=fy*y0/z0+cy;
    dis=sqrt(x0*x0+y0*y0+z0*z0);
    cout<<"像素坐标为(u,v):("<<u<<","<<v<<")"<<endl;
    cout<<"欧式距离为:"<<dis<<endl;
    }//这里不考虑u和v的范围问题，假设像素坐标在图像范围内
    return 0;
}
double cal_dis(double a,double b)
{
    double c=sqrt((u-a)*(u-a)+(v-b)*(v-b));
    return c;
}