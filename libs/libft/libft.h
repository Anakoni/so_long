/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:04:40 by arthur            #+#    #+#             */
/*   Updated: 2024/11/28 15:05:58 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		ft_atoi(char *str);
char	*ft_itoa(int n);
void	*calloc(size_t nmemb, size_t size);
void	*ft_bzero(void *s, size_t n);
int		ft_isalnum(unsigned char c);
int		ft_isalpha(unsigned char c);
int		ft_isascii(unsigned char c);
int		ft_isdigit(unsigned char c);
int		ft_isprint(unsigned char c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, char c);
char	*ft_strdup(char *src);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
int		ft_strlcpy(char *dest, const char *src, size_t n);
int		ft_strlen(char *str);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	ft_tolower(char c);
char	ft_toupper(char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strtrim(char const *s1, char const *set);
char	*get_next_line(int fd);
int		gnl_strchr(const char *s, char c);
size_t	gnl_strlen(const char *str);
size_t	gnl_strlcpy(char *dest, const char *src, size_t n);
size_t	gnl_strlcat(char *dest, const char *src, size_t n);
char	*gnl_strjoin(char const *s1, char const *s2);
int		ft_printf(const char *tst, ...);
int		ft_printchar(char c);
int		ft_printstr(char *s);
int		ft_printptr(unsigned long long ptr);
int		ft_printnbr(int nb);
int		ft_printunbr(unsigned int nb);
int		ft_printhex(unsigned int num, const char format);

#endif