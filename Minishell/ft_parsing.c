/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 08:01:28 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/07 12:17:59 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>
#include <fcntl.h>

#define SRC 0
#define TRANS 1
#define STDIN 0
#define STDOUT 1
#define STDERR 2
#define SIMPLE 0
#define DOUBLE 1
/*
typedef struct s_size {
	int	second;
	int	third;
}		t_size;///////revoir

typedef struct s_blocks {
	char	**src;
	char	**src_trans;
}			t_blocks;//////////inutile


typedef struct s_layers {
	char	*src;
	char	*src_trans;
	int		src_len;
}			t_layers;////////doublon
*/

typedef struct s_sections {
	char	*first;
	char	*mid;
	char	*new_mid;
	char	*last;
	int		*cut;
}			t_sections;

typedef struct s_quantity {
	int	cmds;
	int	redirections;
}		t_quantity;///////////a eviter si possible

typedef struct s_parsed {
	int				empty;
	char			**cmds;
	char			**redirections;
	int				heredocs;
	struct s_parsed	*next;
}					t_parsed;

typedef struct s_book {
	char			*src;
	char			*s_trans;
	char			**dest;
	char			**d_trans;
	struct s_book	*next;
}					t_book;

typedef struct s_twins {
	char	**src;
	char	**trans;
	int		len;
}			t_twins;

void	ft_close_stdfds(void)
{
	close(STDIN);
	close(STDOUT);
	close(STDERR);
}

void	ft_true_free(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void ft_full_free(void **tobefreed)
{
	int i;

	i = -1;
	while (tobefreed && tobefreed[++i])
		ft_true_free(&tobefreed[i]);
	free(tobefreed);
	tobefreed = NULL;
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*mem;
	size_t			i;

	mem = s;
	i = 0;
	while (i < n)
	{
		mem[i] = c;
		i++;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*mem;
	size_t			i;

	mem = s;
	i = 0;
	while (i < n)
	{
		mem[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;

	if ((nmemb == SIZE_MAX || size == SIZE_MAX) && (nmemb > 1 || size > 1))
		return (NULL);
	ptr = (char *)malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

int	ft_isalnum(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (1);
	else
		return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[j] == '\0')
		return ((char *)big);
	while ((big[i]) && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && ((i + j) < len) && big[i])
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*p;

	i = 0;
	while (c > 127)
		c -= 128;
	p = (char *)s;
	while (i <= ft_strlen(s))
	{
		if (p[i] == c)
			return (&p[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i != -1)
	{
		if (s[i] == (unsigned char) c)
			return ((char *)&s[i]);
		else
			i--;
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t	ls;
	size_t	i;
	char	*dup;

	i = 0;
	ls = ft_strlen(s) + 1;
	dup = (char *)malloc(sizeof(char) * ls);
	if (dup == NULL)
		return (NULL);
	while (i < ls)
	{
		dup[i] = (char)s[i];
		i++;
	}
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	ssize_t	j;
	char	*str;

	i = start;
	j = -1;
	if (i > ft_strlen(s) || len == 0)
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len > (ft_strlen(s) - i))
		str = malloc((sizeof(char) * (ft_strlen(s) - i)) + 1);
	else
		str = malloc((sizeof(char) * len) + 1);
	if (!str)
		return (NULL);
	while (++j < (ssize_t)len && s[i + j])
		str[j] = s[i + j];
	str[j] = '\0';
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < (size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int				i;
	int				j;
	unsigned int	k;
	char			*str;

	i = 0;
	j = 0;
	k = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) *(k + 1));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i + j] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

ssize_t	ft_count_strs(const char *s, char c)
{
	ssize_t	n;
	ssize_t	i;

	n = 0;
	i = 0;
	while (s && s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			n++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (n);
}

void	ft_true_split(char const *s, char **strs, char c, ssize_t len)
{
	ssize_t	i;
	ssize_t	j;
	ssize_t	a;

	a = 0;
	i = 0;
	j = 0;
	while (s[i] && a < len)
	{
		while (s[i + j] && s[i + j] == c)
			i++;
		while ((s[i + j] && s[i + j] != c))
			j++;
		if (s[i + j] == c || s[i + j] == 0)
			strs[a] = ft_substr(s, i, j);
		a++;
		i = i + j;
		j = 0;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	ssize_t	len;

	strs = NULL;
	if (s)
	{
		len = ft_count_strs(s, c);
		strs = (char **)malloc(sizeof(char *) * (len + 1));
		if (!strs)
			return (NULL);
		strs[len] = NULL;
		ft_true_split(s, strs, c, len);
	}
	return (strs);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (!str1 && str2 && str2[0])
			return (-str2[0]);
		else if (str1 && !str2 && str1[0])
			return (str1[0]);
		else if ((!str1 && !str2) || (str1[i] == '\0' && str2[i] == '\0'))
			return (0);
		else if (str1[i] - str2[i] != 0)
			return (str1[i] - str2[i]);
		else
			i++;
	}
	return (0);
}

void	ft_show_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs && strs[i])
	{
		printf("%s%%", strs[i]);
		i++;
	}
}

////////////////////////////////////////////////////////

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	ssize_t	i;
	ssize_t	j;

	i = 0;
	j = ft_strlen(s1);
	if (s1)
	{
		while (s1 && s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1 && s1[i] && ft_strrchr(set, s1[j]))
			j--;
		str = ft_substr(s1, i, (j - i + 1));
		if (str)
			return (str);
	}
	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

int	ft_strslen(char **strs)
{
	int	i;

	i = 0;
	while (strs && strs[i])
		i++;
	return (i);
}

int	ft_isspace(int c)
{
	if ((c > 8 && c < 17) || c == 32)
		return (1);
	else
		return (0);
}

int	ft_iscmd(char *str)
{
	if (str && str[0] && str[0] == '0')
		return (1);
	return (0);
}

int	ft_isoutfile(char *str)
{
	if (str && str[0])
	{
		if(str[0] == '>')
			return (1);
		if(str[0] == 'A')
			return (2);
	}
	return (0);
}

int	ft_isheredoc(char *str)
{
	if (str && str[0])
	{
		if(str[0] == 'A')
			return (1);
	}
	return (0);
}

int	ft_isinfile(char *str)
{
	if (str && str[0])
	{
		if(str[0] == '<')
			return (1);
		if(str[0] == 'H')
			return (2);
	}
	return (0);
}

/*
void	ft_destroy_layers(t_layers **strs)
{
	(*strs)->src = NULL;//tofree
	(*strs)->src_trans = NULL;//tofree
	*strs = NULL;
}

void	ft_layers_visualizer(t_layers *strs)
{
	printf(">src         :%s\n>", strs->src);
	printf("src_trans   :%s\n>", strs->src_trans);
	printf("src_len     :%d\n", strs->src_len);
}

char	*ft_get_var_env_val(t_layers *strs, int i)
{
	char	*val;
	char	*tmp;
	int		j;

	j = 0;
	i++;
	while (strs && strs->src && strs->src[i + j] \
		&& ft_isalnum(strs->src[i + j]))
		j++;
	tmp = (char *)malloc(sizeof(char) * (j + 1));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, strs->src + i, j + 1);
	printf("tmp %ld:%s\n", ft_strlen(tmp), tmp);
	val = getenv(tmp);
	if (!val)
		return ("");
	printf("val %ld:%s\n", ft_strlen(val), val);
	return (val);
}

char	*ft_get_mid_part(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (str && str[i] == '$')
	{
		i++;
		while (str[i] && ft_isalnum(str[i]))
			i++;
		tmp = (char *)malloc(sizeof(char) * (i + 1));
		if (!tmp)
			return (NULL);
		ft_strlcpy(tmp, str, i + 1);
	}
	return (tmp);
}

void	ft_get_parts_src(char *full, t_sections *parts, t_size *index)
{
	index->second = *parts->cut;
	parts->mid = ft_get_mid_part(full + index->second);
	index->third = index->second + ft_strlen(parts->mid);
	parts->last = ft_strdup(full + index->third);
	full[index->second] = '\0';
	parts->first = ft_strdup(full);
}

void	ft_get_parts_trans(char *trans, t_sections *parts, t_size *index)
{
	parts->last = ft_strdup(trans + index->third);
	trans[index->second] = '\0';
	parts->first = ft_strdup(trans);
}

void	ft_join_parts_to_layers(t_layers *strs, t_sections **parts)
{
	char	*tmp;

	tmp = ft_strjoin(parts[SRC]->new_mid, parts[SRC]->last);
	strs->src = ft_strjoin(parts[SRC]->first, tmp);
	tmp = ft_strjoin(parts[TRANS]->new_mid, parts[TRANS]->last);
	strs->src_trans = ft_strjoin(parts[TRANS]->first, tmp);
}

t_sections	*ft_init_t_sections(void)
{
	t_sections *part;

	part = (t_sections *)malloc(sizeof(t_sections));
	part->first = NULL;
	part->mid = NULL;
	part->new_mid = NULL;
	part->last = NULL;
	part->cut = NULL;
	return (part);
}

void	ft_var_env_to_layers(t_layers *strs, char *val, int *i)
{
	t_sections	**parts;
	t_size		index;
	char		*copy;

	copy = ft_strdup(val);
	ft_layers_visualizer(strs);
	parts = (t_sections **)malloc(sizeof(t_sections *) * 2);
	parts[SRC] = ft_init_t_sections();
	parts[TRANS] = ft_init_t_sections();
	index.second = 0;
	index.third = 0;
	parts[SRC]->new_mid = ft_strdup(val);
	copy = ft_memset(copy, '0', ft_strlen(copy));
	parts[TRANS]->new_mid = ft_strdup(copy);
	parts[SRC]->cut = i;
	parts[TRANS]->cut = i;
	ft_get_parts_src(strs->src, parts[SRC], &index);
	parts[TRANS]->mid = ft_memset(parts[SRC]->mid, '0', \
		ft_strlen(parts[SRC]->mid));
	ft_get_parts_trans(strs->src_trans, parts[TRANS], &index);
	ft_join_parts_to_layers(strs, parts);
}

void	ft_renew_with_vars_env(t_layers *strs)
{
	int		i;
	char	*val;

	i = 0;
	val = NULL;
	while (strs->src_trans && strs->src_trans[i])
	{
		if (strs->src_trans[i] == '$')
		{
			val = ft_get_var_env_val(strs, i);
			printf("test val :%s\n", val);
			ft_var_env_to_layers(strs, val, &i);
			i = 0;
		}
		else
			i++;
	}
}

void	ft_quotes_focus(t_layers *strs, int i, int *sq, int *dq)
{
	if (strs->src[i] == '\"' && (*sq % 2) == 0)
	{
		strs->src_trans[i] = '\"';
		*dq += 1;
	}
	else if (strs->src[i] == '\'' && (*dq % 2) == 0)
	{
		strs->src_trans[i] = '\'';
		*sq += 1;
	}
}

void	ft_angled_brackets_focus(t_layers *strs, int i, int *sq, int *dq)
{
	if ((strs->src[i] == '<' || strs->src[i] == '>') \
		&& (*sq % 2) == 0 && (*dq % 2) == 0)
		strs->src_trans[i] = strs->src[i];
}

void	ft_pipes_focus(t_layers *strs, int i, int *sq, int *dq)
{
	if (strs->src[i] == '|' && (*sq % 2) == 0 && (*dq % 2) == 0)
		strs->src_trans[i] = strs->src[i];
}

void	ft_var_env_focus(t_layers *strs, int i, int *sq)
{
	if ((i == 0 && strs->src[i] == '$' && strs->src_len > 1) \
		|| (i != (strs->src_len - 1) && strs->src[i] == '$' && (*sq % 2) == 0))
	{
		if (i > 0 && strs->src_trans[i - 1] \
			&& strs->src_trans[i - 1] == '$' && strs->src[i] == '$')
			strs->src_trans[i - 1] = '0';
		strs->src_trans[i] = strs->src[i];
	}
}

void	ft_spaces_focus(t_layers *strs, int i, int *sq, int *dq)
{
	if (ft_isspace(strs->src[i]) && (*sq % 2) == 0 && (*dq % 2) == 0)
		strs->src_trans[i] = ' ';
}

int	ft_occurences_counter(char *big, char *little)
{
	int		i;
	int		total;
	int		big_len;
	int		little_len;
	char	*tmp;

	tmp = NULL;
	total = 0;
	big_len = ft_strlen(big);
	little_len = ft_strlen(little);
	i = -1;
	if (big && little && big_len >= little_len)
	{
		while (big[++i])
		{
			tmp = ft_strnstr(big + i, little, little_len);
			if (tmp)
			{
				i += little_len - 1;
				tmp = NULL;
				total++;
			}
		}
	}
	return (total);
}

void	ft_remove_symbol_var_env(t_layers *strs, int i)
{
	while (strs->src && strs->src[i] && ft_isspace(strs->src[i]))
		i++;
	while (strs->src && strs->src[i] && !ft_strchr("<>|$", strs->src_trans[i]) \
		&& !ft_isspace(strs->src[i]))
	{
		if (strs->src_trans[i] == '\"')
		{
			i++;
			while (strs->src_trans[i] && strs->src_trans[i] != '\"')
				i++;
		}
		else if (strs->src_trans[i] == '\'')
		{
			i++;
			while (strs->src_trans[i] && strs->src_trans[i] != '\'')
				i++;
		}
		i++;
	}
	if (strs->src && strs->src[i] && strs->src_trans[i] == '$')
		strs->src_trans[i] = '0';
}

void	ft_disable_var_env(t_layers *strs)
{
	char	*tmp;
	int		heredocs;
	int		i;

	i = 0;
	tmp = NULL;
	heredocs = ft_occurences_counter(strs->src_trans, "<<");
	while (strs->src_trans && strs->src_trans[i] && heredocs)
	{
		tmp = ft_strnstr(strs->src_trans + i, "<<", 2);
		if (tmp)
		{
			i += 1;
			tmp = NULL;
			heredocs -= 1;
			if (ft_strnstr(strs->src_trans + i + 1, \
				"$", strs->src_len  - (i + 1)))
				ft_remove_symbol_var_env(strs, i + 1);
		}
		i++;
	}
}

char	**ft_get_wrong_angl_brackets(void)
{
	char	**needle;

	needle = (char **)malloc(sizeof(char *) * 5);
	if (!needle)
		return (NULL);
	needle[0] = ft_strdup("<<<");
	needle[1] = ft_strdup(">>>");
	needle[2] = ft_strdup("><");
	needle[3] = ft_strdup("<>");
	needle[4] = NULL;
	return (needle);
}

int	ft_check_format_angl_brackets(t_layers *strs)
{
	char	**needle;
	char	*tmp;
	int		i;

	i = -1;
	tmp = strs->src_trans;
	needle = ft_get_wrong_angl_brackets();
	while (needle[++i])
	{
		if (ft_strnstr(tmp, needle[i], strs->src_len))
			return (0);
	}
	i = strs->src_len;
	if (i >= 2 && tmp[i - 2] && ft_strchr("<>", tmp[i - 2]))
		if (ft_strchr("\t\n \"\'#&*./|~<>", strs->src[i - 1]) \
			|| (!ft_isprint(strs->src[i - 1])))
			return (0);
	if (i >= 1 && tmp[i - 1] && ft_strchr("<>", tmp[i - 1]))
		return (0);
	return (1);
}

int	ft_check_format_quotes(t_layers *strs)
{
	int		i;
	int		sq;
	int		dq;

	i = 0;
	sq = 0;
	dq = 0;
	while (strs->src_trans && strs->src_trans[i])
	{
		if (strs->src_trans[i] == '\"' && (sq % 2) == 0)
			dq += 1;
		else if (strs->src_trans[i] == '\'' && (dq % 2) == 0)
			sq += 1;
		i++;
	}
	if ((sq % 2) != 0 || (dq % 2) != 0)
		return (0);
	return (1);
}


int	ft_check_format_pipes(t_layers *strs)
{
	char	*tmp;
	int		i;

	i = -1;
	tmp = strs->src_trans;
	if (tmp[0] == '|' || tmp[strs->src_len - 1] == '|')
			return (0);
	while (tmp && tmp[++i])
		if (i > 0 && tmp[i - 1] && tmp[i] == '|' && tmp[i - 1] == '|')
			return (0);
	return (1);
}

int	ft_check_quotes(t_layers *strs)
{
	int		i;
	int		sq;
	int		dq;

	i = 0;
	sq = 0;
	dq = 0;
	while (strs->src && strs->src[i])
		ft_quotes_focus(strs, i++, &sq, &dq);
	if (!ft_check_format_quotes(strs))
	{
		ft_destroy_layers(&strs);
		return (0);
	}
	return (1);
}

int	ft_check_angl_brackets(t_layers *strs)
{
	int		i;
	int		sq;
	int		dq;

	i = 0;
	sq = 0;
	dq = 0;
	while (strs->src && strs->src[i])
	{
		ft_quotes_focus(strs, i, &sq, &dq);
		ft_angled_brackets_focus(strs, i, &sq, &dq);
		i++;
	}
	if (!ft_check_format_angl_brackets(strs))
	{
		ft_destroy_layers(&strs);
		return (0);
	}
	return (1);
}

int	ft_check_pipes(t_layers *strs)
{
	int		i;
	int		sq;
	int		dq;

	i = 0;
	sq = 0;
	dq = 0;
	while (strs->src && strs->src[i])
	{
		ft_quotes_focus(strs, i, &sq, &dq);
		ft_angled_brackets_focus(strs, i, &sq, &dq);
		ft_pipes_focus(strs, i, &sq, &dq);
		i++;
	}
	if (!ft_check_format_pipes(strs))
	{
		ft_destroy_layers(&strs);
		return (0);
	}
	return (1);
}

int	ft_check_var_env(t_layers *strs)
{
	int		i;
	int		sq;
	int		dq;

	i = 0;
	sq = 0;
	dq = 0;
	while (strs->src && strs->src[i])
	{
		ft_quotes_focus(strs, i, &sq, &dq);
		ft_angled_brackets_focus(strs, i, &sq, &dq);
		ft_pipes_focus(strs, i, &sq, &dq);
		ft_var_env_focus(strs, i, &sq);
		i++;
	}
	if (ft_strnstr(strs->src_trans, "<<", strs->src_len))
		ft_disable_var_env(strs);
	return (1);
}

int	ft_check_spaces(t_layers *strs)
{
	int		i;
	int		sq;
	int		dq;

	i = 0;
	sq = 0;
	dq = 0;
	while (strs->src && strs->src[i])
	{
		ft_quotes_focus(strs, i, &sq, &dq);
		ft_spaces_focus(strs, i, &sq, &dq);
		i++;
	}
	return (1);
}

void	ft_replace_spaces(t_layers *strs)
{
	int	i;

	i = 0;
	while (strs && strs->src_trans && strs->src_trans[i])
	{
		if (ft_strchr("<>", strs->src_trans[i]) && strs->src_trans[i + 1] == ' ')
		{
			while (strs->src_trans[i + 1] && strs->src_trans[i + 1] == ' ')
			{
				strs->src_trans[i + 1] = '0';
				i++;
			}
			i -= 1;
		}
		i++;
	}
}

void	ft_rename_angl_brackets(t_layers *strs)
{
	int	i;

	i = 0;
	while (strs && strs->src_trans && strs->src_trans[i] && strs->src_trans[i + 1])
	{
		if (strs->src_trans[i] == '<' && strs->src_trans[i + 1] == '<')
		{
			strs->src_trans[i] = 'H';
			strs->src_trans[i + 1] = '0';
			i++;
		}
		else if (strs->src_trans[i] == '>' && strs->src_trans[i + 1] == '>')
		{
			strs->src_trans[i] = 'A';
			strs->src_trans[i + 1] = '0';
			i++;
		}
		i++;
	}
}

void	ft_translate_all(t_layers *strs)
{
	if (ft_check_quotes(strs) && ft_check_angl_brackets(strs) \
		&& ft_check_pipes(strs))
	{
		ft_check_var_env(strs);
		if (ft_strchr(strs->src_trans, '$'))
			ft_renew_with_vars_env(strs);
		ft_check_spaces(strs);/////////////////
		ft_replace_spaces(strs);
		ft_rename_angl_brackets(strs);
	}
}
*/
////////////////////////////////////////////////////////////////////////

void	ft_show_duo_strs(char **strs1, char **strs2)
{
	int	i;

	i = 0;
	printf(">src   :");
	while (strs1 && strs1[i])
	{
		printf("%s", strs1[i]);
		printf("%%");
		i++;
	}
	i = 0;
	printf("\n");
	printf(">trans :");
	while (strs2 && strs2[i])
	{
		printf("%s", strs2[i]);
		printf("%%");
		i++;
	}
	printf("\n");
}

char	**ft_strsdup(char **src)
{
	char	**dest;
	int		i;

	i = 0;
	while (src && src[i])
		i++;
	dest = (char **)malloc(sizeof(char *) * (i + 1));
	dest[i] = NULL;
	while (--i >= 0)
		dest[i] = ft_strdup(src[i]);
	return (dest);
}

/*
char	**ft_parallel_split(char **model, char *to_split)
{
	int		i;
	int		j;
	char	**dest;

	i = 0;
	j = 0;
	dest = ft_strsdup(model);
	while (model && model[i])
	{
		ft_strlcpy(dest[i], to_split + j, ft_strlen(dest[i]) + 1);
		j += ft_strlen(dest[i]) + 1;
		i++;
	}
	ft_show_duo_strs(dest, model);
	return (dest);
}

char	*ft_index_trim(char *str, int begin, int end)
{
	char	*ret;
	int		len;

	if (!str || (begin + end) > (int)ft_strlen(str))
		return (NULL);
	ret = NULL;
	len = ft_strlen(str);
	str[len - end] = '\0';
	ret = ft_strdup(str + begin);
	return (ret);
}

char	*ft_strtrim_index_to_blocks(char *src, char *trans, char *set)
{
	char	*ret;
	int		begin;
	int		end;
	int		i;

	begin = 0;
	end = 0;
	i = -1;
	ret = NULL;
	if (src && src[0] && set)
	{
		while (ft_strchr(set, src[++i]))
			begin++;
		i = ft_strlen(src);
		while (i >= 0 && ft_strchr(set, src[--i]))
			end++;
		ret = ft_index_trim(trans, begin, end);
	}
	return (ret);
}

void	ft_strstrim_to_blocks(t_blocks **block, char *set)
{
	int	i;

	i = 0;
	if (block && *block && set)
	{
		while ((*block)->src_trans && (*block)->src && (*block)->src_trans[i] \
			&& (*block)->src[i] && (*block)->src[0][0])
		{
			(*block)->src_trans[i] = ft_strtrim_index_to_blocks
				((*block)->src[i], (*block)->src_trans[i], set);
			(*block)->src[i] = ft_strtrim((*block)->src[i], set);
			i++;
		}
	}
}

t_blocks	*ft_layers_pipe_split(t_layers *strs)
{
	t_blocks	*block;

	block = (t_blocks *)malloc(sizeof(t_blocks) * 1);
	if (strs->src_trans && strs->src_trans[0])
	{
		block->src_trans = ft_split(strs->src_trans, '|');
		block->src = ft_parallel_split(block->src_trans, strs->src);
	}
	else if (strs->src_trans && strs->src_trans[0] == '\0')
	{
		block->src_trans = (char **)malloc(sizeof(char *) * 2);
		block->src = (char **)malloc(sizeof(char *) * 2);
		if (!block->src || !block->src_trans)
			return (NULL);
		block->src[0] = strs->src;
		block->src_trans[0] = "0";
		block->src[1] = NULL;
		block->src_trans[1] = NULL;
	}
	ft_strstrim_to_blocks(&block, "\a\b\t\n\v\f\r ");
	ft_show_duo_strs(block->src, block->src_trans);
	return (block);
}

void	ft_pages_src_split(t_pages **page)
{
	int		i;
	int		j;
	int		k;
	char	*copy;
	t_pages *tmp;

	i = 0;
	j = 0;
	k = 0;
	tmp = *page;
	copy = tmp->src;
	tmp->tmp_trans = ft_split(tmp->trans, ' ');
	tmp->tmp = ft_strsdup(tmp->tmp_trans);
	while (tmp->tmp[i])
	{
		j = ft_strlen(tmp->tmp_trans[i]);
		ft_strlcpy(tmp->tmp[i], copy, j + 1);
		copy += j;
		while (copy && copy[k] && ft_isspace(copy[k]))
			k++;
		copy += k;
		k = 0;
		i++;
	}
}
*/
char **ft_split_at_index(char *str, int i)
{
	char	**final;
	char	*first;
	char	*last;

	final = NULL;
	if (str)
	{
		last = ft_strdup(str + i);
		str[i] = '\0';
		first = ft_strdup(str);
		final = (char **)malloc(sizeof(char *) * 3);
		if (!final)
			return (NULL);
		final[0] = first;
		final[1] = last;
		final[2] = NULL;
	}
	return (final);
}
/*
void	ft_include_spaces(t_pages **page)
{
	t_pages		*copy;
	t_blocks	parts;
	char		*buffer;
	int			i;

	i = 0;
	copy = *page;
	while (copy)
	{
		while (copy->trans && copy->trans[i])
		{
			if (i != 0 && ft_strchr("<>AH", copy->trans[i]) && !ft_isspace(copy->trans[i - 1]))
			{
				parts.src = ft_split_at_index(copy->src, i);
				parts.src_trans = ft_split_at_index(copy->trans, i);
				buffer = ft_strjoin(parts.src[0], " ");
				copy->src = ft_strjoin(buffer, parts.src[1]);
				buffer = ft_strjoin(parts.src_trans[0], " ");
				copy->trans = ft_strjoin(buffer, parts.src_trans[1]);
				i = -1;
			}
			i++;
		}
		copy = copy->next;
	}
}

void	ft_init_page(t_pages **page)
{
	(*page)->src = NULL;
	(*page)->trans = NULL;
	(*page)->cmds = NULL;
	(*page)->redirections = NULL;
	//(*page)->outfiles = NULL;
	(*page)->tmp = NULL;
	(*page)->tmp_trans = NULL;
	(*page)->next = NULL;
}

void	ft_pages_clean_quotes(t_pages **pages)
{
	t_pages	*copy;
	int		i;

	i = 0;
	copy = *pages;
	while (copy && copy->src && copy->trans)
	{
		while (copy->trans[i])
		{
			if (ft_strchr("\'\"", copy->trans[i]))
			{
				while (copy->trans[i + 1])
				{
					copy->trans[i] = copy->trans[i + 1];
					copy->src[i] = copy->src[i + 1];
					i++;
				}
				copy->trans[i] = '\0';
				copy->src[i] = '\0';
				i = -1;
			}
			i++;
		}
		copy = copy->next;
	}
}

void	ft_show_book(t_pages *book)
{
	t_pages	*tmp;
	int		i;

	tmp = book;
	i = 0;
	while (tmp)
	{
		printf("\nsrc  %d____:%s\n", i, tmp->src);
		printf("\ntrans%d____:%s\n", i, tmp->trans);
		printf("\ncmds_____ :");
		ft_show_strs(tmp->cmds);
		printf("\nredirect_ :");
		ft_show_strs(tmp->redirections);
		//printf("\noutfiles_ :");
		//ft_show_strs(tmp->outfiles);
		printf("\ntmp______ :");
		ft_show_strs(tmp->tmp);
		printf("\ntmp_trans :");
		ft_show_strs(tmp->tmp_trans);
		printf("\n________________________________________________________\n");
		tmp = tmp->next;
		i++;
	}
}

void	ft_pages_clean_redirection(t_pages **page)
{
	t_pages	*tmp;
	int	i;

	i = 0;
	tmp = *page;
	while (tmp)
	{
		while (tmp->tmp_trans && tmp->tmp_trans[i])
		{
			tmp->tmp_trans[i][1] = '\0';
			if (tmp->tmp_trans[i][0] == 'A' || tmp->tmp_trans[i][0] == 'H')
			{
				tmp->tmp[i][0] = ' ';
				tmp->tmp[i][1] = ' ';
			}
			else if (tmp->tmp_trans[i][0] == '<' || tmp->tmp_trans[i][0] == '>')
				tmp->tmp[i][0] = ' ';
			tmp->tmp[i] = ft_strtrim(tmp->tmp[i], "\a\b\t\n\v\f\r ");
			if (tmp->tmp_trans[i][0] == '<' || tmp->tmp_trans[i][0] == '>' \
			|| tmp->tmp_trans[i][0] == 'A' || tmp->tmp_trans[i][0] == 'H')
				tmp->tmp[i] = ft_strjoin(tmp->tmp_trans[i], tmp->tmp[i]);
			i++;
		}
		i = 0;
		tmp = tmp->next;
	}
}

t_quantity	ft_quantity_counter(char **trans)
{
	t_quantity	count;
	int			i;

	i = 0;
	count.cmds = 0;
	count.redirections = 0;
	count.heredocs = 0;
	while (trans && trans[i])
	{
		if (ft_iscmd(trans[i]))
			count.cmds++;
		else if (ft_isinfile(trans[i]) || ft_isoutfile(trans[i]))
			count.redirections++;
		if (ft_isheredoc(trans[i]))
			count.heredocs++;
		//else if (ft_isoutfile(trans[i]))
		//	count.outfile++;
		i++;
	}
	return (count);
}

void	ft_pages_alloc(t_pages **page, t_quantity count)
{
	(*page)->cmds = (char **)malloc(sizeof(char *) * (count.cmds + 1));
	(*page)->redirections = (char **)malloc(sizeof(char *) * (count.redirections + 1));
	//(*page)->heredocs = (char **)malloc(sizeof(char *) * (count.outfile + 1));
	/////a securiser
	(*page)->cmds[count.cmds] = NULL;
	(*page)->redirections[count.redirections] = NULL;
	//(*page)->outfiles[count.outfile] = NULL;
}

t_quantity	ft_init_quantity(int n)
{
	t_quantity q;

	q.cmds = n;
	q.redirections = n;
	q.heredocs = n + 1;
	return (q);
}

void	ft_pages_dispatch_units(t_pages **page)
{
	t_pages *copy;
	t_quantity count;
	t_quantity index;

	int	i;
	i = 0;
	copy = *page;
	index = ft_init_quantity(-1);
	while (copy)
	{
		count = ft_quantity_counter(copy->tmp_trans);
		ft_pages_alloc(&copy, count);
		while (copy->tmp_trans[i])
		{
			if (ft_iscmd(copy->tmp_trans[i]))
				copy->cmds[++index.cmds] = ft_strdup(copy->tmp[i]);
			else if (ft_isinfile(copy->tmp_trans[i]) || ft_isoutfile(copy->tmp_trans[i]))
				copy->redirections[++index.redirections] = ft_strdup(copy->tmp[i]);
			if (ft_isheredoc(copy->tmp_trans[i]))
				index.heredocs++;
			//else if (ft_isoutfile(copy->tmp_trans[i]))
			//	copy->outfiles[++index.outfile] = ft_strdup(copy->tmp[i]);
			i++;
		}
		i = 0;
		copy = copy->next;
	}
}

void	ft_pages_dispatch_units(t_pages **page)
{
	t_pages *copy;
	t_quantity count;
	t_quantity index;

	int	i;
	i = 0;
	copy = *page;
	index = ft_init_quantity(-1);
	while (copy)
	{
		count = ft_quantity_counter(copy->tmp_trans);
		ft_pages_alloc(&copy, count);
		while (copy->tmp_trans[i])
		{
			if (ft_iscmd(copy->tmp_trans[i]))
				copy->cmds[++index.cmd] = ft_strdup(copy->tmp[i]);
			else if (ft_isinfile(copy->tmp_trans[i]))
				copy->infiles[++index.infile] = ft_strdup(copy->tmp[i]);
			else if (ft_isoutfile(copy->tmp_trans[i]))
				copy->outfiles[++index.outfile] = ft_strdup(copy->tmp[i]);
			i++;
		}
		i = 0;
		copy = copy->next;
	}
}

t_pages	*ft_fill_pages(char *src, char *src_trans)
{
	t_pages	*page;

	page = (t_pages *)malloc(sizeof(t_pages));
	if (!page)
		return (NULL);
	ft_init_page(&page);
	page->src = src;
	page->trans = src_trans;
	ft_include_spaces(&page);
	ft_pages_clean_quotes(&page);
	ft_pages_src_split(&page);
	//ft_show_book(page);
	ft_pages_clean_redirection(&page);
	ft_pages_dispatch_units(&page);
	ft_show_book(page);

	return (page);
}

t_pages	*ft_fill_book(t_blocks *blocks)
{
	t_pages	*book;
	t_pages	*first;
	int		i;

	i = 0;
	book = NULL;
	while (blocks && blocks->src && blocks->src[i])
	{
		if (!book)
		{
			book = ft_fill_pages(blocks->src[i], blocks->src_trans[i]);
			first = book;
		}
		else
		{
			book->next = ft_fill_pages(blocks->src[i], blocks->src_trans[i]);
			book = book->next;
		}
		i++;
	}
	return (first);
}
*/


void	ft_quotes_focus(char **src, char **trans, int i, int *quotes)//done
{
	if (src[0][i] == '\'' && (quotes[DOUBLE] % 2) == 0)
	{
		trans[0][i] = '\'';
		quotes[SIMPLE] += 1;
	}
	else if (src[0][i] == '\"' && (quotes[SIMPLE] % 2) == 0)
	{
		trans[0][i] = '\"';
		quotes[DOUBLE] += 1;
	}
}

int	ft_check_format_quotes(int *quotes)//done
{
	if ((quotes[SIMPLE] % 2) != 0 || (quotes[DOUBLE] % 2) != 0)
		return (0);
	return (1);
}

void	ft_angled_brackets_focus(char **src, char **trans, int i, int *quotes)//done
{
	if (ft_strchr("<>", src[0][i]) && ft_check_format_quotes(quotes))
		trans[0][i] = src[0][i];
}

char	**ft_get_wrong_angl_brackets(void)//done
{
	char	**needle;

	needle = (char **)malloc(sizeof(char *) * 5);
	if (!needle)
		return (NULL);
	needle[0] = ft_strdup("<<<");
	needle[1] = ft_strdup(">>>");
	needle[2] = ft_strdup("><");
	needle[3] = ft_strdup("<>");
	needle[4] = NULL;
	return (needle);
}

int	ft_check_format_angl_brackets(char *src, char *trans)//done
{
	char	**needle;
	int		test;
	int		i;

	i = -1;
	test = 1;
	needle = ft_get_wrong_angl_brackets();
	while (needle[++i] && test)
	{
		if (ft_strnstr(trans, needle[i], ft_strlen(trans)))
			test = 0;
	}
	i = ft_strlen(trans);
	if (i >= 2 && trans[i - 2] && ft_strchr("<>", trans[i - 2]) && test)
		if (ft_strchr("\t\n \"\'#&*./|~<>", src[i - 1]) \
			|| (!ft_isprint(src[i - 1])))
				test = 0;
	if (i >= 1 && trans[i - 1] && ft_strchr("<>", trans[i - 1]) && test)
		test = 0;
	ft_full_free((void **)needle);
	if (!test)
		return (0);
	return (1);
}

void	ft_pipes_focus(char **src, char **trans, int i, int *quotes)//done
{
	if (src[0][i] == '|' && !(quotes[SIMPLE] % 2) && !(quotes[DOUBLE] % 2))
		trans[0][i] = src[0][i];
}

int	ft_check_format_pipes(char *trans)//done
{
	int	len;
	int	i;

	i = -1;
	len = ft_strlen(trans);
	if (trans && len > 0 && (trans[0] == '|' || trans[len - 1] == '|'))
			return (0);
	while (trans && trans[++i])
		if (i > 0 && trans[i - 1] && trans[i] == '|' && trans[i - 1] == '|')
			return (0);
	return (1);
}

void	ft_replace_spaces(char **trans)//done
{
	int	i;

	i = 0;
	while (trans && trans[0] && trans[0][i])
	{
		if (ft_strchr("<>", trans[0][i]) && trans[0][i + 1] == ' ')
		{
			while (trans[0][i + 1] && trans[0][i + 1] == ' ')
			{
				trans[0][i + 1] = '0';
				i++;
			}
			i -= 1;
		}
		i++;
	}
}

void	ft_rename_angl_brackets(char **trans)//done
{
	int	i;

	i = 0;
	while (trans && trans[0] && trans[0][i] && trans[0][i + 1])
	{
		if (trans[0][i] == '<' && trans[0][i + 1] == '<')
		{
			trans[0][i] = 'H';
			trans[0][i + 1] = '0';
			i++;
		}
		else if (trans[0][i] == '>' && trans[0][i + 1] == '>')
		{
			trans[0][i] = 'A';
			trans[0][i + 1] = '0';
			i++;
		}
		i++;
	}
}

void	ft_spaces_focus(char **src, char **trans, int i, int *quotes)//done
{
	if (ft_isspace(src[0][i]) && !(quotes[SIMPLE] % 2) && !(quotes[DOUBLE] % 2))
		trans[0][i] = ' ';
}

void	ft_var_env_focus(char **src, char **trans, int i, int s_quotes)//done
{
	int	len;

	len = ft_strlen(src[0]);
	if ((i == 0 && src[0][i] == '$' && len > 1) \
		|| (i != (len - 1) && src[0][i] == '$' && (s_quotes % 2) == 0))
	{
		if (i > 0 && trans[0][i - 1] && trans[0][i - 1] == '$' \
			&& src[0][i] == '$')
			trans[0][i - 1] = '0';
		trans[0][i] = src[0][i];
	}
}

void	ft_only_strs_free(char **tobefreed)//done
{
	int	i;

	i = -1;
	while (tobefreed && tobefreed[++i])
	{
		free(tobefreed[i]);
		tobefreed[i] = NULL;
	}
}

void	ft_add_spaces(char **src, char **trans)//done
{
	int	i;

	i = 0;
	while (trans && trans[0] && trans[0][i])
	{
		if (i > 0 && ft_strchr("<>AH", trans[0][i]) \
			&& !ft_isspace(trans[0][i - 1]))
		{
			src[1] = ft_substr(src[0], 0, i);
			src[2] = ft_strdup(src[0] + i);
			src[3] = ft_strjoin(src[1], " ");
			src[4] = src[0];
			src[0] = ft_strjoin(src[3], src[2]);
			trans[1] = ft_substr(trans[0], 0, i);
			trans[2] = ft_strdup(trans[0] + i);
			trans[3] = ft_strjoin(trans[1], " ");
			trans[4] = trans[0];
			trans[0] = ft_strjoin(trans[3], trans[2]);
			ft_only_strs_free(src + 1);
			ft_only_strs_free(trans + 1);
			i = 0;
		}
		i++;
	}
}

int	ft_occurences_counter(char *big, char *little)//done
{
	int		i;
	int		total;
	int		big_len;
	int		little_len;
	char	*tmp;

	tmp = NULL;
	total = 0;
	big_len = ft_strlen(big);
	little_len = ft_strlen(little);
	i = 0;
	while (big && big[i] && little && big_len >= little_len)
	{
		tmp = ft_strnstr(big + i, little, little_len);
		if (tmp)
		{
			i += little_len - 1;
			tmp = NULL;
			total++;
		}
		i++;
	}
	return (total);
}

void	ft_remove_symbol_var_env(char **src, char **trans, int i)//done
{
	while (src && src[0] && src[0][i] && ft_isspace(src[0][i]))
		i++;
	while (src && src[0] && src[0][i] && trans && trans[0] && trans[0][i] \
		&& !ft_strchr("<>|$", trans[0][i]) && !ft_isspace(src[0][i]))
	{
		if (trans[0][i] == '\"')
		{
			i++;
			while (trans[0][i] && trans[0][i] != '\"')
				i++;
		}
		else if (trans[0][i] == '\'')
		{
			i++;
			while (trans[0][i] && trans[0][i] != '\'')
				i++;
		}
		i++;
	}
	if (src && src[0] && trans && trans[0] && src[0][i] && trans[0][i] == '$')
		trans[0][i] = '0';
}

void	ft_disable_var_env(char **src, char **trans)//done
{
	char	*tmp;
	int		heredocs;
	int		i;
	int		len;

	i = 0;
	tmp = NULL;
	len = ft_strlen(trans[0]);
	heredocs = ft_occurences_counter(trans[0], "H0");
	while (trans && (len - i) >= 3 && heredocs)
	{
		tmp = ft_strnstr(trans[0] + i, "H0", 2);
		if (tmp)
		{
			tmp = NULL;
			heredocs -= 1;
			if (ft_strnstr(trans[0] + i + 2, "$", len  - (i + 2)))
				ft_remove_symbol_var_env(src, trans, i + 2);
			i++;
		}
		i++;
	}
}

char	*ft_get_var_env_val(char *src)//done
{
	char	*copy;
	char	*ret;
	int	i;

	i = 0;
	ret = NULL;
	copy = NULL;
	if (src)
	{
		while (src[i] && ft_isalnum(src[i]))
			i++;
		copy = ft_substr(src, 0, i);
		ret = getenv(copy);
		ft_true_free((void **)&copy);
		if (ret)
			return (ret);
	}
	return ("");
}

void	ft_replace_with_val(char **src, char **trans, char *var, int i)//done
{
	int j;
	int k;

	j = 1;
	k = -1;
	if (src && src[0] && trans && trans[0] && var)
	{
		while (src[0][i] && src[0][i + j] && ft_isalnum(src[0][i + j]))
			j++;
		src[1] = ft_substr(src[0], 0, i);
		src[2] = ft_strdup(src[0] + i + j);
		src[3] = ft_strjoin(src[1], var);
		src[4] = src[0];
		src[0] = ft_strjoin(src[3], src[2]);
		while (var[++k])
			var[k] = '0';
		trans[1] = ft_substr(trans[0], 0, i);
		trans[2] = ft_strdup(trans[0] + i + j);
		trans[3] = ft_strjoin(trans[1], var);
		trans[4] = trans[0];
		trans[0] = ft_strjoin(trans[3], trans[2]);
		ft_only_strs_free(src + 1);
		ft_only_strs_free(trans + 1);
	}
}

void	ft_include_var_env(char **src, char **trans)//done -> to improve
{
	int		i;
	char	*var;

	i = 0;
	var = NULL;
	while (src && src[0] && src[0][i] && trans && trans[0] && trans[0][i])
	{
		if (trans[0][i] == '$')
		{
			var = ft_get_var_env_val(src[0] + i + 1);
			ft_replace_with_val(src, trans, var, i);
			i = 0;
		}
		else
			i++;
	}
}

void	ft_translation(char **src, char **trans)//done?
{
	int	i;
	int	quotes[2];

	i = 0;
	quotes[SIMPLE] = 0;
	quotes[DOUBLE] = 0;
	while (src[0] && src[0][i])
	{
		ft_quotes_focus(src, trans, i, quotes);
		ft_angled_brackets_focus(src, trans, i, quotes);
		ft_pipes_focus(src, trans, i, quotes);
		ft_var_env_focus(src, trans, i, quotes[SIMPLE]);
		ft_spaces_focus(src, trans, i, quotes);
		i++;
	}
	ft_replace_spaces(trans);
	ft_rename_angl_brackets(trans);
	ft_add_spaces(src, trans);
	ft_disable_var_env(src, trans);
	ft_include_var_env(src, trans);
}

int	ft_check_syntax(char **src, char **trans)//done
{
	int	i;
	int	quotes[2];

	i = 0;
	quotes[SIMPLE] = 0;
	quotes[DOUBLE] = 0;
	while (src[0] && src[0][i])
	{
		ft_quotes_focus(src, trans, i, quotes);
		ft_angled_brackets_focus(src, trans, i, quotes);
		ft_pipes_focus(src, trans, i, quotes);
		i++;
	}
	if (!ft_check_format_quotes(quotes) \
		|| !ft_check_format_angl_brackets(src[0], trans[0]) \
			|| !ft_check_format_pipes(trans[0]))
		return (0);
	return (1);
}

char	*ft_twin_str(char *str1)//done
{
	char *str2;

	str2 = ft_strdup(str1);
	if (str2)
		str2 = ft_memset(str2, '0', ft_strlen(str1));
	else
		str2 = NULL;
	return (str2);
}

t_twins	*ft_init_origin(t_twins *origin, char *str1)//done
{
	origin = (t_twins *)malloc(sizeof(t_twins));
	if (!origin)
		return (NULL);
	origin->src = (char **)malloc(sizeof(char *) * 6);////c'était 2
	if (!origin->src)
	{
		ft_true_free((void **)&origin);
		return (NULL);
	}
	origin->trans = (char **)malloc(sizeof(char *) * 6);////
	if (!origin->trans)
	{
		ft_full_free((void **)origin->src);
		ft_true_free((void **)&origin);
		return (NULL);
	}
	origin->src[0] = str1;
	origin->src[1] = NULL;
	origin->src[5] = NULL;
	origin->trans[0] = ft_twin_str(str1);
	origin->trans[1] = NULL;
	origin->trans[5] = NULL;
	origin->len = ft_strlen(origin->src[0]);
	return (origin);
}

void	ft_free_twins(t_twins *lst)//done
{
	if (lst)
	{
		if (lst->src)
			ft_full_free((void **)lst->src);
		if (lst->trans)
			ft_full_free((void **)lst->trans);
		ft_true_free((void **)&lst);
	}
}

void	ft_free_parsed(t_parsed *lst)//done
{
	t_parsed *tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->cmds)
			ft_full_free((void **)tmp->cmds);
		if (tmp->redirections)
			ft_full_free((void **)tmp->redirections);
		lst = lst->next;
		ft_true_free((void **)&tmp);
		tmp = lst;
	}
}

void	ft_show_twins(t_twins *twins)
{
	printf("%d\n", twins->len);
	ft_show_duo_strs(twins->src, twins->trans);
}

t_parsed	*ft_minishell_parsing(char *str1)
{
	t_parsed	*lst;
	t_twins		*origin;
	//t_twins		twins;
	//t_book		*book;

	lst = NULL;//a suppr
	//lst = ft_init_new_elem(NULL, NULL, 0, 0);
	origin = NULL;
	origin = ft_init_origin(origin, str1);
	//book = NULL;
	ft_show_twins(origin);//first
	if (ft_check_syntax(origin->src, origin->trans))
	{
		ft_translation(origin->src, origin->trans);
		//var env
		//spaces
	//	twins = ft_split_on_pipes(origin);
	//	book = ft_split_whithin_pipes(twins);
	//	lst = ft_book_translation(book);
	}
	ft_show_twins(origin);//last
	ft_free_twins(origin);
	return (lst);
}

t_parsed	*ft_init_new_elem(char **cmds, char **redir, int hdocs, int	empty)//done
{
	t_parsed	*lst;

	lst = (t_parsed *)malloc(sizeof(t_parsed));
	if (!lst)
		return (NULL);
	lst->empty = empty;
	lst->cmds = cmds;
	lst->redirections = redir;
	lst->heredocs = hdocs;
	lst->next = NULL;
	return (lst);
}

//test multi cmdline
int	main(void)
{
	t_parsed	*lst;
	char		*name;
	char		*cmdline;
	char		*tmp;
	int			fd;
	int			i;
	int			n;

	tmp = NULL;
	name = ft_strdup("cmdline0");
	i = -1;
	while (++i < 5)
	{
		tmp = (char *)malloc(sizeof(char) * (200 + 1));
		name[7] = i + 48;
		fd = open(name, O_RDONLY);
		n = read(fd, tmp, 200);
		close(fd);
		tmp[n] = '\0';
		cmdline = ft_strtrim(tmp, "\a\b\t\n\v\f\r ");
		ft_true_free((void **)&tmp);
		lst = ft_minishell_parsing(cmdline);//////en cours
		//printer le contenu de la lst;
		ft_true_free((void **)&lst);
		printf("\n\n=====================================================\n\n");
	}
	ft_true_free((void **)&name);
	ft_close_stdfds();
	return (0);
}
