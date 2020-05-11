# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/11 06:50:50 by user42            #+#    #+#              #
#    Updated: 2020/05/11 06:50:54 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global			ft_strcmp
section			.text
ft_strcmp :
            mov         rax, -1                 ;compteur a -1

start:
            
            inc         rax                     ;incrementation
            cmp         byte[rdi + rax], 0      ;if rdi est a 0 c'est quil est peut etre egal donc on verif apres
            je          returnegal
            mov			cl, byte [rdi + rax]    ;on met rdi dans cl
            cmp         cl, byte[rsi + rax]     ;on compare avec str2
            jl          returninf               ;if c'est inferieur on va ds la fonction returninf
            cmp         cl, byte[rsi + rax]     ;pareil
            jg          returnsup               ;si c'est > on va dans lautre fonction       
            cmp         cl, byte[rsi + rax]     ; si c'est = on recommence la boucle
            je          start                   ; jump a la fonction start 
            

returnsup:
            mov    rax, 1
            ret

returninf:  
            cmp     byte[rsi + rax], 0          ;secu au cas ou les deux chaine sont vide
            je      returnegall
            mov     rax, -1
            ret
returnegal:
            cmp     byte [rdi + rax], 0         ;secu au cas ou sa commence pareil mais que rdi na plus de lettre
            je     returninf
            mov     rax, 0
            ret
returnegall:       
            mov     rax, 0
            ret
