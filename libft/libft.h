/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 15:43:18 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/31 15:29:03 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_atoi(const char *nptr);
int				ft_printf(char const *format, ...);
int				foud_type(char c, va_list args);
int				print_string(char *str);
int				print_numbers(int n);
int				print_nbr_hexadecimal(unsigned int n, char c);
int				ft_putnbr_base(unsigned int nbr, char *base);
int				print_long_hexadecimal(unsigned long n, char c);
int				ft_putlong_base(unsigned long nbr, char *base);
int				print_unsigned_n(unsigned int n);
int				print_pointer(unsigned long n);
int				print_char(char c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_printf_error(char const *format, ...);
int				foud_type_error(char c, va_list args);
int				print_string_error(char *str);
int				print_numbers_error(int n);
int				print_nbr_hexadecimal_error(unsigned int n, char c);
int				ft_putnbr_base_error(unsigned int nbr, char *base);
int				print_long_hexadecimal_error(unsigned long n, char c);
int				ft_putlong_base_error(unsigned long nbr, char *base);
int				print_unsigned_n_error(unsigned int n);
int				print_pointer_error(unsigned long n);
int				print_char_error(char c);

unsigned int	ft_lstsize(t_list *lst);

void			ft_bzero(void *s, size_t n);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));	
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));

void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);

size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);

char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strdup(const char *src);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char			**ft_split(char const *s, char c);

t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

void	*gnl_clean_stash(char *stash, char *line);
char	*gnl_memory_free(char *new, char **stash);
char	*gnl_get_lines(char	**stash, size_t len_l);
char	*gnl_read_buff(int fd, char *rest);
char	*get_next_line(int fd);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strchr(char *s, int c);
char	*gnl_substr(char const *s, unsigned int start, size_t len);

size_t	gnl_strlcpy(char *dst, const char *src, size_t size);
size_t	gnl_strlen(const char *s);

#endif
