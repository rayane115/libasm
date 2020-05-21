# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rqouchic <rqouchic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/11 06:49:39 by user42            #+#    #+#              #
#    Updated: 2020/05/14 04:45:25 by rqouchic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global    ft_read
section   .text
extern     __errno_location

ft_read:    
            mov             rax, 0 
            syscall
            cmp				rax, 0
            jl  			error
            ret
error:
			neg             rax
            mov             rdi, rax
            call            __errno_location
            mov             [rax], rdi
            mov             rax, -1
            ret