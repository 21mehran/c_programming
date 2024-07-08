// Create a deadlock and resolve it.

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

void *first_thread (void *arg)
{
	pthread_mutex_lock (&mutex1);
	printf ("first thread : Acquired mutex 1\n");

	pthread_mutex_lock (&mutex2);
	printf ("first thread : Acquired mutex 2\n");

	pthread_mutex_unlock (&mutex2);
	printf ("first thread : Released mutex 1\n");

	pthread_mutex_unlock (&mutex1);
	printf ("first thread : Release mutex 2\n");

}

void *second_thread (void *arg)
{
        pthread_mutex_lock (&mutex2);
        printf ("second thread : Acquired mutex 1\n");

        pthread_mutex_lock (&mutex1);
        printf ("second thread : Acquired mutex 2\n");

        pthread_mutex_unlock (&mutex1);
       	printf ("second thread : Released mutex 1\n");

        pthread_mutex_unlock (&mutex2);
        printf ("second thread : Release mutex 2\n");

}

int main ()
{
	pthread_t first, second;

	pthread_create (&first, NULL, first_thread, NULL);
	pthread_create (&second, NULL, second_thread, NULL);

	pthread_join (first, NULL);
        pthread_join (second, NULL);	

	return 0;
}

/*
1. pthread_mutex_lock & pthread_mutex_unlock are used for locking and unlocking mutexes.
2. pthread_create creates a new thread to execute a specified function.
3. pthread_join waits for a thread to complete its execution before continuing with main thread.
4. PTHREAD_MUTEX_INITIALIZER is macro provided to initialise pthread_mutex_t variable with default values. 
5. It is used instead of pthread_mutex_init (&mutex, NULL);
*/

/* 
 * To resolve the deadlock acquire the mutex in the same sequence in both threads.
*/
