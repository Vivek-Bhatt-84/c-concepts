#include<bits/stdc++.h>

#define NUM_THREADS  5
using namespace std;

int sharedCounter = 0;
pthread_mutex_t mtx;

void* incrementCounter(void* threadID){
    long tid = long(threadID);

    pthread_mutex_lock(&mtx);

    for(int i = 0 ; i < 10000 ; i++){
        sharedCounter++;
    }

    cout << "Thread " << threadID << "has finished incrementing " << endl;

    pthread_mutex_unlock(&mtx);
    pthread_exit(nullptr);

}

int main(){
    pthread_t t[NUM_THREADS];
    pthread_mutex_init(&mtx,nullptr);

    for(long i = 0 ; i < NUM_THREADS ; i++){
        if(pthread_create(&t[i] , nullptr , incrementCounter , (void*)i) != 0){
            cerr << "Error creating thread " << i << endl;
            return 1;
        }
    }

    for (int i = 0; i < NUM_THREADS; ++i) {

        pthread_join(t[i], nullptr);

    }


    // Destroy the mutex

    pthread_mutex_destroy(&mtx);


    std::cout << "Final counter value: " << sharedCounter << std::endl;

    return 0;



return 0;
}