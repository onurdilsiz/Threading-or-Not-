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

int*numbers;
int N;
int minn,maxx,range,modee,median;
long long int sum;
double mean, harmonicMean,standardDev,interQuartile;

void *findMin(void *param);
void *findMax(void *param);
void *findRange(void *param);
void *findMode(void *param);
void *findMedian(void *param);
void *findSum(void *param);
void *findArithmeticMean(void *param);
void *findHarmonicMean(void *param);
void *findStandardDev(void *param);
void *findInterQuartile(void *param);

int main(int argc, char *argv[]){

    ofstream myfile;
    myfile.open ("output2.txt");
    
    pthread_t tid[10]; /* the thread identifier */
    pthread_attr_t attr; /* set of attributes for the thread */
    N= atoi(argv[1]);
  
   numbers =new int [N];
    for (int i=0; i < N; i++){
        
        int randNum = rand()%9001+ 1000;
        numbers[i]=randNum;
        
    }

    struct timespec start;
    struct timespec finish;
    struct timespec delta;

    std::sort(numbers, numbers + N);

    clock_gettime(CLOCK_REALTIME, &start);


    
    pthread_attr_init(&attr); // initialize the thread attributes with default configuration
 
    pthread_create(&tid[0],&attr,findMin,NULL); 
    pthread_create(&tid[1],&attr,findMax,NULL);
    pthread_create(&tid[2],&attr,findRange,NULL);
    pthread_create(&tid[3],&attr,findMode,NULL);
    pthread_create(&tid[4],&attr,findMedian,NULL);
    pthread_create(&tid[5],&attr,findSum,NULL);
    pthread_create(&tid[6],&attr,findArithmeticMean,NULL);
    pthread_create(&tid[7],&attr,findHarmonicMean,NULL);
    pthread_create(&tid[8],&attr,findStandardDev,NULL);
    pthread_create(&tid[9],&attr,findInterQuartile,NULL);

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_join(tid[2], NULL);
    pthread_join(tid[3], NULL);
    pthread_join(tid[4], NULL);
    pthread_join(tid[5], NULL);
    pthread_join(tid[6], NULL);
    pthread_join(tid[7], NULL);
    pthread_join(tid[8], NULL);
    pthread_join(tid[9], NULL);
    

   
    myfile<< minn<<endl;
  
    myfile<< maxx<<endl;
  
    myfile<< range<<endl;
    
    myfile<<modee<<endl;
   
    myfile<<setprecision(5)<< median<<endl;

    myfile<<sum<<endl;

    myfile<<setprecision(5)<<mean<<endl;

    myfile<<setprecision(5)<<harmonicMean<<endl;

    myfile<<setprecision(5)<<standardDev<<endl;

    myfile<<setprecision(5)<<interQuartile<<endl;

    clock_gettime(CLOCK_REALTIME, &finish);
    
    double executionTime = (finish.tv_sec - start.tv_sec) * 1000.0;
    executionTime += (finish.tv_nsec - start.tv_nsec) / 1000000.0;
    executionTime /= 1000.0;

    myfile<<executionTime;
    myfile.close();

  
    return 0;
}



void * findMin(void * param){
   
    minn=numbers[0];
    for(int i=0; i < N; i++){
        if(minn>numbers[i]){
        minn=numbers[i];
        }
    }

    pthread_exit(0); // exit thread
    


}

void * findMax(void* param){


    maxx=numbers[N-1];

    for(int i=0; i < N; i++){
       
        if(maxx<numbers[i]){
        maxx=numbers[i];
        }
    }
    
    pthread_exit(0); // exit thread

}
void *findRange(void *param){
    range=numbers[N-1]-numbers[0];
}

void * findMode(void * param){
   
    int number = numbers[0];
    modee = number;
    int count = 1;
    int countMode = 1;

    for (int i=1; i<N; i++)
    {
          if (numbers[i] == number) 
          { // count occurrences of the current number
            count++;
          }
          else
          { // now this is a different number
                if (count > countMode) 
                {
                      countMode = count;
                      modee = number;
                }
              count = 1; 
              number = numbers[i];
      }
        if (count > countMode) 
                {
                      countMode = count; 
                      modee = number;
                }

    }

    pthread_exit(0); // exit thread

}


void* findMedian(void* param){
   median=0;
   
   if(N%2==0){
      median= ((double)numbers[N/2-1]+(double)numbers[N/2])/2;
    }else{
      median=(double)numbers[N/2];
    }
    
    pthread_exit(0); 
}



void * findSum(void * param){
    sum=0;
    for(int i =0;i<N;i++){
      sum+=numbers[i];

    }
      pthread_exit(0); 


}

void * findArithmeticMean(void * param){
    long long int summ=0;
     for(int i =0;i<N;i++){
      summ+=numbers[i];

    }
    mean= (double)summ/N;
    pthread_exit(0); 
}
   

void * findHarmonicMean(void * param){
    double revSum=0;
     for(int i =0;i<N;i++){
      revSum += (double)1/ (double)numbers[i];    

    }
    harmonicMean= N/revSum;
   pthread_exit(0);
}


void * findStandardDev(void * param){
  long long int summ=0;
     for(int i =0;i<N;i++){
      summ+=numbers[i];

    }
    mean= (double)summ/N;

  

  double sumDev=0;
    for(int i =0;i<N;i++){
        sumDev+= ( (numbers[i]-mean)*(numbers[i]-mean));  
      
    }
    standardDev= sqrt((double) sumDev/(N-1));
  
    pthread_exit(0);

}

void * findInterQuartile(void * param){
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
 

    interQuartile= medianOfSecond-medianOfFirst;

    pthread_exit(0);
  

  
}