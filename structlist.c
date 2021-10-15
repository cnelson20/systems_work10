#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct college; 

struct college {
  char *name;
  char *location;
  int ncaa_div;
  int student_population;
  struct college *next;
};

int main();
struct college *generate_college();
void print_college(struct college *uni);
void print_list(struct college *c); 
struct college *free_list(struct college *c);

int main() {
  struct college *uc;
  struct college *michtech;
  struct college *dartmouth;
  
  while (1 || getchar()) {
    uc = generate_college("University of Chicago","Chicago, IL",6989,3);
    michtech = generate_college("Michigan Technological University","Houghton, MI",5642,2);
    dartmouth = generate_college("Dartmouth College","Hanover, NH",4170,1);

    uc->next = michtech;
    michtech->next = dartmouth;
    print_list(uc);

    free_list(uc);
    
  }
  return 0;
}
struct college *generate_college(char *n, char *place,int body, int div) {
  struct college *u = malloc(sizeof(struct college));
  u->name = malloc(strlen(n));
  strcpy(u->name,n);
  u->location = malloc(strlen(place));
  strcpy(u->location,place);
  u->student_population = body; 
  u->ncaa_div = div;
  u->next = NULL;
  return u;
}
void free_college(struct college *c) {
  free(c->name);
  free(c->location);
  free(c);
}
void print_college(struct college *uni) {
  printf("%s:\n\tLocation: %s\n\tStudent Body: %d\nNCAA Division: %d\n",uni->name,uni->location,uni->student_population,uni->ncaa_div);
}
void print_list(struct college *c) {
  while (c) {
    print_college(c); 
    c = c->next;
  }
}
struct college *free_list(struct college *c) {
  if (c->next) {
    free_list(c->next);
  }
  free_college(c);
  
  return c;
}
