#include <iostream>
#include <math.h>
using namespace std;

void table_ditoch(const double& ak,const double& bk){
  std::cout << '|';
  std::cout.width(14);\
    std::cout.setf(std::ios::left);
  std::cout.fill(' ');
  std::cout << ak;
  std::cout << "|    ";
  std::cout.width(10);
  std::cout.fill(' ');
  std::cout<<bk;
  std::cout << "|    ";
  std::cout.width(10);
  std::cout.fill(' ');
  std::cout<<bk-ak;
  std::cout << "|  ";
  std::cout.width(10);
  std::cout.fill(' ');
  std::cout<<pow(ak,2)*exp(sin(ak));
  std::cout << "|  ";
  std::cout.width(10);
  std::cout.fill(' ');
  std::cout<<pow(bk,2)*exp(sin(bk));
  std::cout<<"|\n";
}

void table_passive (const double mini, const double i){
  std::cout.setf(std::ios::left);
  std::cout.precision(0);
  std::cout<<"|     "<<i<<"      |  ";
  std::cout.precision(2);
  std::cout.width(2);
  std::cout<<std::fixed<<mini<<" ± ";
  std::cout.width(7);
  std::cout.fill(' ');
  std::cout.precision(3);
  std::cout.unsetf(std::ios_base::fixed);
  std::cout << 1./(i+1);
  std::cout<<"|\n";
}

double f(const double &x){
    double f = pow(x, 2) * exp(sin(x));
   return f;
}
int main() {
  setlocale(LC_ALL, "Russian");
  int a=9, b=14;
  const double e=0.1;
  double x1, x2, ak=a, bk=b, s=0.04;

  std::cout<<"________________________________________________________________________\n";
  std::cout<<"|    Начало    |    Конец     |    Длина     |            |            |\n";
  std::cout<<"|  интервала   |  интервала   |  интервала   |    f(ak)   |   f(bk)    |\n";
  std::cout<<"|     (ak)     |     (bk)     |      1       |            |            |\n";
  std::cout<<"------------------------------------------------------------------------\n";
  while (bk-ak>e){
    table_ditoch(ak,bk);
     x1=(ak+bk)/2.-s;
     x2=(ak+bk)/2.+s;
     if (f(x1)<=f(x2)) bk=x2-s;
     else ak=x1+s;
  }
  table_ditoch(ak, bk);
  std::cout<<"------------------------------------------------------------------------\n";
  std::cout<<'\n';
  std::cout<<"Минимальное значение функции достигается при x = "<<(ak+bk)/2.<<"±"<<s<<'\n';
  std::cout<<'\n';
  size_t j;
  double i=1;
  double min, part, mini;
  size_t N=(1/e)-1;
  std::cout<<"_____________________________\n";
  std::cout<<"| Количество |   Значение x   |\n";
  std::cout<<"|  точек (N) |   в минимуме   |\n";
  std::cout<<"-----------------------------\n";
  for (i; i<=N; i++){
    part=(b-a)/(i+1);
    min=10000;
    for (j=1; j<=i; j++) {
      if (f(a + part * j) < min) {
        min = f(a + part * j);
        mini = a + part * j;
      }
    }
    table_passive(mini, i);
  }
  std::cout<<"-------------------------------\n\n";
  std::cout<<"Минимальное значение функции достигается при N = "<<i<<" (x = "<<mini<<" ± ";
  std::cout.precision(1);
  std::cout<<std::fixed<<1./(i+1)<<")\n";
  return 0;
}
