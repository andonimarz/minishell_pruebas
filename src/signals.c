/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:45:14 by amarzana          #+#    #+#             */
/*   Updated: 2022/10/07 12:19:47 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <signals.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

void	signal_handler(int num)
{
	if (num == SIGINT)
		printf("CTRL + C = SIGINT ^C\n");
	if (num == SIGQUIT)
		printf ("CTRL + Ç = SIGQUIT ^\\Quit: 3\n");
	printf ("función para salir haciendo frees etc. besitos xd\n");
	exit(0);
}

void	ft_signals(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
}

//	Si en algún caso queremos ignorar las señales hay que usar SIG_IGN 
//	signal(SIGQUIT, SIG_IGN);

//	Ejemplo usando rl
/* 	if (SIGINT == num)
	{
		printf("\n");
		rl_replace_line("", 1);
		rl_redisplay();
	}
*/

//
//rl_on_new_line
//Tell the update functions that we have moved onto a new 
//(empty) line, usually after outputting a newline. 
//With ctr-d it returns -1

//rl_replace_line
//Replace the contents of rl_line_buffer with text. The point 
//and mark are preserved, if possible. If clear_undo is non-zero,
//the undo list associated with the current line is cleared.

//rl_redisplay
//Change what’s displayed on the screen to reflect the current 
//contents of rl_line_buffer. 


//using sig_ign like signal(SIGINT, SIG_IGN); will cause the 
//program to ignore Signal.
