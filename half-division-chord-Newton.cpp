#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

double func1(double x)
{return (-29*pow(x,7)+121*pow(x,6)+363*pow(x,5)-783*pow(x,4)-924*pow(x,3)+728*pow(x,2)+386*x+5);}

double d1f1(double x)
{return (-203*pow(x,6)+726*pow(x,5)+1815*pow(x,4)-3132*pow(x,3)-2772*pow(x,2)+1456*x+386);}

double d2f1(double x)
{return (-1218*pow(x,5)+3639*pow(x,4)+7260*pow(x,3)-9396*pow(x,2)-5544*x+1456);}

double func2(double x)
{return (pow(x,2)+4*sin(x));}

double d1f2(double x)
{return 2*x+4*cos(x);}

double d2f2(double x)
{return (2-4*sin(x));}

int main()
{
    double a,b,c = 0.0,e;
int i=1, number, num;
    
  cout<<"f(x)=-29x^7+121x^6+363x^5-783x^4-924x^3+728x^2+386^x+5 --- 1"<<endl;
  cout<<"f(x)=x^2+4sinx --- 2"<<endl<<"Enter the number of the equation: ";
  cin>>num;
    if (num==1) {
        cout<<endl<<"1 - half division method"<<endl<<"2 - chord method"<<endl<<"3 - Newton's method"<<endl<<"Enter the method number: ";
        cin>>number;
        cout<<"The beginning of the interval a=";
        cin>>a;
        cout<<"End of interval b=";
        cin>>b;
        cout<<"Calculate with accuracy e=";
        cin>>e;


      switch(number)
      {
        case 1:
              c=(a+b)/2;

              
                while((fabs(b-a)>e)&&(fabs(func1(c))>e))
                            {
                            if (func1(a)*func1(c)<0)
                               b=c;
                            else
                               a=c;
                                c=(a+b)/2;
                                cout<<i<<" iteration = "<<c<<endl;
                                cout<<" a="<<a<<" b="<<b<<" f(a)="<<func1(a)<<" f(b)="<<func1(b)<<endl;
                                cout<<endl;
                                i++;
                            }
        break;
          case 2:
              while ((fabs(b-a)>e)&&(fabs(func1(c))>0)){
                      b = a - (a - b) * func1(a) / (func1(a) - func1(b));
                      a = b - (b - a) * func1(b) / (func1(b) - func1(a));
                      c = a;
                      cout<<i<<" iteration = "<<c<<"\n";
                  cout<<" a="<<a<<" b="<<b<<" f(a)="<<func1(a)<<" f(b)="<<func1(b)<<endl;
                  cout<<endl;
                  i++;}

                  
          break;
              
          case 3:
              double x,x0;
                         
              if (func1(a)*d2f1(a)>0) x0 = a;
                       else x0 = b;
                     x = x0-func1(x0)/(d1f1(x0));
              cout<<i++<<" iteration"<<endl;
              cout<<" x="<<x<<" f(x)="<<func1(x)<<endl;
         while((fabs(x0-x)>e)&&(fabs(func1(x))>0))
                                      {x0 = x;
                                      x = x0-func1(x0)/d1f1(x0);
                                      cout<<i<<" iteration"<<endl;
                                      cout<<" x="<<x<<" f(x)="<<func1(x)<<endl;
                                          i++;
                                      }

          break;}
    }
    if (num==2) {
  cout<<endl<<"1 - half division method"<<endl<<"2 - chord method"<<endl<<"3 - Newton's method"<<endl<<"Enter the method number: ";
  cin>>number;
  cout<<"The beginning of the interval a=";
  cin>>a;
  cout<<"End of interval b=";
  cin>>b;
  cout<<"Calculate with accuracy e=";
  cin>>e;


switch(number)
{
  case 1:
        c=(a+b)/2;

        
          while((fabs(b-a)>=e)&&(fabs(func2(c))>=0))
                      {
                      if (func2(a)*func2(c)<0)
                         b=c;
                      else
                         a=c;
                          c=(a+b)/2;
                          cout<<i<<" iteration = "<<c<<endl;
                          cout<<" a="<<a<<" b="<<b<<" f(a)="<<func2(a)<<" f(b)="<<func2(b)<<endl;
                          cout<<endl;
                          i++;
                      }
  break;
    case 2:
        while ((fabs(b-a)>=e)&&(fabs(func2(c))>=0)){
                b = a - (a - b) * func2(a) / (func2(a) - func2(b));
                a = b - (b - a) * func2(b) / (func2(b) - func2(a));
                c = a;
                cout<<i<<" iteration = "<<c<<"\n";
            cout<<" a="<<a<<" b="<<b<<" f(a)="<<func2(a)<<" f(b)="<<func2(b)<<endl;
            cout<<endl;
            i++;}

            
    break;
        
    case 3:
        double x,x0;
                   
        if (func2(a)*d2f2(a)>0) x0 = a;
                 else x0 = b;
               x = x0-func2(x0)/(d1f2(x0));
                cout<<++i<<" iteration = "<<x<<"\n";

   while((fabs(x0-x)>=e)&&(fabs(func2(x))>=0))
                                {x0 = x;
                                x = x0-func2(x0)/d1f2(x0);
                                cout<<i<<" iteration"<<endl;
                                cout<<" x="<<x<<" f(x)="<<func2(x)<<endl;
                                    i++;
                                }

    break;}
    }}
