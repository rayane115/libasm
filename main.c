/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rqouchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 04:45:38 by rqouchic          #+#    #+#             */
/*   Updated: 2020/05/14 04:47:46 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

int		ft_strlen(char *s);
ssize_t	ft_write(int fd, const void *buf, size_t nbyte);
ssize_t	ft_read(int fd, void *buf, size_t nbyte);
char	*ft_strcpy( char *destination, const char *source );
int 	ft_strcmp(const char *first, const char *second );
char	*ft_strdup(const char *source );

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)s)[i] = 0;
		i++;
	}
}

void	size_len(void)
{
	char *str;
	char *str2;

	str2 = "dalya";
	printf("-- FT_STRLEN -- \n");
	str = "dalya";
	printf("   strlen: %d\n", (int)strlen(str2));
	printf("   ft_strlen: %d\n", (int)ft_strlen(str2));
	printf("----------------------------------------\n");
}

void	ecriture(void)
{
	int ret;
	int ft_ret;
	char *str;

	printf("-- FT_WRITE --");
	str = "Bonsoir a toute et a tous";
	printf("string : '%s'\n", str);
	ret = write(1, str, ft_strlen(str));
	printf(":    write returned : %d\n", ret);
	ft_ret = ft_write(1, str, ft_strlen(str));
	printf(": ft_write returned : %d\n\n", ft_ret);
	str = "";
	printf("string : '%s'\n", str);
	ret = write(1, str, ft_strlen(str));
	printf(":    write returned : %d\n", ret);
	ft_ret = ft_write(1, str, ft_strlen(str));
	printf(": ft_write returned : %d\n\n", ft_ret);
	printf("--> Error with bad fd\n");
	str = "Ceci est un test";
	printf("string : '%s'\n", str);
	errno = 0;
	ret = write(489, str, ft_strlen(str));
	printf(":    write returned : %d : %s -> %d\n", ret, strerror(errno), errno);
	errno = 0;
	ft_ret = ft_write(489, str, ft_strlen(str));
	printf(": ft_write returned : %d : %s -> %d\n\n", ft_ret, strerror(errno), errno);
	printf("----------------------------------------\n");
}

void	lecture(void)
{
	int			fd;
	int			ft_fd;
	int			ret;
	int			ft_ret;
	char		buffer[30];
	char		ft_buffer[30];
	int			value;
	int			i;

	fd = open("ft_strlen.txt", O_RDONLY);
	ft_fd = open("ft_strlen.txt", O_RDONLY);
	printf(" -- FT_READ --\n");
	value = 15;
	i = 0;
	while (i < 3)
	{
		ft_bzero(buffer, 30);
		ft_bzero(ft_buffer, 30);
		ret = read(fd, buffer, value);
		ft_ret = ft_read(ft_fd, ft_buffer, value);
		printf("   read: '%s' -> %d\n", buffer, ret);
		printf("ft_read: '%s' -> %d\n\n", ft_buffer, ft_ret);
		value += 5;
		i++;
	}
	printf("---> error bad fd test\n");
	ft_bzero(buffer, 30);
	ft_bzero(ft_buffer, 30);
	errno = 0;
	ret = read(-1, buffer, 15);
	printf("   read: errno: %d %s -> %d\n", errno, strerror(errno), errno);
	printf("buffer: '%s'\n", buffer);
	errno = 0;
	ft_ret = ft_read(-1, ft_buffer, 15);
	printf("ft_read: errno: %d %s -> %d\n", errno, strerror(errno), errno);
	printf("buffer: '%s'\n\n", ft_buffer);
	printf("---> error bad buffer test\n");
	ft_bzero(buffer, 30);
	ft_bzero(ft_buffer, 30);
	errno = 0;
	ret = read(fd, 250, 15);
	printf("   read: errno: %d %s -> %d\n", errno, strerror(errno), errno);
	printf("buffer: '%s'\n", buffer);
	errno = 0;
	ft_ret = ft_read(ft_fd, 250, 15);
	printf("ft_read: errno: %d %s -> %d\n", errno, strerror(errno), errno);
	printf("buffer: '%s'\n\n", ft_buffer);
	close(fd);
	close(ft_fd);
	printf("----------------------------------------\n");
}

void	string_cpy(void)
{
	char *str1;
	char *str2;
	char dest[8];
	char *src;

	src = "😀";
	ft_bzero(dest, 8);
	ft_bzero(dest, 8);
	printf("-- FT_STRCPY --\n");
	str1 = strdup(dest);
	str2 = strdup(dest);
	str1 = strcpy(str1, src);
	str2 = ft_strcpy(str2, src);
	printf("   strcpy: %s\n", str1);
	printf("ft_strcpy: %s\n", str2);
	printf("----------------------------------------\n");
}

void	diff_string(void)
{
	char		*s1;
	char		*s2;
	int			ret;

	printf("-- FT_STRCMP --");
	printf("s1 -> '%s' : s2 -> '%s'\n", "Bonsoir", "Bonsoir");
	printf("   strcmp: %d\n", strcmp("Bonsoir", "Bonsoir"));
	printf("ft_strcmp: %d\n\n", ft_strcmp("Bonsoir", "Bonsoir"));
	printf("s1 -> '%s' : s2 -> '%s'\n", "Z", "A");
	printf("   strcmp: %d\n", strcmp("Z", "A"));
	printf("ft_strcmp: %d\n\n", ft_strcmp("Z", "A"));
	printf("s1 -> '%s' : s2 -> '%s'\n", "A", "Z");
	printf("   strcmp: %d\n", strcmp("A", "Z"));
	printf("ft_strcmp: %d\n\n", ft_strcmp("A", "Z"));
	printf("s1 -> '%s' : s2 -> '%s'\n", "Bonjoir", "Bonsoir");
	printf("   strcmp: %d\n", strcmp("Bonjoir", "Bonsoir"));
	printf("ft_strcmp: %d\n\n", ft_strcmp("Bonjoir", "Bonsoir"));
	printf("s1 -> '%s' : s2 -> '%s'\n", "Bonso", "Bonsoir");
	printf("   strcmp: %d\n", strcmp("Bonso", "Bonsoir"));
	printf("ft_strcmp: %d\n\n", ft_strcmp("Bonso", "Bonsoir"));
	printf("s1 -> '%s' : s2 -> '%s'\n", "Bonsoir", "Bonso");
	printf("   strcmp: %d\n", strcmp("Bonsoir", "Bonso"));
	printf("ft_strcmp: %d\n\n", ft_strcmp("Bonsoir", "Bonso"));
	printf("s1 -> '%s' : s2 -> '%s'\n", "", "Bonsoir");
	printf("   strcmp: %d\n", strcmp("", "Bonsoir"));
	printf("ft_strcmp: %d\n\n", ft_strcmp("", "Bonsoir"));
	printf("s1 -> '%s' : s2 -> '%s'\n", "Bonsoir", "");
	printf("   strcmp: %d\n", strcmp("Bonsoir", ""));
	printf("ft_strcmp: %d\n\n", ft_strcmp("Bonsoir", ""));
	printf("s1 -> '%s' : s2 -> '%s'\n", "", "");
	printf("   strcmp: %d\n", strcmp("", ""));
	printf("ft_strcmp: %d\n\n", ft_strcmp("", ""));
	ret = strcmp("bonjour", "bonjour");
	printf("ret    strcmp : %d\n", ret);
	ret = ft_strcmp("bonjour", "bonjour");
	printf("ret ft_strcmp : %d\n", ret);
	ret = strcmp("bonj", "bonjour");
	printf("ret    strcmp : %d\n", ret);
	ret = ft_strcmp("bonj", "bonjour");
	printf("ret ft_strcmp : %d\n", ret);
	ret = strcmp("bonjour", "bonj");
	printf("ret    strcmp : %d\n", ret);
	ret = ft_strcmp("bonjour", "bonj");
	printf("ret ft_strcmp : %d\n", ret);
	ret = strcmp("bonjkur", "bonjour");
	printf("ret    strcmp : %d\n", ret);
	ret = ft_strcmp("bonjkur", "bonjour");
	printf("ret ft_strcmp : %d\n", ret);
	ret = strcmp("", "");
	printf("ret    strcmp : %d\n", ret);
	ret = ft_strcmp("", "");
	printf("ret ft_strcmp : %d\n", ret);
	ret = strcmp("\xff\xff", "\xff");
	printf("ret     strcmp : %d\n", ret);
	ret = ft_strcmp("\xff\xff", "\xff");
	printf("ret  ft_strcmp : %d\n", ret);
	ret = strcmp("\xff\xfe", "\xff");
	printf("ret     strcmp : %d\n", ret);
	ret = ft_strcmp("\xff\xfe", "\xff");
	printf("ret  ft_strcmp : %d\n", ret);
	ret = strcmp("\xfe\xff", "\xfe");
	printf("ret     strcmp : %d\n", ret);
	ret = ft_strcmp("\xfe\xff", "\xfe");
	printf("ret  ft_strcmp : %d\n", ret);
	printf("----------------------------------------\n");
}

void	string_dup(void)
{
	char *text;
	char *str;
	char *ft_str;

	str = strdup(text);
	ft_str = ft_strdup(text);
	printf("-- FT_STRDUP --\n");
	text = "Bonsoir a toute et a tous";
	printf("original text : '%s'\n", text);
	printf("   strdup: '%s'\nft_strdup: '%s'\n\n", str, ft_str);
	free(str);
	free(ft_str);
	text = "";
	printf("original text : '%s'\n", text);
	str = strdup(text);
	ft_str = ft_strdup(text);
	printf("   strdup: '%s'\nft_strdup: '%s'\n\n", str, ft_str);
	free(str);
	free(ft_str);
	text = "Deuxieme test ca doit fonctionner :P";
	printf("original text : '%s'\n", text);
	str = strdup(text);
	ft_str = ft_strdup(text);
	printf("   strdup: '%s'\nft_strdup: '%s'\n\n", str, ft_str);
	free(str);
	free(ft_str);
	printf("--- FIN DU TEST ---\n");
}

int		main(int argc, char **argv)
{
	size_len();
	ecriture();
	lecture();
	string_cpy();
	diff_string();
	string_dup();
	return (0);
}