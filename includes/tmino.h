/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmino.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 21:29:36 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/25 22:41:49 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		TMINO_H
# define	TMINO_H

# define TMINO_ERROR_SIZE	150
# define TMINO_NAME_SIZE	20
# define TMINO_FILE_SIZE	(26 * (16 + 1))

# define TMINO_EMPTY_CHAR	' '
# define TMINO_FILL_CHAR	'#'

# define ERR_MISSING_NL 4
# define ERR_NOT_FOUND 5
# define ERR_ILL_FORMAT 6

# ifndef NULL
#  define NULL ((void*)0)
# endif

typedef enum		e_tmino_type
{
	BLOCK_SQ,
	BLOCK_LG,
	BLOCK_RG,
	BLOCK_S,
	BLOCK_Z,
	BLOCK_BAR,
	BLOCK_T,
	BLOCK_COUNT
}					t_tmino_type;

typedef struct		s_tmino
{
	t_tmino_type	type;
	char const		name[TMINO_NAME_SIZE];
	char			data[16];
}					t_tmino;

typedef struct		s_tmino_parser
{
	char const		*fname;
	char const		*buf;
	unsigned short	bufsize;
	char const		*pbuf;
	char const		error[TMINO_ERROR_SIZE];
	unsigned char	nempty;
	unsigned char	nfilled;
	unsigned short	line;
	unsigned char	col;
	unsigned char	row;
	t_tmino			obj;
}					t_tmino_parser;

void				ft_tmino_parser_init(t_tmino_parser *t,
										char const *fname,
										char const *buf,
										unsigned short n);
int					ft_tmino_parser_error(int code,
										  char const *msg);

#endif
