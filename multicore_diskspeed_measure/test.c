#define _GNU_SOURCE

#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <error.h>
#include <errno.h>

#include <stdlib.h>
#include <stdio.h>

#define err() error_at_line(\
    1, errno, __FILE__, __LINE__, "%s", __FUNCTION__);

// busy wait for time
// rough attempt to sync threads
int wait_for_time(const struct timespec t, struct timespec *tstart)
{
	while(clock_gettime(CLOCK_REALTIME, tstart) == 0)
	{
		long nano_delta = 1000000000 * (t.tv_sec - tstart->tv_sec)
			+ (t.tv_nsec - tstart->tv_nsec);
		// fprintf(stderr, "%ld\n", nano_delta);
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
	if (asprintf(&fname, "./%d", num) < 0)
	{
		err();
	}

	int fd = open(fname, O_RDONLY
		|O_DIRECT // this needs aligned memory
		);
	if (fd < 0)
	{
		err();
	}
	
	off_t fsize = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);

	// char* buf = malloc(fsize);
	char* buf;
	posix_memalign((void**)&buf, 512, fsize);

	struct timespec tstart;
	if (wait_for_time(tdata->t, &tstart))
	{
		err();
	}

	ssize_t tot_read = 0;
	ssize_t this_read = 0;
	size_t next_read = fsize - tot_read;
	do
	{
		next_read = fsize - tot_read;
		tot_read += this_read;
		if (next_read > 1024 * 1024 * 1024)
		{
			next_read = 1024 * 1024 * 1024;
		}
	} 
	while ((this_read = read(fd, buf + tot_read, next_read)) > 0);
	if (this_read < 0)
	{
		err();
	}

	struct timespec tstop;
	clock_gettime(CLOCK_REALTIME, &tstop);

	// start time (millis) runtime (millis)
	// bytes read, MB / s
	long elapsed_millis = (tstop.tv_sec - tstart.tv_sec) * 1000
			+ (tstop.tv_nsec - tstart.tv_nsec) / 1000000;
	fprintf(stderr, 
		"%ld\t%ld\t%ld\t%ld\n", 
		(tstart.tv_sec - tdata->t.tv_sec) * 1000000 
			+ (tstart.tv_nsec - tdata->t.tv_nsec) / 1000,		
		(tstop.tv_sec - tstart.tv_sec) * 1000000 
			+ (tstop.tv_nsec - tstart.tv_nsec) / 1000,
		tot_read,
		tot_read / elapsed_millis * 1000 / 1024 / 1024
		);
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

	start_time.tv_sec += 1;
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
