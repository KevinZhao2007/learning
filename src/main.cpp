#include<bits/stdc++.h>
#include "calculation.h"
using namespace std;
int main()
{
    if(cal()==true)
    {
     cout<<"请输入实际观测值："<<endl;
    double a,b;
    cin>>a>>b;
    cout<<"残差大小为："<<cal_dis(a,b)<<endl;    
    }
    return 0;
}
