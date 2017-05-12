//compiled with g++
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>
using namespace std;

void cycle_leader(vector<int> &a,int from, int mod) {  
  for (int i = from * 2 % mod;i != from; i = i * 2 % mod)  
     swap(a[from],a[i]);
}

void perfect_shuffle(vector<int> &a,int n){
   int n2,m,i,k,t;
   vector<int>::iterator iter = a.begin()+1; //exclude index 0
   for(;n > 1;){
      //step 1
      n2 = n * 2;
      for(k = 0,m = 1; n2 / m >=3; ++k,m *= 3)
         ;
      m /= 2;
      // 2m = 3^k - 1 , 3^k <= 2n < 3^(k + 1)

      //step 2   STL/algorithm-rotate
      rotate(iter+m, iter+n, iter+m+n ); //right cyclic shift of the index[m+1,...,n+m] O(n)
      
      //step 3
      for(i = 0,t = 1;i < k; ++i,t *= 3)
         cycle_leader(a,t,m * 2 +1);
      
      //step 4
      iter += (m * 2);
      n -= m;
   }
   //n = 1
   swap(a[1],a[2]);
}

int main(){
   vector<int > a;
   a.push_back(0);//to make index start from 1
   int num = 0,length = 0;
   cout<<"Please input your number to be shuffled and '0' to end up \n";
   cin>>num;
   while(num != 0){
      a.push_back(num);
      cin>>num;
   }
   cout<<"The input number is \n";
   copy(a.begin()+1,a.end(),ostream_iterator<int> (cout," "));
   cout<<"\n";
   
   length = a.size();
   assert(length % 2 == 1); //the size of input number is even
   perfect_shuffle(a,length / 2);
   
   cout<<"After shuffered,the number is  \n";
   copy(a.begin()+1,a.end(),ostream_iterator<int> (cout," "));
   cout<<"\n";
}
