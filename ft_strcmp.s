# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rqouchic <rqouchic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/11 06:50:50 by user42            #+#    #+#              #
#    Updated: 2020/05/14 04:57:06 by rqouchic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global			ft_strcmp
section			.text
ft_strcmp :
            mov         rax, -1                 ;compteur a -1

start:
            
            inc         rax                     ;incrementation
            mov			cl, byte [rdi + rax]    ;on met rdi dans cl
            cmp         cl, 0      ;if rdi est a 0 c'est quil est peut etre egal ou fini donc on verif apres
            je          returninf
            cmp			byte[rsi + rax], 0 
		    je			returnsup
            cmp         cl, byte[rsi + rax]     ;on compare avec str2
            jl          returninf               ;if c'est inferieur on va ds la fonction returninf
            jg          returnsup               ;si c'est > on va dans lautre fonction       
            je          start                   ; jump a la fonction start 
            

returnsup:
            mov    rax, 1
            ret

returninf:  
            cmp     byte[rsi + rax], 0          ;secu au cas ou les deux chaine sont vide
            je      returnegal
            mov     rax, -1
            ret
returnegal:
            mov     rax, 0
            ret

