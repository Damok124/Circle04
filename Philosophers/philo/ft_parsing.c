/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 08:01:28 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/23 18:26:28 by zharzi           ###   ########.fr       */
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

//en principe c'est ok, mais il faut gérer les ' " maintenant

typedef struct s_layers {
	char	*src;
	char	*src_trans;
	char	*clone;
	char	*clone_trans;
	int		src_len;
	int		clone_len;
}			t_layers;

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

////////////////////////////////////////////////////////

void	ft_destroy_layers(t_layers **strs)
{
	//(*strs)->src = NULL;//tofree
	(*strs)->clone = NULL;//tofree
	//(*strs)->src_trans = NULL;//tofree
	(*strs)->clone_trans = NULL;//tofree
	//*strs = NULL;
}

void	ft_layers_visualizer(t_layers *strs)
{
	printf(">src         :%s\n>", strs->src);
	printf("src_trans   :%s\n>", strs->src_trans);
	printf("clone       :%s\n>", strs->clone);
	printf("clone_trans :%s\n>", strs->clone_trans);
	printf("src_len     :%d\n>", strs->src_len);
	printf("clone_len   :%d\n", strs->clone_len);
}

int	ft_isspace(int c)
{
	if (c > 9 && c < 16 || c == 32)
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

int	ft_is_valid_var_env(char *str, int i)
{
	if (str && str[i] && str[i + 1])
	{
		if (str && str[i] == '$' && ft_isprint(str[i + 1]))
//			if (ft_translate_or_not(str, i))
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
	ft_strlcpy(tmp, strs->src + i, j);
	val = getenv(tmp);
	return (val);
}
/*
char	*ft_get_var_env(t_layers *strs, int i, int *alias_len)
{
	char	*var_env;
	int		j;

	j = 0;
	var_env = NULL;
	if (str && str[i + j] == '$')
	{
		i++;
		while (str[i + j] && ft_isalnum(str[i + j]))
			j++;
		str[i + j] = '\0';
		var_env = getenv(str + i);
		*alias_len = ft_strlen(str + i + 1);
	}
	return (var_env);
}
*/
/*
char	*ft_setup_newstr(t_layers *strs, char *var_env, int alias_len)
{
	int		var_len;
	//int		total_len;
	char	*newstr;

	var_len = ft_strlen(var_env);
	strs->clone_len = strs->src_len - alias_len + var_len;
	newstr = (char *)malloc(sizeof(char) * (strs->clone_len + 1));
	if (!newstr)
		return (NULL);
	newstr[strs->clone_len] = '\0';
	return (newstr);
}
*/
/*
char	*ft_replace_alias(char *src, int i, char *var_env, char *dest)
{
	int	j;
	int	k;

	j = -1;
	k = -1;
	while (++j < i && dest && src && dest[j] && src[j])
		dest[j] = src[j];
	i ++;
	while (src && src[i] && ft_isalnum(src[i]))
		i++;
	while (var_env && var_env[++k])
		dest[j++] = var_env[k];
	while (src && src[i])
		dest[j++] = src[i++];
	return (dest);
}
*/
///je dois transformer la chaine pour inclure les var_env

char	**ft_get_parts(const char *src, int len, int i)
{
	char	**parts;
	char	*first;
	char	*middle;
	char	*last;
	int		j;

	j = 0;
	while (src && strs->src[i + j] \
		&& ft_isalnum(strs->src[i + j]))
		j++;
	parts = (char **)malloc(sizeof(char *) * 4);
	first = (char *)malloc(sizeof(char) * (i + 1));
	middle = (char *)malloc(sizeof(char) * j);
	last = (char *)malloc(sizeof(char) * (len - i) + 1);
	if (!parts || !first || !middle || !last)
		return (NULL);
	ft_strlcpy(first, src, i);
	ft_strlcpy(last, src + i, len - i);
	parts[0] = first;
	parts[1] = middle;
	parts[2] = last;
	parts[3] = NULL;
	return (parts);
}

void	ft_var_env_to_layers(t_layers *strs, char *val, int i)
{
	char	**parts;

	parts = ft_get_parts(strs->src, strs->src_trans, i);
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
			ft_var_env_to_layers(strs, val, i);
			i = 0;
		}
		else
			i++;
	}
}

/*
char	*ft_translate_vars_env(char *str)
{
	int		i;
	char	*var_env;
	char	*newstr;
	int		alias_len;

	i = 0;
	alias_len = 0;
	var_env = NULL;
	newstr = NULL;
	while (str && str[i])
	{
		if (ft_is_valid_var_env(str, i))
		{
			var_env = ft_get_var_env(str, i, &alias_len);
			newstr = ft_setup_newstr(str, var_env, alias_len);
			str = ft_replace_alias(str, i, var_env, newstr);
			i += ft_strlen(var_env);
		}
		else
			i++;
	}
	return (str);
}
*/
/*
int	ft_check_if_vars_env(char *str)
{
	int		i;

	i = 0;
	if (str && str[i])
	{
		while (str[i] && !ft_is_valid_var_env(str, i))
			i++;
		if (str[i] == '\0')
			return (0);
	}
	return (1);
}
*/
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
	if (big && little && big_len >= little_len)
	{
		while (big[i])
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
	}
	return (total);///////////a verifier
}

void	ft_remove_symbol_var_env(t_layers *strs, int i)////////a verifier
{
	while (strs->src && strs->src[i] && ft_isspace(strs->src[i]))
		i++;
	while (strs->src && strs->src[i] && !ft_strchr("<>|$", strs->src_trans[i]) && !ft_isspace(strs->src[i]))
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
		strs->src_trans = '0';
}

void	ft_disable_var_env(t_layers *strs)//////a verifier
{
	char	*tmp;
	int		heredocs;
	int		i;
	int		j;

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
	//trouver davantage de cas d'erreurs
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
		ft_renew_with_vars_env(strs);/////////////
	}
}

void ft_minishell_parsing(t_layers *strs)
{
	ft_layers_visualizer(strs);
	ft_translate_all(strs);
	ft_layers_visualizer(strs);

}

void	ft_layers_init(t_layers *strs, char *cmdline)
{
	strs->src = ft_strdup(cmdline);
	strs->src_len = ft_strlen(strs->src);
	strs->clone = ft_strdup(strs->src);
	strs->clone_len = strs->src_len;
	strs->src_trans = ft_strdup(strs->src);
	strs->src_trans = (char *)ft_memset(strs->src_trans, '0', strs->src_len);
	strs->clone_trans = ft_strdup(strs->clone);
	strs->clone_trans = \
		(char *)ft_memset(strs->clone_trans, '0', strs->src_len);
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
	if (n)
	{
		cmdline = ft_strtrim(tmp, "\a\b\t\n\v\f\r");
		free(tmp);
		ft_layers_init(&strs, cmdline);
		ft_minishell_parsing(&strs);
	}
	close(fd);
	return (0);
}
