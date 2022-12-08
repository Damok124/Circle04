#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int	ft_strlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

typedef struct s_lst{
	char			*str;
	//char			**strs;
	int				n;
	//int				*p;
	struct s_lst	*next;
}					t_lst;

void	ft_modif(t_lst *lst)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	new->str = NULL;
	new->n = 250;
	new->next = NULL;
	lst->str[0] = 'B';
	lst->n = 150;
	lst->next = new;
}


void	ft_trafic(t_lst *lst)
{
	while (lst)
	{
		lst->n *= 2;
		lst = lst->next;
	}
}

int	main(void)
{
	t_lst *lst;
	char	**test;
	char	*str;
	//int	tab[2];

	test = (char **)malloc(sizeof(char *) * 5);
	test[4] = NULL;
	lst = (t_lst *)malloc(sizeof(t_lst));
	lst->str = (char *)malloc(sizeof(char) * 8);
	lst->str[0] = 'b';
	lst->str[1] = 'o';
	lst->str[2] = 'n';
	lst->str[3] = 'j';
	lst->str[4] = 'o';
	lst->str[5] = 'u';
	lst->str[6] = 'r';
	lst->str[7] = '\0';
	str = getenv("PATH");
	test[0] = lst->str;
	test[1] = lst->str;
	test[2] = lst->str;
	test[3] = lst->str;
	//ft_modif(lst);
	//ft_trafic(lst);
	//printf("%d, %s\n", lst->n, lst->str);
	//printf("%d, %s\n", lst->next->n, lst->next->str);
	//tab[0] = 5;
	//tab[1] = tab[0] * 5;
	//printf("%d %d\n", tab[0], tab[1]);
	printf("%s\n", lst->str);//bonjour
	//lst->str[3] = '\0';
	lst->str = lst->str + 3;
	printf("%s\n", lst->str);//jour
	printf("%s\n", str);
	printf("%p %p\n", lst->str, str);
	printf("test :%d\n", ft_strlen(test));
	free(lst->str - 3);
	free(lst);
	//verif si transmettre un lst** est nécessaire
	//verif si un str déplacé permet toujours de le free ou non
	return (0);
}
