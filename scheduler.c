#include "runtime.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scheduler_fifo()
{
  int num_jobs = get_num_jobs();
  int arrival = get_current_time();
  
  float total_turnaround = 0.0f, total_response = 0.0f;
  for (int i = 0; i < num_jobs; i++) {
    int firstrun = get_current_time();
    printf("job %d started at %d\n", i, firstrun);
    total_response += firstrun - arrival;
    
    int r;
    while ((r = schedule_job(i, 9)) >= 0)
      printf("job %d run for %d at %d\n", i, r, get_current_time());
    
    int completion = get_current_time();
    printf("job %d finished at %d\n", i, completion);
    
    total_turnaround += completion - arrival;
  }
  
  printf("Average turnaround time was %f\n", total_turnaround / num_jobs);
  printf("Average response time was %f\n", total_response / num_jobs);
}

void scheduler_rr(int time)
{
  
  int num_jobs = get_num_jobs();
  

  //int arrivals[10];
  int bursts[10];
  int start_time;
  int completion_time;
  
  for(int i=0;i<num_jobs;i++) 
  {
    int total_turnaround;
   // arrivals[i]=get_current_time();
    printf("Enter Burst Time for Job %d :",i+1); 
    scanf("%d",&bursts[i]); 
   
    start_time = get_current_time();
    printf("job %d started at %d\n", i, start_time);
    schedule_job(i, time);
    completion_time = get_current_time();
    printf("job %d finished at %d\n", i, completion_time);
    total_turnaround = completion_time-start_time;
    printf("total turnaround: %d\n",total_turnaround);
     
    }

}
void scheduler_mlfq()
{

	int i;
	int num_jobs = get_num_jobs();
	int jobs[num_jobs];
	int arrivals[num_jobs];
        int bursts[num_jobs];
	int priorities[num_jobs];
	int queue[num_jobs];

	for (i = 0; i < num_jobs; i++){
		

		printf("\n Job number: %d", i);
		jobs[i] = i;
                int start_time;
		start_time = get_current_time();
		
		printf("\n Arrival time: %d", start_time);
		arrivals[i] = start_time;
		printf("Burst time:");
		scanf("%d",&bursts[i]);
		printf("Priority:");
		scanf("%d",&priorities[i]); 
}
	//organizing priority categories into queues

	int uniq_priorities=[num_jobs];


	for (int j =0; j < num_jobs; j++){
		
		for 
		if (priorities[i] 
		
		
		
	

}

void help()
{
  printf("Usage: scheduler [-s seed] [-n jobs] [-t time_flag] fifo|rr|mlfq\n");
  exit(1);
}

int main(int argc, char* argv[])
{
  int seed = 4;
  int jobs = 2;
  int time_slice = 0;

  char c;
  while ((c = getopt(argc, argv, "n:t:s:h")) != -1) {
    switch (c) {
    
    case 'n':
      jobs = atoi(optarg);
      break;
    case 't':
      time_slice = atoi(optarg);
      break;
     case 's':
      seed = atoi(optarg);
      break;

      default:
      help();
    }
  }
  
  init_simulation(seed, jobs);

  if (argv[optind] == NULL || strcmp(argv[optind], "fifo") == 0)
    scheduler_fifo();
  else if (strcmp(argv[optind], "rr") == 0)
    scheduler_rr(time_slice);
  else if (strcmp(argv[optind], "mlfq") == 0)
    scheduler_mlfq();
  else
    help();
  
  return 0;
}