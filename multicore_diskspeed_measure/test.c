#define _GNU_SOURCE

#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#include <stdlib.h>
#include <stdio.h>


// busy wait for time
// rough attempt to sync threads
int wait_for_time(const struct timespec t)
{
	struct timespec t2;
	while(clock_gettime(CLOCK_REALTIME, &t2) == 0)
	{
		long nano_delta = 1000000000 * (t.tv_sec - t2.tv_sec)
			+ (t.tv_nsec - t2.tv_nsec);
		if (nano_delta < 0)
		{
			return 0;
		}
	}
	return 1;
}

struct thread_data
{
	struct timespec t;
	int count;
};

void* work(void* data)
{
	struct thread_data *tdata = (struct thread_data*)data;
	int num = tdata->count;

	char *fname;
	asprintf(&fname, "./%d", num);

	int fd = open(fname, O_RDONLY);
	
	off_t fsize = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);

	char* buf = malloc(fsize);

	if (wait_for_time(tdata->t))
	{
		perror("");
		fprintf(stderr, "bad wait\n");
	}

	ssize_t tot_read;
	while ((tot_read = read(fd, buf, fsize - tot_read)) > 0)
	{

	}
	return NULL;
}


int main(int argc, char const *argv[])
{
	int num_threads = strtoul(argv[1], NULL, 10);

	pthread_t *threads = malloc(num_threads * sizeof (pthread_t));
	struct thread_data *data = malloc(num_threads * sizeof *data);

	struct timespec start_time;
	if (clock_gettime(CLOCK_REALTIME, &start_time))
	{
		perror("");
	}

	start_time.tv_sec += 2;
	for (int i = 0; i < num_threads; ++i)
	{
		data[i].count = i;
		data[i].t = start_time;
		
		pthread_create(
			threads + i,
			NULL,
			work,
			data + i
			);
	}

	for (int i = 0; i < num_threads; ++i)
	{
		pthread_join(
			threads[i],
			NULL
			);
	}

	return 0;
}
