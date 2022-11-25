/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 08:01:28 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/25 18:41:07 by zharzi           ###   ########.fr       */
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

typedef struct s_layers {
	char	*src;
	char	*src_trans;
	int		src_len;
}			t_layers;

typedef struct s_sections {
	char	*first;
	char	*mid;
	char	*new_mid;
	char	*last;
	int		*cut;
}			t_sections;

typedef struct s_blocks {
	char	**src;
	char	**src_trans;
}			t_blocks;

typedef struct s_size {
	int	second;
	int	third;
}		t_size;

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

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	ssize_t	i;
	ssize_t	j;

	i = -1;
	j = ft_strlen(s1);
	if (s1)
	{
		while (ft_strchr(set, s1[++i]))
			;
		while (ft_strrchr(set, s1[--j]) && j >= 0)
			;
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

////////////////////////////////////////////////////////

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

int	ft_isspace(int c)
{
	if ((c > 9 && c < 16) || c == 32)
		return (1);
	else
		return (0);
}

int	ft_is_heredoc(char *str)
{
	if (str && str[0] && str[1])
	{
		if (str[0] == '<' && str[1] == '<')
			return (1);
	}
	return (0);
}

int	ft_is_infile(char *str)
{
	if (str && str[0] && str[1])
	{
		if (str[0] == '<' && str[1] != '<')
			return (1);
	}
	return (0);
}

int	ft_is_outfile(char *str)
{
	if (str && str[0])
	{
		if (str[0] == '>')
			return (1);
	}
	return (0);
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

void	ft_var_env_focus(t_layers *strs, int i, int *sq, int *dq)
{
	if ((i == 0 && strs->src[i] == '$') || (i != (strs->src_len - 1) \
		&& strs->src[i] == '$' && (*sq % 2) == 0 && (*dq % 2) == 0))
	{
		if (i > 0 && strs->src_trans[i - 1] && strs->src_trans[i - 1] == '$' \
			&& strs->src[i] == '$')
			strs->src_trans[i - 1] = '0';
		strs->src_trans[i] = strs->src[i];
	}
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
	if (tmp[i - 2] && ft_strchr("<>", tmp[i - 2]))
		if (ft_strchr("\t\n \"\'#&*./|~<>", strs->src[i - 1]) \
			|| (!ft_isprint(strs->src[i - 1])))
			return (0);
	if (tmp[i - 1] && ft_strchr("<>", tmp[i - 1]))
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
		ft_var_env_focus(strs, i, &sq, &dq);
		i++;
	}
	if (ft_strnstr(strs->src_trans, "<<", strs->src_len))
		ft_disable_var_env(strs);
	return (1);
}

void	ft_translate_all(t_layers *strs)
{
	if (ft_check_quotes(strs) && ft_check_angl_brackets(strs) \
		&& ft_check_pipes(strs))
	{
		ft_check_var_env(strs);
		if (ft_strchr(strs->src_trans, '$'))
			ft_renew_with_vars_env(strs);
	}
}

////////////////////////////////////////////////////////////////////////

void	ft_show_duo_strs(char **strs1, char **strs2)
{
	int	i;

	i = 0;
	printf(">src         :");
	while (strs1 && strs1[i])
	{
		printf("%s", strs1[i]);
		printf("%%");
		i++;
	}
	i = 0;
	printf("\n");
	printf(">src_trans   :");
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

void	ft_strstrim_to_blocks(char **src, char **trs, char*set)
{
	char	*tmptmp;
	int		i;
	int		j;

	i = -1;
	j = 0;
	tmptmp = NULL;
	while (src && src[++i])
	{
		tmptmp = ft_strtrim(src[i], set);
		if (tmptmp && ft_strncmp(src[i], tmptmp, ft_strlen(src[i])))
		{
			while (ft_strchr(set, src[i][j]))
				j++;
			tmptmp = ft_strdup(trs[i] + j);
			j = ft_strlen(tmptmp);/////probleme, refaire fonction sans doute
			while (j >= 0 && ft_strrchr(set, src[i][--j]))
			{
				printf("src[%d][%d]:[%c]\n", i, j, src[i][j]);
				printf("src[%d]:%s%%\n", i, src[i]);
				printf("tmptmp:%s\n", tmptmp);
				tmptmp[j] = '\0';
				printf("tmptmp:%s\n", tmptmp);
			}
			trs[i] = ft_strdup(tmptmp);
			tmptmp = ft_strtrim(src[i], set);
			src[i] = tmptmp;
			j = 0;
		}
		tmptmp = NULL;
	}
}

t_blocks	*ft_layers_pipe_split(t_layers *strs)
{
	t_blocks	*blocks;

	blocks = (t_blocks *)malloc(sizeof(t_blocks) * 1);
	blocks->src_trans = ft_split(strs->src_trans, '|');
	blocks->src = ft_parallel_split(blocks->src_trans, strs->src);
	ft_strstrim_to_blocks(blocks->src, blocks->src_trans, "\a\b\t\n\v\f\r ");
	printf("GOOD?\n");
	ft_show_duo_strs(blocks->src, blocks->src_trans);
	return (blocks);
}

void ft_minishell_parsing(t_layers *strs)
{
	t_blocks *blocks;

	ft_layers_visualizer(strs);
	ft_translate_all(strs);
	ft_layers_visualizer(strs);
	blocks = ft_layers_pipe_split(strs);///////////////
	(void)blocks;
}

void	ft_layers_init(t_layers *strs, char *cmdline)
{
	strs->src = ft_strdup(cmdline);
	strs->src_len = ft_strlen(strs->src);
	strs->src_trans = ft_strdup(strs->src);
	strs->src_trans = (char *)ft_memset(strs->src_trans, '0', strs->src_len);
}

int	main(void)
{
	t_layers	strs;
	char	*cmdline;
	char	*tmp;
	int		fd;
	int		n;

	tmp = (char *)malloc(sizeof(char) * (150 + 1));
	fd = open("cmdline", O_RDONLY);
	n = read(fd, tmp, 150);
	tmp[n] = '\0';
	if (n)
	{
		printf("%s\n", tmp);
		cmdline = ft_strtrim(tmp, "\a\b\t\n\v\f\r ");
		free(tmp);
		ft_layers_init(&strs, cmdline);
		ft_minishell_parsing(&strs);
	}
	close(fd);
	return (0);
}

/*
cat<lol>filex|























*/
