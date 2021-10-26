#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define LIMIT 20

struct fact_entry
{                               /* Definition of each table entry */
  int n;
  long long int lli_fact;       /* 64-bit integer */
  char *str_fact;
};

void
panic (char *m)
{
  fprintf (stderr, "%s\n", m);
  exit (0);
}

int
main (int argc, char *argv[])
{
  int n;
  int i;
  struct fact_entry *fact_table;

  if (argc != 2)
    panic ("wrong parameters");

  n = atoi (argv[1]);
  if (n < 0)
    panic ("n too small");
  if (n > LIMIT)
    panic ("n too big");

/* Your code starts here */
  // Allocate memory
  printf("%ld\n", n*sizeof(int));
  fact_table = malloc(n*sizeof(int)); // request space for n integers
  if(fact_table == NULL) printf("Memory not available");

  // Compute fact(n) for i=0 to n
  int fact = 1;
  for (i = 0; i < n; i++){
    if (i > 1) {
      fact = fact * (i+1);
      printf("fact = %d\n", fact);
    }
    fact_table[i].n = i;
    fact_table[i].lli_fact = fact;
    fact_table[i].str_fact = "c";
    // fact = 0;
  }

/* Your code ends here */

  // print computed numbers
  for (i = 0; i <= n; i++)
    {
      printf ("%d %lld %s\n", fact_table[i].n, fact_table[i].lli_fact,
              fact_table[i].str_fact);
    }

/* Your code starts here */
  // Free memory

    free(fact_table);


/* Your code ends here */

  return 0;
}
