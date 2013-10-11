#include <stdio.h>
#include <string.h>

#define max 11

char a[4][max];

long long num2Dec(char * p, long long radix)
 {
      long long  i;
      long long  len=strlen(p);

      long long digit = 0;
      long long m = 1;
      long long sum = 0;
      for(i=len-1;i>=0;i--)
      {
         if(p[i]>='a'&&p[i]<='z')
              digit= p[i] - 'a' + 10;
         else if(p[i]>='0'&& p[i]<='9')
              digit=p[i] - '0';
          sum+=digit*m;
          m*=radix;
      }
      return sum;
 }

 int findLeastRadix(char *p)
  {
     long long  len=strlen(p);
     long long  low=0;
     long long num;
     long long i;
     for(i=len-1;i>=0;i--)
      {
          if(p[i]>='a'&&p[i]<='z')
             num= p[i] - 'a' + 10;
          else if(p[i]>='0'&& p[i]<='9')
              num=p[i] - '0';
          if(num+1>low)
              low=num+1;
      }
      return low;

 }

int compare(char* p, long long radix, long long target)
 {
     long long  i;
     long long len=strlen(p);

     long long m = 1;
     long long num = 1;
     long long sum = 0;
     for(i=len-1;i>=0;i--)
     {
         if(p[i]>='a'&&p[i]<='z')
             num= p[i] - 'a' + 10;
         else if(p[i]>='0'&& p[i]<='9')
             num=p[i] - '0';
         sum+=num*m;
         m*=radix;
         if(sum>target)  //avoid  overflow
             return 1;
     }

     if(sum>target)
         return 1;
     else if(sum<target)
         return -1;
     else
         return 0;

 }


long long binarySearch(char* p, long long low, long long high, long long target){

    long long mid = low;
    int tag;

    while(low<=high) {

        tag = compare(p, mid, target);

        switch(tag) {
            case -1:
                low = mid + 1;
                break;
            case 0:
                return mid;
            case 1:
                high = mid - 1;
        }

        mid = (low + high) >> 1;
    }

    return -1;
}


int main(int argc, char* argv[])
{
    int i;
    int tag;
    int base;
    long long n1;
    long long n2;
    long long low;
    long long high;
    long long radix;

    for(i=0; i<4; i++) {
        scanf("%s", a[i]);
    }

    tag = atoi(a[2]);
    base = atoi(a[3]);

    switch(tag) {
        case 1 :
            n1 = num2Dec(a[0], base);
            low=findLeastRadix(a[1]);
            high = (n1+1 > low+1) ? n1+1 : low+1;
            radix = binarySearch(a[1], low, high, n1);
            break;

        case 2 :
            n2 = num2Dec(a[1], base);
            low=findLeastRadix(a[0]);
            high = (n2+1 > low+1) ? n2+1 : low+1;
            radix = binarySearch(a[0], low, high, n2);
            break;
    }

    if(-1 != radix){
         printf("%ld\n", (long)radix);
    }
    else {
        printf("Impossible");
    }

    return 0;
}