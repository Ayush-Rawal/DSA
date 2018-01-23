#include <iostream>
#include<cmath>

void enterArray(int *a,size_t size)
{
	for (int i=0;i<size;i++){
		std::cin>>*(a+i);
	}
}

void printArray(int *a,size_t size)
{
	for (int i=0;i<size;i++){
		std::cout<<*(a+i)<<" ";
	}
	std::cout<<std::endl;
}

void sort_asc(int *a,size_t size, unsigned int inc = 1)
{
	for(int i = 0 ; i < size; i += inc){
		int small = *(a+i), pos = i;
		for(int j=i+inc;j<size;j=j+inc){
			if(*(a+j)<small){
				small=*(a+j);
				pos=j;
			}
		}
		small = *(a+i);
		*(a+i)=*(a+pos);
		*(a+pos)=small;
	}
}

void q1()
{
	size_t n;
	int *p;
	std::cout<<"How many numbers do you want to sort?"<<std::endl;
	std::cin>>n;
	p = (int*)(calloc(n,sizeof(int)));
	std::cout<<"Enter numbers"<<std::endl;
	enterArray(p,n);
	sort_asc(p,n);
	std::cout<<"Sorted array is:"<<std::endl;
	printArray(p,n);
}

void q2()
{
	size_t size;
	int n=1,*p;
	std::cout<<"How many numbers are there?"<<std::endl;
	std::cin>>size;
	p = (int*)calloc(size,sizeof(int));
	std::cout<<"Enter numbers"<<std::endl;
	enterArray(p,size);
	std::cout<<"Which smallest element do you want? ex: second smallest, first smallest"<<std::endl;
	std::cin>>n;
	sort_asc(p,size);
	std::cout<<n<<"th smallest element is: "<<*(p+n-1)<<std::endl;
}


struct point{
    int x,y;
};

void enterPoints(point* p, size_t size)
{
	for(int i=0;i<size;i++){
		std::cin>>(p+i)->x>>(p+i)->y;
	}
}

float computeDist(point a,point b)
{
    return sqrt(fabs(( a.x*a.x + a.y*a.y ) - ( b.x*b.x + b.y*b.y )));
}

float computeSmallestDistance(point *p,size_t size)
{
    int i,j;
    float min = computeDist(*(p+0),*(p+1));
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if( ( i==0 && j==1 ) || ( i==j ))
            continue;
            float small = computeDist(*(p+i),*(p+j));
            if(small<min)
            min=small;
        }
    }
    return min;
}

void q3()
{
	size_t n;
	point *p;
	std::cout<<"How many points are there?"<<std::endl;
	std::cin>>n;
	p = (point*)calloc(n,sizeof(point));
	std::cout<<"Enter points"<<std::endl;
	enterPoints(p,n);
	std::cout<<"Smallest distance between any two points is: "<<computeSmallestDistance(p,n)<<std::endl;
}

int main(int argc, char* argv[])
{
	// int a[3][3], *p;
	// p=a; /* Please check */

// Sort n numbers
// Find nth smalest number;
// Find the closest pair among n 2D points

	q1();
	q2();
	q3();
	return 0;
}