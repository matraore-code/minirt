#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include <limits.h>
#include <string.h>

/* rand () tire un int au hasard entre 0 et INT_MAX*/
/* rand () / INT_MAX => on obtient un nombre entre [0.0 et 1.0[*/
/*_alea = un nombren entre 0 et 8[*/
/* alea = un nombre entre 5 et 13*/


int tool_random_int (int vmin, int vmax)
{
	int amp = vmax - vmin + 1;
	double _alea = (1.0 * rand () / INT_MAX) * amp;
	int alea = (int) (vmin + _alea);
	if (alea < vmin)
		alea = vmin;
	else if (alea > vmax)
		alea = vmax;
	return alea;
}

void tools_memory_init (void)
{
	GLOBAL_ALLOC_MEMORY = 0;
}

void* tools_malloc(int alloc)
{
	void* ptr = malloc (alloc);
	GLOBAL_ALLOC_MEMORY += alloc;
	return ptr;
}

void tools_free (void* ptr, int alloc)
{
	free (ptr);
	GLOBAL_ALLOC_MEMORY -= alloc;
}

void tools_memory_check_at_end_of_app(void)
{
	if (GLOBAL_ALLOC_MEMORY != 0)
		printf ("Ce programme a une fuite de memoire.\n %d bytes n'ont pa ete liberes", GLOBAL_ALLOC_MEMORY);
}

void int_swap (int* a, int* b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// int get_int (int minv, int maxv)
// {
//   int n;
//   if(scanf ("%d", &n))
//       while ((n < minv) || (n > maxv))
// 	{
// 	  printf ("min =  %d ; max = %d", minv, maxv);
// 	  if(scanf ("%d", &n))
// 	}
//       return n;
// }

/*
 * ok veut 1 si pas de caractere autre que '0'-'9'
 * ok veut 0 sinon
 */
int safe_string_to_int (char *str, int *ok)
{
	if (str[0] == '-')
		return ( - safe_string_to_int (str + 1, ok));
	int n;
	int i;

	*ok = 1;
	n = 0;
	i = 0;
	if (!str[0])
	{
		*ok = 0;
		return (0);
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			*ok = 0;
			return (0);
		}
		n *= 10;
		n += (str[i] - '0');
		i++;
	}
	return (n);

}
int string_to_int (char *str)
{
	int ok;
	int n = safe_string_to_int (str, &ok);
	if (ok == 0)
		printf("string_to_int : la chaine %s n'est pas numerique\n", str);
	return (n);
}


/*
** le for est execute b fois exactement.
** Dans ce for , il y a 5 operations elementaires.
** 
** Nombre d'operations elementaires total :
** 5 * b => de l'ordre de b.
** 
** La complexite algorthmique en temps
** de puiss_iter est :
** - de l'ordre de b.
** - fonction lineaire de b;
*/
float puiss_iter (float a, int b)
{
	float r = 1;
	int i;
	if (b < 0)
		return (1.0 / puiss_iter (a, -b));

	for (i = 1; i <= b; i++)
		r *= a;
	return r;
}

/*
** la complixite en temps de puisse_rec est
** fonction lineare de b car il y a exactement
** b appels recursifs
**
*/

float puiss_rec (float a, float b)
{
	if (b < 0)
		return (1.0 /puiss_rec(a, -b));
	else if (b == 0)
		return (1);
	else
		return (a * puiss_rec(a, b - 1));
}

/*
		
	   c (b)
	2 ^       = b
	c(b) = log_2 (b)

	complexite logarithmique
	complexite est une fonction logarithmique de b
*/

// float puiss_alex (float a, int b)
// {
// 	if (b < 0)
// 		return (1.0 / puiss_alex(a, -b));
// 	else if (b == 0)
// 		return (1);
// 	else if (b % 2 == 0)
// 		return (puiss_alex(a * a, b / 2));
// 	else if (b % 2 != 0)
// 		return (a * puiss_alex (a * a, b / 2));
// }

void int_normalize_and_warn (int* n, int minv, int maxv)
{
  if (*n < minv)
    {
      fprintf(stderr, "int %d normalized to %d.\n", *n, minv);
      *n = minv;
    }
  else if (*n > maxv)
    {
      fprintf(stderr, "int %d normalized to %d.\n", *n, maxv);
      *n = maxv;
    }
}

void int_normalize (int* n, int minv, int maxv)
{
  if (*n < minv)
    *n = minv;
  else if (*n > maxv)
    *n = maxv;
}

char* regstr_clone (char* str)
{
  int len = strlen (str);
  char* clone = (char *) tools_malloc (sizeof (char) * (len + 1));
  int i;
  for (i = 0; i < len; i++)
    clone[i] = str[i];
  clone[i] = '\0';
  return clone;
}

void regstr_destroy (char** sstr)
{
  regstr_destroy_of_len (sstr, strlen (*sstr));
}

void regstr_destroy_of_len (char** sstr, int len)
{
      char* str = *sstr;
      tools_free (str, sizeof (char) * (len + 1));
      *sstr = NULL;
}

bool regstr_equal (char* str1, char* str2)
{
  int i = 0;
  int j = 0;
  while ((str1[i] != '\0') && (str2[j] != '\0'))
    {
      if (str1[i] != str2[j])
		return FALSE;
      i++;
      j++;
    }
  
  if (str1[i] == str2[j] && i == j)
    return TRUE;
  else
    return FALSE;
}


static int	digitlen(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

// char		*ft_itoa(int n)
// {
// 	int		m;
// 	char	*str;
// 	long	nb;

// 	nb = n;
// 	m = digitlen(n);
// 	if (!(str = (char *)malloc(m + 1)))
// 		return (NULL);
// 	if (nb == 0)
// 	{
// 		str[0] = 0 + '0';
// 	}
// 	if (nb < 0)
// 	{
// 		nb *= -1;
// 		str[0] = '-';
// 	}
// 	while (nb != 0)
// 	{
// 		str[m - 1] = nb % 10 + '0';
// 		nb /= 10;
// 		m--;
// 	}
// 	str[digitlen(n)] = '\0';
// 	return (str);
// }	



bool d_equal (double n1, double n2)
{
	if (fabs(n1 - n2) < EPSILON)
		return TRUE;
	else
		return FALSE;
}