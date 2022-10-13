/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:09:24 by caquinta          #+#    #+#             */
/*   Updated: 2022/10/13 17:08:08 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "environment.h"
#include "expansor.h"
#include "fill_tokens.h"
#include "utils.h"
#include "utils2.h"
#include "builtins.h"
#include "signals.h"
#include <fcntl.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>

int	count_char_index(char *str, char a)
{
	int	x;

	str++;
	x = 1;
	while (*str)
	{
		if (*str == a)
			return (x);
		str++;
		x++;
	}
	return (-1);
}
int	count_word_index(char *str)
{
	int	x;
	int	i;

	i = 0;
	x = 0;
	while (*str)
	{
		if ((*str == '"' || *str == '\''))
		{
			if (!second_char_exists(str, *str))
			{
				printf("error\n");
				return (-1);
			}
			i = count_char_index(str, *str);
			x += i + 1;
			str += i + 1;
		}
		else if (*str == '|' || *str == '<' || *str == '>' || *str == ' ')
			return (x);
		else
		{
			x++;
			str++;
		}
	}
	return (x);
}

int	count_tokens(char *str)
{
	int	num_token;
	int	index;

	index = 0;
	num_token = 0;
	while (*str)
	{
		if (*str == '|' || *str == '<' || *str == '>')
			num_token++;
		else if (*str != ' ')
		{
			index = count_word_index(str);
			if (index < 0)
				return (0);
			str += index - 1;
			num_token++;
		}
		str++;
	}
	return (num_token);
}

int	main(int argc, char *argv[], char **envp)
{
	char	*str;
	int		x;
	char	*aux;
	char	**tokens;
	//char	*i;
	char	**env2;

	argc = 0;
	argv = NULL;
	env2 = env_copy(envp);
	while (1)
	{
		ft_signals();
		aux = ft_strjoin(getenv("USER"), "@minishell $ ");
		str = readline(aux);
		if (str == NULL)
		{
			printf("exit\n");
			printf("/////CTRL + D = está en el bucle principal\n");
			printf ("/////función para salir haciendo frees etc. besitos xd\n");
			exit(0);
		}
		add_history(str);
		if (!str)
			continue ;
		free(aux);
		aux = expansor(str);
		x = count_tokens(aux);
		tokens = fill_tokens(aux, x);
		if (!x)
			continue ;
		free(aux);
		x = 0;
		/* while (tokens[x])
		{
			printf("el token es %s\n", tokens[x]);
			i = erase_quotes(tokens[x]);
			printf("el array es %s\n", i);
			free(i);
			x++;
		} */
		//ft_pwd();
		//ft_export("olajijixd=", "probando", &env2);
		//ft_chdir("..", env2);
		//ft_pwd();
		//ft_env(env2);
		//ft_unset("TERMdrhd=", &env2);
		//ft_env(env2);
		//ft_echo(tokens);
	}
	/*x = 0;
	while (tokens[x])
	{
		printf("token %d es: %s\n",x, tokens[x]);
		x++;
	} */
	free_d_array(tokens);
	//free(str);
	return (0);
}
