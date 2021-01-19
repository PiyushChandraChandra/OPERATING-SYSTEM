#include<stdio.h>
#include<pthread.h>

#define NUM_LOOP 500000000
long long sum = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* counting_thread(void *args)
{
	int offset = *(int *) args;
	for (int i=0; i < NUM_LOOP; i++)
	{
		
		pthread_mutex_lock(&mutex);
		//critical section
		sum+= offset;
		
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}

int main()
{
	//spawn threads

	pthread_t id1;
	int offset1 = 1;
	pthread_create(&id1, NULL, counting_thread, &offset1);
	
	pthread_t id2;
	int offset2 = -1;
	pthread_create(&id2, NULL, counting_thread, &offset2);
	
	//wait for threads to finish
	pthread_join(id1, NULL);
	pthread_join(id2, NULL);

	
	printf("sum = %lld\n", sum);
	return 0;
}

