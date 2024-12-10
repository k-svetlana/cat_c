#include "cat.h"
#define _GNU_SOURCE

int main(int argc, char **argv) {
  if (argc > 1 && argv[1][0] == '-') {
    options flag = {0};
    options_parse(argc, argv, &flag);
    if (flag.err == 1) {
      fprintf(stderr, "usage: 21s_cat [-benstv] [file ...]\n");
    } else {
      for (int i = 1; i < argc; i++) {
        cat(flag, argv[i]);
      }
    }
  } else {
    for (int i = 1; i < argc; i++) {
      print(argv[i]);
    }
  }
  return 0;
}

int options_parse(int argc, char **argv, options *flag) {
  int c = 0;

  // int getopt_long(int argc, char * const argv[], const char *optstring, const
  // struct option *longopts, int *longindex); man-pages: const struct option
  // *longopts longopts is a pointer to the first element of an array of struct
  // option declared in <getopt.h> as struct option {
  //     const char *name;
  //     int         has_arg;
  //     int        *flag;
  //     int         val;
  // };

  while ((c = getopt_long(argc, argv, SHORTOPTS, longopts, NULL)) != -1) {
    switch (c) {
      case 'b':
        flag->b = 1;
        break;
      case 'n':
        flag->n = 1;
        break;
      case 'v':
        flag->v = 1;
        break;
      case 's':
        flag->s = 1;
        break;
      case 'e':
        flag->e = flag->v = 1;
        break;
      case 'E':
        flag->e = 1;
        break;
      case 't':
        flag->t = flag->v = 1;
        break;
      case 'T':
        flag->t = 1;
        break;
      case '?':
        flag->err = 1;
        break;
    }
  }
  return flag->err;
}

void print(char *filename) {
  FILE *ptrFile = fopen(filename, "r");
  if (ptrFile != NULL) {
    int a = fgetc(ptrFile);
    while (a != EOF) {
      fputc(a, stdout);
      a = fgetc(ptrFile);
    }
    fclose(ptrFile);
  } else
    nofile(filename);
}

void cat(options flag, char *filename) {
  FILE *ptrFile = fopen(filename, "r");
  if (ptrFile != NULL) {
    char ch, prev;
    int line = 1;
    int blank_line = 0;

    for (prev = '\n'; (ch = getc(ptrFile)) != EOF; prev = ch) {
      if (flag.b == 1 && prev == '\n') {
        if (ch != '\n') {
          printf("%*d\t", 6, line);
          line++;
        }
      }
      if (flag.n == 1 && flag.b == 0 && prev == '\n') {
        printf("%*d\t", 6, line);
        line++;
      }
      if (flag.v == 1) {
        if ((ch >= 0 && ch <= 31) && ch != '\t' && ch != '\n') {
          printf("^");
          ch = ch + 64;
        } else if (ch == 127) {
          printf("^");
          ch = ch - 64;
        }
      }
      if (flag.s == 1) {
        if (ch == '\n' && prev == '\n') {
          if (blank_line == 1) {
            continue;
          }
          blank_line++;
        } else
          blank_line = 0;
      }
      if (flag.e == 1 && ch == '\n') {
        putchar('$');
      }
      if (flag.t == 1 && ch == '\t') {
        printf("^");
        ch = 'I';
      }
      putchar(ch);
    }
    fclose(ptrFile);
  }
}

void nofile(char *filename) {
  fprintf(stderr, "cat: %s: No such file or directory\n", filename);
}
