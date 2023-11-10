#include <stdio.h>
#include <string.h>

int main(void) {
  char exp[] = "(55+55-1)";
  const char delim[] = "(+-*/)";
  char *token;

  token = strtok(exp, delim);

  while (token != NULL) {
    printf("%s\n", token);

    token = strtok(NULL, delim);
  }

  return 0;
}
