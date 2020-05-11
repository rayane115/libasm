# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/11 06:49:39 by user42            #+#    #+#              #
#    Updated: 2020/05/11 06:49:52 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global    ft_read
section   .text

ft_read:    
            mov             rax, 0 
            syscall
            cmp				rax, 0
            jl  			error
            ret
error:
			mov			 	rax, -1
			ret