#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int		ft_strlen(char *s);
ssize_t	ft_write(int fd, const void *buf, size_t nbyte);
ssize_t	ft_read(int fd, void *buf, size_t nbyte);
char 	*ft_strcpy( char * destination, const char * source );
int 	ft_strcmp( const char * first, const char * second );
char 	*ft_strdup( const char * source );

void	size_len()
{
	char *str;
	char *str2 = "dalya";
	printf("-- FT_STRLEN -- \n");
	str = "dalya";
	printf("   strlen: %d\n", (int)strlen(str2));
	printf("   ft_strlen: %d\n", (int)ft_strlen(str2));
	printf("----------------------------------------\n");
}

void	ecriture()
{
	char *str;
	char *str2;
	str = "Salut comment tu vas";
	str2 = "Salut comment tu vas";
	printf("-- FT_WRITE -- \n");
	printf(" =    write: %zd\n", write(1, str, strlen(str2)));
	printf(" = ft_write: %zd\n", ft_write(1, str2, strlen(str2)));
	printf("----------------------------------------\n");
}

void	lecture()
{
	int fd = open("ft_strlen.txt", O_RDONLY);
	int fd1 = open("ft_strlen.txt", O_RDONLY);
	char	buffer[100];
	char	buffer1[100];
	int			ret;
	int			ret1;
	bzero(buffer, 100);
	bzero(buffer1,100);
	ret = read(fd, buffer, 100);
	ret1 = ft_read(fd1, buffer1, 100);	
	printf("--FONCTION READ--\n");
	printf("read,  ret : %d,  \nbuffer : %s\n", ret, buffer);
	printf("ft_read, ret1 : %d, \nbuffer : %s\n", ret1, buffer1);
	printf("----------------------------------------\n");
}

void	string_cpy()
{
	char *str1;
	char *str2;
	char dest[8];
	char *src;

	src = "😀";
	bzero(dest, 8);
	bzero(dest,8);
	printf("-- FT_STRCPY --\n");
	str1 = strdup(dest);
	str2 = strdup(dest);	
	str1 = strcpy(str1, src);
	str2 = ft_strcpy(str2, src);
	printf("   strcpy: %s\n", str1);
	printf("ft_strcpy: %s\n", str2);
	printf("----------------------------------------\n");
}

void	diff_string()
{
	char		*s1;
	char		*s2;

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

	int ret = strcmp("bonjour", "bonjour");
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
	ret = strcmp("\xff", "\xff\xfe");
	printf("ret    strcmp : %d\n", ret);
	ret = ft_strcmp("\xff", "\xff\xfe");
	printf("ret ft_strcmp : %d\n", ret);
	printf("----------------------------------------\n");
}

void	string_dup()
{
	printf("-- FT_STRDUP --\n");

	char *text;
	text = "Bonsoir a toute et a tous";
	printf("original text : '%s'\n", text);
	char *str = strdup(text);
	char *ft_str = ft_strdup(text);
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
