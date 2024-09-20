/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:19:57 by jingwu            #+#    #+#             */
/*   Updated: 2024/09/16 10:45:27 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> // for read
# include <stdlib.h> // for free and malloc
# include <stdio.h> // for EOF

#ifndef BUFFER_SIZE  // need to write it like this
# define BUFFER_SIZE	42
# endif

char	*get_next_line(int fd);

# endif
