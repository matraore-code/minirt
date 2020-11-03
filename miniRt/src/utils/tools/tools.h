#ifndef __TOOLS_H
# define __TOOLS_H

# include <stdlib.h>
# include <stdio.h>

#include <math.h>

typedef char bool;

#define TRUE 1
#define FALSE 0

#define EPSILON 0.00001



int GLOBAL_ALLOC_MEMORY;

int tool_random_int (int vmin, int vmax);
void tools_memory_init (void);
void* tools_malloc(int alloc);
void tools_free (void * ptr, int alloc);
void tools_memory_check_at_end_of_app(void);

void int_swap (int* a, int* b);
int safe_string_to_int (char *str, int *ok);
int string_to_int (char *str);

int get_int (int minv, int maxv);

float puiss_iter (float a, int b);
float puiss_rec (float a, float b);
float puiss_alex (float a, int b);

void int_normalize_and_warn (int* n, int minv, int maxv);
void int_normalize (int* n, int minv, int maxv);

char* regstr_clone (char* str);
void regstr_destroy (char** sstr);

void regstr_destroy_of_len (char** sstr, int len);

bool regstr_equal (char* str1, char* str2);

char		*ft_itoa(int n);

bool d_equal (double n1, double n2);

#endif
