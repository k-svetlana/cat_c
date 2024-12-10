#ifndef _CAT_H_
#define _CAT_H_

#include <getopt.h>
#include <stdio.h>

#define SHORTOPTS "bnvseEtT?"

typedef struct {
  int b;
  int n;
  int v;
  int s;
  int e;
  int t;
  int err;
} options;

const struct option longopts[] = {{"number-nonblank", 0, NULL, 'b'},
                                  {"number", 0, NULL, 'n'},
                                  {"squeeze-blank", 0, NULL, 's'},
                                  {NULL, 0, NULL, 0}};

void print(char *filename);
int options_parse(int argc, char **argv, options *flag);
void cat(options flag, char *filename);
void nofile(char *filename);

#endif /* _CAT_H */
