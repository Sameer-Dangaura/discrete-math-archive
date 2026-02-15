//Let, 'a' -> be an integer 
//and  'd' -> be a +ve interger.
//Then, there are unique intergers 
// 'q' and 'r', with 0<r<d.
//----------------
//: a = d.q + r
//----------------
//Here, 'a' is dividend
// 'd' is divisor
// 'c' is quotient
// 'r' is remainder.


//gcd using euclidean
#include<stdio.h>
int main()
{
    int a,d,q,r,x,y;
    printf("enter two numbers a and d:\n");
    scanf("%d %d",&a,&d);
    x=a;
    y=d;
    while(r!=0)
    {
        r=a % d;         
        a=d;
        d=r;
    }
    printf("the gcd of %d,%d is %d",x,y,a); 
    return 0;
}
//here in last step of gcd when remainder is 0, our gcd is that divisor. .
//but in this algo divisor is copied in 'a' (i.e. dividend) so we print "a".