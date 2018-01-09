#include <iostream>
#include <cmath>

void reverse(int a[],size_t size)
{
    int temp,i;
    for(i=0;i<size/2;i++){
        temp=a[i];
        a[i]=a[size-i-1];
        a[size-i-1]=temp;
    }
}

void q1()
{
    size_t n=6;
    int i;
    int arr[n];
    for(i=0;i<n;i++)
    arr[i]=1<<i;
    std::cout<<"Original Array"<<std::endl;
    for(int i=0;i<6;i++)
    std::cout << arr[i] << "\t";
    reverse(arr,n);
    std::cout<<std::endl<<"Reversed Array"<<std::endl;
    for(int i=0;i<6;i++)
    std::cout << arr[i] << "\t";
    std::cout<<std::endl;
}

int findMin(int a[],size_t size)
{
    int i,small=a[0];
    for(i=0;i<size;i++){
        if(a[i]<small)
            small=a[i];
    }
    return small;
}

unsigned int findPos(int a[],size_t size,int elem)
{
    int i;
    for(i=0;i<size;i++){
        if(a[i]==elem)
        return i;
    }
    return -1;
}

void q2()
{
    size_t n=6;
    int i,min,pos;
    int arr[n];
    std::cout<<"Enter Array"<<std::endl;
    for(i=0;i<n;i++){
    std::cin>>arr[i];
    }
    min=findMin(arr,n);
    pos=findPos(arr,n,min);
    std::cout<<"Minimum Element is "<<min<<" at position "<<pos;
    std::cout<<std::endl;
}

void rotate(int a[],size_t size)
{
    int temp=a[0];
    for(int i=1;i<size;i++){
        a[i-1]=a[i];
    }
    a[size-1]=temp;
}

void q3()
{
    size_t n=6;
    int arr[n];
    std::cout<<"Enter Array"<<std::endl;
    for(int i=0;i<n;i++){
    std::cin>>arr[i];
    }
    rotate(arr,n);
    std::cout<<"Rotated Array"<<std::endl;
    for(int i=0;i<n;i++){
    std::cout<<arr[i]<<"\t";
    }
    std::cout<<std::endl;
}

struct point{
    int x,y;
};

float computeDist(point a,point b)
{
    return sqrt(fabs(( a.x*a.x + a.y*a.y ) - ( b.x*b.x + b.y*b.y )));
}

float computeSmallestDistance(point p[],size_t size)
{
    int i,j;
    float min = computeDist(p[0],p[1]);
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if( ( i==0 && j==1 ) || ( i==j ))
            continue;
            float small = computeDist(p[i],p[j]);
            if(small<min)
            min=small;
        }
    }
    return min;
}

void q4()
{
    size_t n=3;
    int i;
    point arr[n];
    std::cout<<"Enter points"<<std::endl;
    for(i=0;i<n;i++){
        std::cin>>arr[i].x>>arr[i].y;
    }
    std::cout<<computeSmallestDistance(arr,n);
}

int main(int argc,char* argv[])
{
    q1();    //reverse an array
    q2();    //nth minimum no. in array and position
    q3();    //rotate(shift) an array
    q4();    //find nearest point
    return 0;
}
