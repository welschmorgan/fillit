/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmino.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 21:49:52 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/25 22:53:29 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tmino.h"

/*static char	*g_tmino_shapes[BLOCK_COUNT][4] = {
	{
		"##  ",
		"##  ",
		"    ",
		"    ",
	},
	{
		" #  ",
		" #  ",
		"##  ",
		"    ",
	},
	{
		"#   ",
		"#   ",
		"##  ",
		"    ",
	},
	{
		" ## ",
		"##  ",
		"    ",
		"    ",
	},
	{
		"##  ",
		" ## ",
		"    ",
		"    ",
	},
	{
		"#   ",
		"#   ",
		"#   ",
		"#   ",
	},
	{
		"### ",
		" #  ",
		"    ",
	},
};

char


*/

void				ft_tmino_parser_init(t_tmino_parser *t,
										char const *fname,
										char const *buf,
										unsigned short n)
{
	t->fname = fname;
	t->buf = buf;
	t->pbuf = t->buf;
	t->nempty = 0;
	t->nfilled = 0;
	t->line = 0;
	t->col = 0;
	t->row = 0;
	ft_bzero(&t->obj, sizeof(t_tmino));
}

int					ft_tmino_parser_error(t_tmino_parser *p,
										  int code,
										  char const *msg)
{
	p->code = code;
	ft_strncpy(p->error, msg, TMINO_ERROR_SIZE);
	return (p->code);
}
