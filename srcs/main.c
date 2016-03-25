/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 21:14:09 by mwelsch           #+#    #+#             */
/*   Updated: 2016/03/25 22:53:30 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>
#include <unistd.h>
#include <fcntl.h>

int		usage()
{
	static char const	*lines[] = {
		"fillit <filename>",
		"	packs tetraminos into the smallest",
		"	square possible.",
		"",
		"filename:",
		"	the name of the file to read",
		"	tetraminos from, 26 max, ill-formatted",
		"	files will be rejected!",
		NULL
	};
	char const			**pline;

	pline = &lines[0];
	while (*pline)
	{
		ft_putendl(*pline);
		pline++;
	}
	return (1);
}

int		parse_file(char const *fname, char *buf, size_t n)
{
	t_tmino_parser	p;

	ft_tmino_parser_init(&p, fname, buf, n)
	while (pbuf < (buf + n))
	{
		if (((row + 1) % 4) && *pbuf != '')
			return (ft_tmino_parser_error(ERR_ILL_FORMAT);
		if (*pbuf == TMINO_FILL_CHAR)
			nfilled++;
		else if (*pbuf == TMINO_EMPTY_CHAR)
			nempty++;
		if (((col + 1) % 4) && *pbuf != '\n')
			return (ft_tmino_parser_error(ERR_MISSING_NL));
		if (*pbuf == '\n')
		{
			col = 0;
			row++;
			line++;
		}
		pbuf++;
	}
	return (0);
}
int		load_file(char const *fname)
{
	int		fd;
	int		nread;
	char	buf[TMINO_FILE_SIZE];
	int		code;

	code = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr(argv[1]);
		ft_putendl(": failed to open file!");
		code = ERR_NOT_FOUND;
	}
	if (!code)
	{
		nread = read(fd, buf, TMINO_FILE_SIZE);
		if (nread <= 0)
		{
			ft_putstr(argv[1]);
			ft_putstr(": read returned ");
			ft_putnbr(nread);
			ft_putendl("");
			code = ERR_;
		}
	}
	if (!code)
	{
		ft_putstr(argv[1]);
		ft_putstr(": ");
		ft_putnbr(nread);
		ft_putendl(" chars read");
		code = parse_file(fname, buf, nread);
	}
	close(fd);
	return (code);
}

int		main(int argc, char *argv[])
{
	if (argc != 2)
		return (usage(argv[0]));
	return (load_file(argv[1]));
}
