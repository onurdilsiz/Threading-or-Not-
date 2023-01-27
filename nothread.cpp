#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <cstdio>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <unistd.h>
#include <fstream>
#include <iomanip>


using namespace std;
int N;




int findMode(int array []){

    int number = array[0];
    int mode = number;
    int count = 1;
    int countMode = 1;

    for (int i=1; i<N; i++)
    {
          if (array[i] == number) 
          { // count occurrences of the current number
            count++;
          }
          else
          { // now this is a different number
                if (count > countMode) 
                {
                      countMode = count;
                      mode = number;
                }
              count = 1; 
              number = array[i];
      }
        if (count > countMode) 
                {
                      countMode = count; 
                      mode = number;
                }
    }

   
    return mode;

}

int findMin(int* array){
  int min=array[0];
  for(int i=0; i < N; i++){
    if(min>array[i]){
      min=array[i];
    }
  }
  return min;
  

}
int findMax(int* array){
  int max=array[N-1];
  for(int i=0; i < N; i++){
    if(max<array[i]){
      max=array[i];
    }
  }
  return max;
  

}

double findMedian(int* numbers){
   double median=0;
   if(N%2==0){
      median= ((double)numbers[N/2-1]+(double)numbers[N/2])/2;
    }else{
      median=(double)numbers[N/2];
    }
    return median;

}


long long int findSum(int* numbers){
    long long int sum=0;
    for(int i =0;i<N;i++){
      sum+=numbers[i];

    }
    return sum;


}

double findArithmeticMean(int* numbers){
    long long int sum=findSum(numbers);
    double mean= (double)sum/N;
    return mean;
}

double findHarmonicMean(int* numbers){
  double revSum=0;
     for(int i =0;i<N;i++){
      revSum += (double)1/ (double)numbers[i];    

    }
    double harmonicMean= N/revSum;
  return harmonicMean;
}

double findStandardDev(int* numbers){

  double mean = findArithmeticMean(numbers);

  double sumDev=0;
    for(int i =0;i<N;i++){
        sumDev+= ( (numbers[i]-mean)*(numbers[i]-mean));  
      
    }
  double standardDev= sqrt((double) sumDev/(N-1));
  return standardDev;


}

double findInterquartile(int* numbers){
  int* lowerPart = new int[N/2];
  int* higherPart = new int[N/2];
  if(N%2==0){
      for(int i=0;i<N/2;i++){
        lowerPart[i] = numbers[i];
        higherPart[i] = numbers[N/2+i];
      }
  }else{
     for(int i=0;i<N/2;i++){
        lowerPart[i] = numbers[i];
        higherPart[i] = numbers[N/2+i+1];
      }

  }
  
  double medianOfFirst=0;
   if(N/2%2==0){
     medianOfFirst= ((double)lowerPart[N/4-1]+(double)lowerPart[N/4])/2;
    }else{
      medianOfFirst=(double)lowerPart[N/4];
    }
  double medianOfSecond=0;
   if(N/2%2==0){
     medianOfSecond= ((double)higherPart[N/4-1]+(double)higherPart[N/4])/2;
    }else{
      medianOfSecond=(double)higherPart[N/4];
    }
 

  double interQuartile= medianOfSecond-medianOfFirst;
  return interQuartile;

}

int main(int argc, char *argv[]){

    ofstream myfile;
    myfile.open ("output1.txt");
    
    pthread_t tid; /* the thread identifier */
    pthread_attr_t attr; /* set of attributes for the thread */
    
    N= atoi(argv[1]);
    int* numbers = new int[N];

    int maxNo=10000;
    int minNo=1000;
    for (int i=0; i < N; i++){
        
        int randNum = rand()%(maxNo-minNo + 1) + minNo;
        numbers[i]=randNum;
        
    }
    struct timespec start, finish, delta;
   
    std::sort(numbers, numbers + N);

    clock_gettime(CLOCK_REALTIME, &start);
   
    int min=findMin(numbers);
    myfile<< min<<endl;
    
    int max=findMax(numbers);
    myfile<< max<<endl;

    int range=max-min;
    myfile<< range<<endl;
    
    int mode= findMode(numbers);
    myfile<<mode<<endl;
    
    int median= findMedian(numbers);
    myfile<< setprecision(5)<< median<<endl;
    
    long long int sum=findSum(numbers);
    myfile<<sum<<endl;

    double arithmeticMean=findArithmeticMean(numbers);
    myfile<<setprecision(5)<< arithmeticMean<<endl;

    double harmonicMean=findHarmonicMean(numbers);
    myfile<<setprecision(5)<< harmonicMean<<endl;

    double standardDev=findStandardDev(numbers);
    myfile<<setprecision(5)<< standardDev<<endl;

    double interquartileRange=findInterquartile(numbers);
    myfile<<setprecision(5)<< interquartileRange<<endl;

    clock_gettime(CLOCK_REALTIME, &finish);
    double executionTime = (finish.tv_sec - start.tv_sec) * 1000.0;
    executionTime += (finish.tv_nsec - start.tv_nsec) / 1000000.0;
    executionTime /= 1000.0;

    myfile<<executionTime;
    
    myfile.close();

  return 0;
}