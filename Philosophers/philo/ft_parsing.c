/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 08:01:28 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/14 14:20:34 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

//en principe c'est ok, mais il faut gérer les ' " maintenant



char	*ft_get_var_env(char *str, int i, int *alias_len)
{
	char	*var_env;
	int		j;

	j = 0;
	var_env = NULL;
	if (str && str[i + j] == '$')
	{
		i++;
		while (str[i + j] && ft_is_alnum(str[i + j]))
			j++;
		str[i + j] = '\0';
		var_env = getenv(str + i);
		*alias_len = ft_strlen(str + i + 1);
	}
	return (var_env);
}

char	*ft_setup_newstr(char *str, int i, char *var_env, int alias_len)
{
	int		len;
	int		var_len;
	int		total_len;
	char	*newstr;

	len = ft_strlen(str);
	var_len = ft_strlen(var_env);
	total_len = len - alias_len + var_len;
	newstr = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!newstr)
		return (NULL);
	return (newstr);
}

char	*ft_replace_alias(char *src, int i, char *var_env, char *dest)
{
	int	j;
	int	k;

	j = -1;
	k = -1;
	while (++j < i && dest && src && dest[j] && src[j])
		dest[j] = src[j];
	i ++;
	while (src && src[i] && ft_is_alnum(src[i]))
		i++;
	while (var_env && var_env[++k])
		dest[j++] = var_env[k];
	while (src && src[i])
		dest[j++] = src[i++];
	return (dest);
}

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
			newstr = ft_setup_newstr(str, i, var_env, alias_len);
			str = ft_replace_alias(str, i, var_env, newstr);
			i += ft_strlen(var_env);
		}
		else
			i++;
	}
}

char	*ft_check_if_var_env(char *str)
{
	char	*result;
	int		i;

	i = 0;
	result = NULL;
	if (str && str[i])
	{
		while (str[i] && !ft_is_var_env(str + i))
			i++;
		if (str[i] == '\0')
			return (str);
		else
			result = ft_translate_vars_env(str);
	}
	return (result);
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
		if (str && str[i] == '$' && ft_is_print(str[i + 1]))
			if (ft_translate_or_not(str, i))
				return (1);
	}
	return (0);
}
