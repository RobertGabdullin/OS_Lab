#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define MAXN 512
#define MaxTime 1000000000 // 10^9 operations ~ 1 min

int buffer[MAXN], posProducer = 0, posConsumer = 0, cnt = 0, sleepCon = 0, sleepProd = 0;
long long Time = 0;

void * Consumer(){
	while(1){
		if(cnt == 0){
			sleepCon = 1; // *
			while(sleepCon == 1);
		}
		buffer[posProducer] = 0;
		cnt--;
		posConsumer = (posConsumer + 1) % MAXN;
		if(cnt == MAXN - 1){
			sleepProd = 0;
		}
	}
}

void *Producer(){
	while(1){
		if(cnt == MAXN){
			sleepProd = 1;
			while(sleepProd == 1);
		}
		buffer[posProducer] = 1;
		if(Time == 0) printf("1\n");
		Time = (Time + 1)%MaxTime;
		cnt++;
		posProducer = (posProducer + 1) % MAXN;
		if(cnt == 1){
			sleepCon = 0; // <- If at some moment we try to wake up the Consumer before
			              //  we put him to sleep (noted * in the comments above), then ultimately the 
				      //consumer will no longer wake up, but the producer will fill the buffer and fall
			              // asleep. As a result, both will sleep and never wake up.
		}
	}
}

int main(){

	pthread_t pr, con;
	pthread_create(&pr, NULL, Producer, NULL);
	pthread_create(&con, NULL, Consumer, NULL);
	pthread_join(pr, NULL);
	pthread_join(con, NULL);

}

