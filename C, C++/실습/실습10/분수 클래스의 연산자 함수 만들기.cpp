#include<iostream>
#include<math.h>
using namespace std;

class Fraction{
private:
   int numerator; //분자
   int denominator; //분모
   
   int gcd(int a, int b){
      int r;
      while(a%b != 0){
         r = a % b;
         a = b;
         b = r;
      }
      return b;
   }
public:
   Fraction(){}
   Fraction(int n, int d){
      numerator = n;
      denominator = d;
   };
   void setFraction(int n, int d){
      numerator = n;
      denominator = d;
   };
   int getnumerator(){
      return numerator;
   };
   int getdenominator(){
      return denominator;
   };
   friend istream& operator>>(istream& cin, Fraction& F);
   friend Fraction operator*(int i, Fraction f);
   friend Fraction operator ++(Fraction& f);
   friend ostream& operator<<(ostream& cout, Fraction& F);
   
   void print()
   {
      if(denominator < 0){
         numerator *= -1;
         denominator *= -1;
      }
      cout<<numerator<<"/"<<denominator<<endl;
   };
   int reduce(){
      int gcdNumDen;
      if(numerator == 0 || denominator == 0)
         return 0;
      
      gcdNumDen = gcd(numerator, denominator);
      numerator = numerator / gcdNumDen;
      denominator = denominator / gcdNumDen;
      return 0;
   };
   Fraction operator+(Fraction F);
   Fraction operator-(Fraction F);
   Fraction operator*(int i);
};

Fraction Fraction::operator+(Fraction f){
   int predenominator = denominator;
   int den, numer;
   
   den = denominator * f.getdenominator() / gcd(denominator, f.getdenominator());
   numer = numerator * (den/predenominator) + f.getnumerator() * (den / f.getdenominator());
   Fraction result = {numer, den};
   result.reduce();
   return result;
}
Fraction Fraction::operator-(Fraction f){
   int predenominator = denominator;
   int den, numer;
   
   den = denominator * f.getdenominator() / gcd(denominator, f.getdenominator());
   numer = numerator * (den/predenominator) - f.getnumerator() * (den / f.getdenominator());
   Fraction result = {numer, den};
   result.reduce();
   return result;
}
Fraction Fraction::operator*(int i){
   Fraction result = {numerator * i, denominator};
   return result;
}
Fraction operator*(int i, Fraction f){
   f.numerator = f.numerator * i;
   return f;
}
istream& operator>>(istream& cin, Fraction& F){
   int n, d;
   cin>>n>>d;
   F.numerator = n;
   F.denominator = d;
   return cin;
}
ostream& operator<<(ostream& cout, Fraction& F){
   F.reduce();
   cout<<F.numerator<<"/"<<F.denominator;
   return cout;
}
Fraction operator ++(Fraction& f){
   f.numerator = f.numerator + f.denominator;
   return f;
}

int main(){
   Fraction f1, f2;
   Fraction sumF, subF, df2, fd2;
   cin>> f1 >> f2;
   cout<<f1 << endl << f2 << endl;
   sumF = f1 + f2;
   subF = f1 - f2;
   cout<<sumF<<endl<< subF<<endl;
   ++f1;
   df2 = 2 * f2;
   fd2 = f2 * 2;
   cout<<f1 <<endl<< df2 <<endl<< fd2<<endl;
   
   return 0;
}
